#include <stdio.h>
#include <ctype.h>

int main( void )
{
   int i=0;
   char ch;

   puts("Input an integer followed by a char:");

   /* read chars until non digit or EOF */
   while((ch = getchar()) != EOF && isdigit(ch))
      i = 10 * i + ch - 48; /* convert ASCII into int value */

   /* if non digit char was read, push it back into input buffer */
   if (ch != EOF)
      ungetc(ch, stdin);

   printf("i = %d, next char in buffer = %c\n", i, getchar());
   return 0;
}


