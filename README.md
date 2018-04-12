# Project 2: Distributed Password Cracker

See Project Spec here: https://www.cs.usfca.edu/~mmalensek/cs220/assignments/project-2.html

## Performance Evaluation

Edit this README.md file to answer the following questions:

### Password Recovery (1 pts)

Choose five entries from the password database and recover the passwords. List the username + password combinations here, along with the run time of your program and the number of hashes computed per second.

(fill in entries here)

### Performance Benchmarking (1 pts)

Choose one of the password hashes from the database (preferably one that runs for a while). Compare the run time with 4, 16, 32, and 64 processes. You'll need to run on the jet machines to do this. List the speedup and parallel efficiency for each.

(your answer)

### Algorithmic Trade-offs (1pts)

Brute-forcing passwords can take some time. What might be a better approach?  On the other hand, what is one guarantee our algorithm can provide that others may not be able to?

(your answer)

Brute forcing is time consuming because every possible combination of letters and numbers needs to be tried out. A faster approach which may however not meet
with the same level of success is to use a dictionary based attack. In this system, instead of trying out every single permuation of letters and numbers only
words that occur in the dictionary are used. However this will often lead to even very weak passwords being left uncracked. An enhanced approach is to use
a dictionary in combination with a few numbers and for example hello123, pizza456 etc.

In the brute force approach, if sufficient time and computing resources are available there is an assurance that the password can in fact be cracked. If the 
password is likely to contain special characters we just need to change our alphabet to include those possible special characters. 