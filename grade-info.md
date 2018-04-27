# Grade Information

## Test 1: Compilation

No dead/leftover/unnecessary code should be highlighted here. [1 pts]

```
+ mpicc -g -Wall passwd.c -o passwd
+ test_end
+ return=0
+ [Output Lines: 0]
+ [Time elapsed: 0.10558]
```

## Test 2: Output Limiting

Hash should print only every 1m inversions

```
+ mpirun -n 2 ./passwd 2 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphanum
Password cracker on silicon, rank 0 (of 2) starting from a 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 1 (of 2) starting from F 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .

Hashes generated:   3844
Time taken 0.00
+ test_end
+ return=0
+ [Output Lines: 7]
+ [Time elapsed: 0.10357]
```

## Test 3: Password length too short

```
+ timeout 1 ./passwd 0 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphanum
Password cracker on silicon, rank 0 (of 1) starting from a 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .

Hashes generated:   3844
Time taken 0.01
+ test_end
+ return=0
+ [Output Lines: 5]
+ [Time elapsed: 0.10061]
```

## Test 4: Password hash too short

```
+ timeout 1 ./passwd 5 219E0B1F651D744D6B6D254BF9781 alphanum
+ test_end
+ return=124
+ [Output Lines: 0]
+ [Time elapsed: 1.02378]
```

## Test 5: Alphanumeric: 6emjb

```
+ timeout 100 mpirun --oversubscribe -n 30 ./passwd 5 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphanum
Password cracker on silicon, rank 24 (of 30) starting from W 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 27 (of 30) starting from 2 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 8 (of 30) starting from q 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 21 (of 30) starting from Q 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 6 (of 30) starting from m 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 23 (of 30) starting from U 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 12 (of 30) starting from y 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 14 (of 30) starting from C 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 16 (of 30) starting from G 
Password cracker on silicon, rank 10 (of 30) starting from u 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 29 (of 30) starting from 6 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 11 (of 30) starting from w 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 19 (of 30) starting from M 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 22 (of 30) starting from S 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 20 (of 30) starting from O 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 18 (of 30) starting from K 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 4 (of 30) starting from i 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 13 (of 30) starting from A 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 0 (of 30) starting from a 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 1 (of 30) starting from c 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 26 (of 30) starting from 0 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 2 (of 30) starting from e 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 7 (of 30) starting from o 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 9 (of 30) starting from s 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 15 (of 30) starting from E 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 5 (of 30) starting from k 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 17 (of 30) starting from I 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 25 (of 30) starting from Y 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 28 (of 30) starting from 4 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
Password cracker on silicon, rank 3 (of 30) starting from g 
	target = 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .
[17|1000000] Ieh61 -> 286F282C326C05735257E872F74946AFAC31DDFF
[27|1000000] 2eh61 -> DE6F6544CAF03B43C06DCA4E51CC6760DDFC6CB7
[29|1000000] 6eh61 -> F080E2C5FAD3AA4A764E3B3BB1DA819A1E22B2F7
[5|1000000] keh61 -> 0E20F5958D8B407EB9ACDF7F91F254C272E639FD
[10|1000000] ueh61 -> 1E8BC313B37D068FAA5E4E4F5F036F9761CE68F1
[16|1000000] Geh61 -> F6B799E2E9D155C94B00DA626895CE7103E7EFE3
[25|1000000] Yeh61 -> 3C50CAC9A4A154342716FBB6411B653ECD526F5F
[20|1000000] Oeh61 -> 1A7DD55FFE672C3BE906CFD53AA39CF9BCD70A96
[28|1000000] 4eh61 -> 8399B1BD567CFF58D5AC9E72ABD56DD778ACDBFF
[18|1000000] Keh61 -> AA300B4B90028C63AFAD77B379C4124A6EF29EA3
[2|1000000] eeh61 -> FF6A86A06BDCFD6CDDA1000EA529F2CB7D65E88C
[23|1000000] Ueh61 -> B2C9D66BC8B641204EE7240C96593F853DA65320
[15|1000000] Eeh61 -> CB97D93FD45F9323DC240E34D55492C3F1C91D5A
[26|1000000] 0eh61 -> 95815FD02BACC17BFDE7CA37585FD31B6163AC60
[9|1000000] seh61 -> 15A6DAAD6BBABE03022DD2F19E769A5451ADA8D1
[11|1000000] weh61 -> 35D9BF0EB5720B094C23331036511F9242766617
[24|1000000] Weh61 -> 2F04F72B866FF375812757EFE8F43578D1E3C80E
[21|1000000] Qeh61 -> 41DC94C5DA822B9BDD841624F921E5F54AC65FE9
[1|1000000] ceh61 -> 5138C2964646B06FE73D9BCCB90DD3B18ECA57DF
[4|1000000] ieh61 -> E26DCAA665B0CB24D5A5FB97135FA57246EB0C2C
[22|1000000] Seh61 -> 30BC77FDE47B3C98C31F64D2C5DE3545CCE7D7DE
[3|1000000] geh61 -> CCB27EAC81AC55B0AEAE963F1BCA41E38F475051
[8|1000000] qeh61 -> 551F8C116E9A368045E4FA95B84FCA5EEC4D1EE1
[19|1000000] Meh61 -> A97EDE8473DD96C3E2CF05CE0BA2857F0B3143DD
[6|1000000] meh61 -> 6321CAF5412C2E275751791CABFE4FD0CA44ECBD
[7|1000000] oeh61 -> D1E42A9CB0FC14C93E3202EA0C04D2BD9402583B
[13|1000000] Aeh61 -> EEDFF81977B3F86F8DC76350CD349A179FCF21D9
[14|1000000] Ceh61 -> 2F276D51621E90DE034FB3C460179F41B803BC3D
[0|1000000] aeh61 -> 12A7B3DCA9EC0D60D6F90C01E033AC370E9AD2D6
[12|1000000] yeh61 -> 26E8FB1B1F56FC177F70BE340CBEBD6A60C52651
Recovered password: 6emjb

Hashes generated:   30462554
Time taken 41.51
+ test_end
+ return=0
+ [Output Lines: 94]
+ [Time elapsed: 41.9127]
```

