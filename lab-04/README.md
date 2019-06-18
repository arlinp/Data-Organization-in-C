# CS 241 Data Organization using C

# Lab 4: Sudoku Solver

February 5, 2018

## 1. Sudoku

Sudoku is a logic-based, combinatorial number placement puzzle. The objective is to fill a 9x9 grid with digits so that
each column, each row, and each of the nine 3x3 sub-grids that compose the grid (also called “boxes”, “blocks”,
“regions”, or “sub-squares”) contains all of the digits from 1 to 9. The puzzle setter provides a partially completed
grid, which for a well-posed puzzle has a unique solution.

## 2. Requirements

Write a C program that reads a bunch of sudoku puzzles from standard input and solves them. This program needs to
be started from sudoku-starter.c. You will also need to write a makefile that compiles your code. You should use
testSudoku.in/testSudoku.out to test your code. Whitespace/other small formatting details matter.

Each puzzle is given as a line of 81 characters, with ‘.’ characters representing unknown digits.


If a solution exists that uses the given digits in the given order, find it, print “Solution:”, and then, on a new line,
pretty print out the solution in the grid format.
If not, echo the input and print “No Solution” on a new line.
If the input does not follow the specified format, print “Error” on a new line.
After each test case, output a blank line to standard output. So, each line of input will produce 3 lines of output:
echo of input, output line, and blank line.
Whether or not the test was a valid sudoku puzzle, your program must be prepared to handle the next test. Make
sure that you do not leave your program in an invalid state as the result of an error test case. This is a
particularly common issue when dealing with lines that were not of the expected length. Make sure you reset all
relevant bookkeeping before beginning the next line of input.

### 2.1 Input Format

A record is a sequence of characters
followed by the newline character: ‘\n’.
The input will consist of some number of
records (lines).
Each valid record will consist of 81
characters, representing the 9 rows of a
sudoku puzzle, each consisting of 9
characters.
The only valid characters in a record are the
nine possible digits (1-9) and ‘.’.
A valid record does not have the same
number appear twice in the same row,
column, or box.

###2.2 Output Format

Your program is expected to be able to print out any sudoku puzzle
in the grid format. For example:

4 1 7 | 3 6 9 | 8 2 5

6 3 2 | 1 5 8 | 9 4 7

9 5 8 | 7 2 4 | 3 1 6

------ + ------ + ------

8 2 5 | 4 3 7 | 1 6 9

7 9 1 | 5 8 6 | 4 3 2

3 4 6 | 9 1 2 | 7 5 8

------ + ------ + ------

2 8 9 | 6 4 3 | 5 7 1

5 7 3 | 2 9 1 | 6 8 4

1 6 4 | 8 7 5 | 2 9 3


