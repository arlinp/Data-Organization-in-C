/***************************/
/* Arlin Pedregon          */
/* 2/1/2018               */
/* CS-241 Lab 2            */
/***************************/

#include <stdio.h>

#define IN 1    /*inside a line*/
#define OUT 0   /*outisde a line*/

int main(void)
{
  int c;
  int wordsInLine = 0;
  int charsInLine = 0;
  int lineNumber = 0;
  int totalWords = 0;
  int totalChars = 0;
  int newLineState = IN;
  int inWordState = OUT;
  int leastChars, leastCharsLine = 0;
  int leastWords, leastWordsLine = 0;
  
  
  while((c = getchar()) != EOF)
  {
    if(newLineState)
    {
      ++lineNumber;
      printf("%2d. ", lineNumber);
      newLineState = OUT;
    }
    
    if(c == '\n')
    {
      printf(" [%d,%d]", wordsInLine, charsInLine);
      newLineState = IN;
      totalChars += charsInLine;
      totalWords += wordsInLine;
      
      /*check to see if this line has most chars*/
      if(charsInLine <= leastChars)
      {
        leastChars = charsInLine;
        leastCharsLine = lineNumber;
      }
      if(wordsInLine <= leastWords)
      {
        leastWords = wordsInLine;
        leastWordsLine = lineNumber;
      }
      /*reset char and word count for lines*/
      charsInLine = 0;
      wordsInLine = 0; 
    }
    
    if(c == ' ' || c == '\n' || c == '\t')
    {
      inWordState = OUT;
    }
    
    else if(!inWordState)
    {
      inWordState = IN;
      ++wordsInLine;
    }
    
    printf("%c", c);
    if(c != '\n')
    {
      ++charsInLine;
    }
 }      
  printf("%i lines, %i words, %i characters\n",
          lineNumber, totalWords, totalChars);
  printf("Line %i has the fewest words with %i\n",
	 leastWordsLine, leastWords);
  printf("Line %i has the fewest characters with %i\n",
          leastCharsLine, leastChars);

  return 0;
}