## Test 6: Numeric: 900000001

```
+ timeout 10 mpirun --oversubscribe -n 10 ./passwd 9 eee65088f52323a4405db87cb40c706accf7ffe5 numeric
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
--------------------------------------------------------------------------
mpirun has exited due to process rank 9 with PID 0 on
node silicon exiting improperly. There are three reasons this could occur:

1. this process did not call "init" before exiting, but others in
the job did. This can cause a job to hang indefinitely while it waits
for all processes to call "init". By rule, if one process calls "init",
then ALL processes must call "init" prior to termination.

2. this process called "init", but exited without calling "finalize".
By rule, all processes that call "init" MUST call "finalize" prior to
exiting or it will be considered an "abnormal termination"

3. this process called "MPI_Abort" or "orte_abort" and the mca parameter
orte_create_session_dirs is set to false. In this case, the run-time cannot
detect that the abort call was an abnormal termination. Hence, the only
error message you will receive is this one.

This may have caused other processes in the application to be
terminated by signals sent by mpirun (as reported here).

You can avoid this message by specifying -quiet on the mpirun command line.
--------------------------------------------------------------------------
+ test_end
+ return=1
+ [Output Lines: 33]
+ [Time elapsed: 0.18006]
```

## Test 7: Alpha: Liu (provided test case)

```
+ timeout 10 mpirun --oversubscribe -n 4 ./passwd 4 a3a73b6dfa8f4caedd0349f676ae46b39bdb7fbd alpha
Password cracker on silicon, rank 3 (of 4) starting from N 
	target = A3A73B6DFA8F4CAEDD0349F676AE46B39BDB7FBD alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .
Password cracker on silicon, rank 0 (of 4) starting from a 
	target = A3A73B6DFA8F4CAEDD0349F676AE46B39BDB7FBD alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .
Password cracker on silicon, rank 1 (of 4) starting from n 
	target = A3A73B6DFA8F4CAEDD0349F676AE46B39BDB7FBD alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .
Password cracker on silicon, rank 2 (of 4) starting from A 
	target = A3A73B6DFA8F4CAEDD0349F676AE46B39BDB7FBD alphabet abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .
[3|1000000] TYLc -> DCD09DF104C9D1FBFB6A30DFED13717DE033CF6B
[1|1000000] tYLc -> 410D55D48C12979D11D99D4AA4F5EC7C2DDE52FE
[2|1000000] GYLc -> ADB6214DDC101DA0C3BEF0E7161A68D77DFB0134
[0|1000000] gYLc -> 236416452ADB5F1B4E081862F7100BF768C3F63E
Recovered password: Meow

Hashes generated:   6925257
Time taken 4.56
+ test_end
+ return=0
+ [Output Lines: 16]
+ [Time elapsed: 4.679]
```

## Test 8: Alphanumeric: Iaaaaaaaaaaemja

```
+ timeout 60 mpirun --oversubscribe -n 25 ./passwd 15 58765A498C1AE6A1518DC9DA54514EA26298D658
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
That password is really too long to be cracked
--------------------------------------------------------------------------
mpirun has exited due to process rank 11 with PID 0 on
node silicon exiting improperly. There are three reasons this could occur:

1. this process did not call "init" before exiting, but others in
the job did. This can cause a job to hang indefinitely while it waits
for all processes to call "init". By rule, if one process calls "init",
then ALL processes must call "init" prior to termination.

2. this process called "init", but exited without calling "finalize".
By rule, all processes that call "init" MUST call "finalize" prior to
exiting or it will be considered an "abnormal termination"

3. this process called "MPI_Abort" or "orte_abort" and the mca parameter
orte_create_session_dirs is set to false. In this case, the run-time cannot
detect that the abort call was an abnormal termination. Hence, the only
error message you will receive is this one.

This may have caused other processes in the application to be
terminated by signals sent by mpirun (as reported here).

You can avoid this message by specifying -quiet on the mpirun command line.
--------------------------------------------------------------------------
+ test_end
+ return=1
+ [Output Lines: 36]
+ [Time elapsed: 0.35881]
```

## Test 9: Invalid password, too many processes

```
+ timeout 5 mpirun --oversubscribe -n 20 ./passwd 3 58765A498C1AE6A1518DC9DA54514EA26298D658 numeric
Password cracker on silicon, rank 19 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 0 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 6 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 9 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 11 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 16 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 17 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 14 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 15 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 12 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 7 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 8 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 10 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 2 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 18 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 4 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 1 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 3 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 5 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
Password cracker on silicon, rank 13 (of 20) starting from 0 
	target = 58765A498C1AE6A1518DC9DA54514EA26298D658 alphabet 0123456789 .
+ test_end
+ return=0
+ [Output Lines: 40]
+ [Time elapsed: 0.27235]
```


## Deductions

* (Test 4): Should quit when hash is too short [-1]
* (Test 6): Password not recovered [-1]
* (Test 8): Password not recovered [-1]
* (Test 9): Should report failed password cracking attempt [-1]
* Missing the first two README answers [-2]
