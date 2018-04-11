/**
 * passwd.c
 *
 * Given a length and SHA-1 password hash, this program will use a brute-force
 * algorithm to recover the password using hash inversions.
 *
 * Compile: mpicc -g -Wall passwd.c -o passwd
 * Run: mpirun --oversubscribe -n 4 ./passwd num-chars hash [valid-chars]
 *
 * Where:
 *   - num-chars is the number of characters in the password
 *   - hash is the SHA-1 password hash (may not be in uppercase...)
 *   - valid-chars tells the program what character set to use (numeric, alpha,
 *     alphanumeric)
 */
 
#include <ctype.h>
#include <mpi.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
 
/* Provides SHA-1 functions: */
#include "sha1.c"
 
/* Defines the alphanumeric character set: */
char *alpha_num = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char *num = "0123456789";
 
char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
/* Pointer to the current valid character set */
char *valid_chars;
 
/* When the password is found, we'll store it here: */
char found_pw[128] = { 0 };
 
/**
 * Generates passwords in order (brute-force) and checks them against a
 * specified target hash.
 * Inputs:
 *  - target - target hash to compare against
 *  - str - initial string. For the first function call, this can be "".
 *  - max_length - maximum length of the password string to generate
 */
 
int counter = 0;
 
/* Get the rank of this process */
int rank;
     
/* Total number of processes in this MPI communicator */
int comm_sz;
 
bool crack(char *target, char *str, int max_length) {
    int curr_len = strlen(str);
    char *strcp = calloc(max_length + 1, sizeof(char));
    strcpy(strcp, str);
 
    /* We'll copy the current string and then add the next character to it. So
     * if we start with 'a', then we'll append 'aa', and so on. */
    int i;
 
    for (i = 0; i < strlen(valid_chars); ++i) {
        int flags=0;
        counter++;
 
        MPI_Iprobe(MPI_ANY_SOURCE,  
                          MPI_ANY_TAG,
                          MPI_COMM_WORLD,
                          &flags,       
                          MPI_STATUS_IGNORE);
 
        if (flags == 1) {
            return true;
        }
 
        strcp[curr_len] = valid_chars[i];
        if (curr_len + 1 < max_length) {
            bool found = crack(target, strcp, max_length);
            if (found == true) {
                return true;
            }
        } else {
            /* Only check the hash if our string is long enough */
            char hash[41];
            sha1sum(hash, strcp);
            if(counter % 1000000 == 0) {
                printf("[%d|%d] %s -> %s\n", rank, counter, strcp, hash);
            }
            if (strcmp(hash, target) == 0) {
                /* We found a match! */
                strcpy(found_pw, strcp);
                for (i = 0; i < comm_sz; i++) {
                  if (i != rank) {
                        MPI_Send(&rank, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
                    }
                }
 
                return true;
            }
        }
    }
 
    free(strcp);
    return false;
}
 
/**
 * Modifies a string to only contain uppercase characters.
 */
void uppercase(char *string) {
    int i;
    for (i = 0; string[i] != '\0'; i++) {
        string[i] = toupper(string[i]);
    }
}
 
int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        printf("Usage: mpirun %s num-chars hash [valid-chars]\n", argv[0]);
        printf("  Options for valid-chars: numeric, alpha, alphanum\n");
        printf("  (defaults to 'alphanum')\n");
        return 0;
    }
    MPI_Init(NULL, NULL);
 
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 
    /* Hostname */
    char hostname[MPI_MAX_PROCESSOR_NAME];
    int name_sz;
    MPI_Get_processor_name(hostname, &name_sz);
 
    int length = atoi(argv[1]);
    if(length >8) {
        printf("That password is really too long to be cracked\n");
        return 0;
    }
 
    char *target = argv[2];
    uppercase(target);
 
    if(argc == 4 && strcmp("alpha", argv[3]) == 0) {
        valid_chars = alpha;
    }
    else if(argc == 4 && strcmp("numeric", argv[3]) == 0) {
        valid_chars = num;
    }
    else {
        valid_chars = alpha_num;
    }
 
 
    double time1 = MPI_Wtime();
 
      
    int x = strlen(valid_chars) / comm_sz;
 
    printf("Password cracker on %s, rank %d (of %d) starting from %c \n", hostname, rank, comm_sz, valid_chars[x * rank]);
    printf("\ttarget = %s alphabet %s .\n", target, valid_chars);
         
    /* TODO: the 'crack' call above starts with a blank string, and then
     * proceeds to add characters one by one, in order. To parallelize this, we
     * need to make each process start with a specific character. Kind of like
     * the following:
     */
     
    int i;
    for (i = x * rank; i < (x * (rank + 1)) ; ++i) {
        char start_str[2] = { valid_chars[i], '\0' };
         
        bool found = crack(target, start_str, length);
        if( found) {
            break;
        }
    }
    
 
    if (strlen(found_pw) > 0) {
        printf("Recovered password: %s\n", found_pw);
    }
 
    int total = 0;
 
    MPI_Reduce(&counter, &total, 1, MPI_INT, MPI_SUM,
        0, MPI_COMM_WORLD);
 
    double time2 = MPI_Wtime();
 
     
    if(rank == 0 && total > 0) {
        printf("\nHashes generated:   %d\n", total);
        printf("Time taken %.2f\n", time2 - time1);
    }
  
    /* Clean up */
    MPI_Finalize();
 
    return 0;
}