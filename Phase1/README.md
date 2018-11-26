# Decaf Compiler (Phase 1)

## Structure
- src
	- scanner.l : scanner file 
	- parser.ypp : parser file
	- Makefile : build file

- test-programs
	- binary.dcf : Decaf program to perform binary search
	- fact.dcf : Decaf program to find the factorial of an element
	- fib.dcf : Decaf program to find the fibonacci series upto nth element
	- hanoi.dcf : Decaf program to find number of iterations to do the Tower of Hanoi problem
	- merge.dcf : Decaf program to perform merge sort


## Run
$ cd src
$ make
$ ./parser $inp_program_file

Eg.
cd src 
make
./parser ../test-programs/fib.dcf

## Description
- src
	- scanner.l : has the regex for the token types.
	- parser.ypp : has the Grammar and the corresponding actions to be taken 
	- Makefile : build file for the compiler

- test-programs
	- binary.dcf : Decaf program to perform binary search
	- fact.dcf : Decaf program to find the factorial of an element
	- fib.dcf : Decaf program to find the fibonacci series upto nth element
	- hanoi.dcf : Decaf program to find number of iterations to do the Tower of Hanoi problem
	- merge.dcf : Decaf program to perform merge sort

## Future Work
-The Phase1 checks if the input code is parsable or not. 
-Phase2 and Phase3 remain to be done, as the bugs haven't been fixable yet. 