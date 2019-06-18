/******************/
/* Arlin Pedregon */
/* Section 2      */
/******************/

#define TRUE 1
#define FALSE 0
#define UINT_MAX 4294967295  /*max size of unsigined int*/


#include <stdio.h>

int maxSize;/* boolean to see if x is larger than UINT_MAX */
int end; /*boolean to see if EOF*/

/************************************* 
 * readRecord reads the records from 
 *the IN files. The record formatted
 * as x;p;n
 *
 *@parameter void This method is the
 *first to read the file nothing needed
 *@return number unsigned int the values of x,
 *p, or n when called
 *
 *@algorithm This method assumes that all
 the lines in the input file have all 3
 values x;p;n and ONLY 3 values. Reads 
 the chars until it reads a delimiter
 and uses the atoid function from the 
 book to turn it into an int .
 Checks if the number is the valid 
 unsigned int size. Sets masSize flag
 if too big. Pauses readingg when it
 hits the delimiter
*************************************/
unsigned int readRecord(void)
{
  double number = 0;
  char c;
  int stopFlag = FALSE; /*flag to pause the reading of input*/

  while (stopFlag != TRUE)
    {
      c = getchar();

      if (c == EOF)
	{
	  end = TRUE; /*signals EOF*/
	  stopFlag = TRUE;
	  break;

	}

      else if ( c >= '0' && c <= '9')
	{
	  number = 10 * number + (c - '0'); /*atoi implementation from book*/

	  if (number > UINT_MAX)
	    {
	      maxSize = TRUE; /*number is too big*/
	    }
	}

      /* Something other than a digit read, so stop reading input and return*/
      else stopFlag = TRUE;
    }
  return number;
}


/*************************************
 * getbits: get n bits from position p 
 *from the book
 *************************************/
unsigned int getbits(unsigned int x, int p, int n)
{
  return ( x >> (p + 1 - n) ) & ~(~0 << n);
}

/************************************* 
 *main method that creates the variables
 and sends them off to be assigned values
 *
 *@parameter void This method is the
 *first to read the file nothing needed
 *@return number unsigned int the values of x,
 *p, or n when called
 *
 *@algorithm 
 *************************************/
int main (void)
{
  unsigned int x;
  int p;
  int n;
  end = FALSE;

  while(!end) /* Keep looping until EOF in readRecord */
    {
      maxSize = FALSE;
      x = readRecord();
      p = (int) readRecord();
      n = (int) readRecord();

      /* Check for error messages */

      if (maxSize) printf("Error: value out of range\n");
      else if (p > 31) printf("Error: position out of range\n");
      else if (n > 31) printf("Error: number of bits out of range\n");
      else if (n > (p + 1) )
	{
	  printf("Error: too many bits requested from position\n");
	}
      /*this case is the only way I could fix exitiing program
       *says that x is not a number greater than 0 so don't process*/
      else if(x == 0)
	{
	  break;
	}
      else /* Passed all error checks, print result */
	{
	  printf("getbits(x=%u, p=%d, n=%d) = %u\n", x, p, n, getbits(x, p, n));
	}
    }

  return 0;
}

