/************************/
/* Arlin Pedregon       */
/* 2/26/18              */
/************************/
#include <stdio.h>
/*checks if board has solution
 *if no 0s, return 1 for complete*/
int complete(int grid[9][9])
{
  int row, col;
  for (row = 0; row < 9; row++)
    {
      for (col = 0; col < 9; col++)
	{
	  if (!grid[row][col])
	    {
	      printf("No solution\n\n");
	      return 1;
	    }
	}
    }
  return 0;
}
/* determines if c at index is valid, given the character array, grid 
 *if it is already in the row, columns, or box, it returns 0*/
int valid(int grid[9][9], int position, int c)
{
  int i, j;
  int row = position / 9;
  int col = position % 9;
  /*fancy calculations to figure out the top left corner of
    box given the index*/
  int boxRowStart = row - (row % 3);
  int boxColStart = col - (col % 3);
  
  /* check if number is okay to use in row */
  for (i = 0; i < 9; i++)
    {
      if (grid[row][i] == c)
	{
	  return 0;
	}
    }
  
  /*check column for number*/
  for (i = 0; i < 9; i++)
    {
      if (grid[i][col] == c)
	{
	  return 0;
	}
    }
  
  /*check box*/
  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  if (grid[boxRowStart + i][boxColStart + j] == c)
	    {
	      return 0;
	    }
	}
    }
  
  /*else, the number is valid to use there*/
  return 1;
}

/*this is the reason my code is late. Could not figure out
  but found math from java game from my cs251*/
int checkBoxes(int grid[9][9])
{
  int row, col, i, j;
  for (row = 0; row < 9; row += 3)
    {
      for (col = 0; col < 9; col += 3)
	{
	  for (i = 0; i < 9; i++)
	    {
	      for (j = i + 1; j < 9; j++)
		{
		  /*this is the unoriginal part*/
		  if ( (grid[row + i / 3][col + i % 3] != 0) &&
		       (grid[row + i / 3][col + i % 3] ==
			grid[row + j / 3][col + j % 3]) )
		    {
		      return 1;
		    }
		}
	    }
	}
    }
  return 0;
}

/*check all columns for duplicates*/

int checkColumns(int grid[9][9])
{
  int row, col, i;
  for (col = 0; col < 9; col++)
    {
      for (row = 0; row < 9; row++)
	{
	  for (i = row + 1; i < 9; i++)
	    {
	      if ((grid[row][col] != 0) && (grid[row][col] == grid[i][col]))
		{
		  return 1;                      /* column error found in grid */
		}
	    }
	}
    }
  return 0;
}

  
int checkRows(int grid[9][9])
{
  int row, col, i;
  for (row = 0; row < 9; row++)
    {
      for (col = 0; col < 9; col++)
	{
	  for (i = col + 1; i < 9; i++)
	    {
	      if ((grid[row][col] != 0) && (grid[row][col] == grid[row][i]))
		{
		  /*error*/
		  return 1;
		}
	    }
	}
    }
  return 0;
}

/*Solves the sudoku grid*/
int findSolution(int grid[9][9], int position)
{
  int num;
  int row = position / 9;
  int col = position % 9;

  /*if we finished all positions*/
  if (position == 81) return 1;
  
  /*skips to next position if there's a number at position*/
  if (grid[row][col] != 0)
    {
      return findSolution(grid, ++position);
    }

  else
    {
      for (num = 1; num <= 9; num++)
	{
	  if (valid(grid, position, num)) 
	    {
	      grid[row][col] = num;
	      /*feed it back into the recursive algorithm with the
	       *updated number. This is where the frames of possibilities
	       *are created*/
	      if (findSolution(grid, position)) return 1;
        
	      /*set back to 0 if it causes error (one of the frames didn't work)*/
	      grid[row][col] = 0;
	    }
	}
      return 0;
    }
}

/*Prints out the grid array to screen in a 9x9 square*/
void prettyPrint(int grid[9][9])
{
  
  int i, j;
  printf("solution:\n");
  for(i=0; i <9; i++)
    {
      for(j=0; j<9; j++)
	{
	  if(j == 8)printf("%d", grid[i][j]);
	  else{
	    printf("%d ", grid[i][j]);
	    if(j==2 || j==5) printf("| ");
	  }
	}
      printf("\n");
      if(i==2 || i==5) printf("------+-------+------\n");
    }
}

  
 
/*Reads in one grid*/
int readLine(int grid[9][9])
{
  int index, c, i, j;
  int error  = 0;

  for (index = 0; (c = getchar()) != '\n'; index++)
    {
      if (c == EOF) return EOF;
      putchar(c);
      if ((c < '1' || c > '9') && (c != '.')) error = 1;
      /*turns blanks to 0s for bookkeeping*/
      if (c == '.') c = '0';
      
      /*fancy little math algorith I found to calculate
       *row and column in 2D array*/
      i = (index / 9) % 9;
      j = index % 9;
      grid[i][j] = c - '0';
    }
  putchar('\n');
  if (index != 81) error = 1;
  return error;
}

/*This program solves any sudoku problems
 *almost matches */
int main(void)
{
  int grid[9][9];
  int position = 0;
  int error;

  while((error = readLine(grid)) != EOF)
    {
      error += checkRows(grid);
      error += checkColumns(grid);
      error += checkBoxes(grid);

      if(error) printf("Error\n\n");
      else
        {
          findSolution(grid, position);
          if(!complete(grid)) prettyPrint(grid);
        }
    }
  return 0;
}


