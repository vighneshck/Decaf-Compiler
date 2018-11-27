# Decaf Compiler (Phase 2)

## Structure
- src
	- scanner.l : scanner file 
	- parser.ypp : parser file
	- Makefile : build file
	- programdef.h : The file containing all the class declarations
	- programdefs.cpp : The file containing all the class definitions, along with the visitor pattern and the code generation code.  

- test-programs
	- binary.dcf : Decaf program to perform binary search
	- fact.dcf : Decaf program to find the factorial of an element
	- fib.dcf : Decaf program to find the fibonacci series upto nth element
	- hanoi.dcf : Decaf program to find number of iterations to do the Tower of Hanoi problem
	- merge.dcf : Decaf program to perform merge sort


## Run
$ cd src
$ make
$ ./compiler $inp_program_file

Eg.
cd src 
make
./compiler ../test-programs/fib.dcf 

## Description
- src
	- scanner.l : has the regex for the token types.
	- parser.ypp : has the Grammar and the corresponding actions to be taken 
	- Makefile : build file for the compiler
	- programdef.h : Contains all the class declarations for the non-terminal tokens declared in the parser.
	- programdefs.cpp : Contains the constructors as well as the functions of all the classes. Also, contains the Visitor Pattern Code for Semantic checking, as well as for code generation. 

- test-programs
	- binary.dcf : Decaf program to perform binary search
	- fact.dcf : Decaf program to find the factorial of an element
	- fib.dcf : Decaf program to find the fibonacci series upto nth element
	- hanoi.dcf : Decaf program to find number of iterations to do the Tower of Hanoi problem
	- merge.dcf : Decaf program to perform merge sort

## Future Work
-Phase3 is still running into bugs, need to fix them. 