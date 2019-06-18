# CS 241 Data Organization using C

# Lab 2: Counting Characters, Words, and Lines

## TO RUN:
Run the following commands on a Linux machine

```
gcc -Wall -ansi -pedantic wordCount.c
./a.out < testWords.in > myOut.txt
```

To show that there is no difference between my output and the expected output (testWords.out), run
```
diff myOut.txt testWords.out
```

## 1 Requirements

The program given in section 1.5.4 of Kernighan and Ritchie reads a text file from the standard input stream and
outputs the number of characters, words, and lines of the input file. Your task is to modify this program (or completely
rewrite it) so that for each line of the input file, the characters in the line are echoed to the standard output stream
preceded by the line number (formatted to take at least 2 characters, right justified, followed by a period and a space)
and followed by a space and then the number of words in the line and the number of characters in the line enclosed in
square brackets and separated by a comma.

After echoing the original file, output three more lines with the following information: the number of lines, words, and
characters (as in the original, just more verbose); the line number of the line with the fewest number of words and the
number of words on that line; the line number of the line with the fewest characters and the number of characters on
that line. If two or more lines tie for the same number of words/characters, report the later line. Exactly match the
formatting given in the example below.

## 1.1 Example

For example, given an input file containing:

It is by will alone I set my mind in motion.
It is by the juice of Sapho that thoughts acquire speed,
the lips acquire stains, the stains become a warning.
It is by will alone I set my mind in motion.
-- Mentat mantra from David Lynch’s Dune movie

Your program must output:

```
1.It is by will alone I set my mind in motion. [11,44]

2.It is by the juice of Sapho that thoughts acquire speed, [11,56]

3. the lips acquire stains, the stains become a warning. [9,56]

4.It is by will alone I set my mind in motion. [11,44]

5. -- Mentat mantra from David Lynch’s Dune movie [8,52]

5 lines, 50 words, 252 characters
Line 5 has the fewest words with 8
Line 4 has the fewest characters with 44
```
## 1.2 Assumptions

You may assume that the input contains only the standard ASCII printable characters (decimal codes 32 through 126)
along with newline, ’\n’, and tab, ’\t’. You may also assume that the input will end with a newline character.


