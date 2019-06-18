# CS 241 Data Organization using C

# Lab 3: getBits

January 29, 2018

## 1 Description

Section 2.9 of Kernighan and Ritchie provides the getbits function. Write a C program that reads records from the
standard input stream, passes the data in each valid record to getbits and displays the result. You will also be required
to submit a makefile that compiles your code when executing "make" on a Linux system. Furthermore, in addition to
testing your code on the provided testing script, you will need to write at least 10 additional test cases to run your code
on.

For this program, a record is a sequence of semicolon delimited numeric characters terminated with a newline. A valid
record has the form: x;p;n
where x, p, and n correspond to the x, p, and n in getbits and where each of these values is within the range usable by
getbits on a machine (such as moons.cs.unm.edu), where an unsigned int is 4 bytes.

For each valid input record, you will print a line with the arguments to and the result from calling getBits. For each
error record, output an error message. There are sample input and output files linked.

When trying to determine a valid range for n and p, please note that if the right hand operand of shift operator is
greater than or equal to the number of bits of the type of the left hand operand, the behaviour is undefined.

For the testing code, you will be required to submit at least 10 test cases for your code. Some of these will in turn be
used to test your classmates’ code. You will be graded based on accuracy and completeness. Does this test code cover
enough edge cases to be comprehensive? Does the output follow the specification precisely? You will be required to
submit input as well as expected output. We have also included sample testing code here: testgetbits.in and
testgetbits.out. Provided examples do not count towards your minimum number of test cases.