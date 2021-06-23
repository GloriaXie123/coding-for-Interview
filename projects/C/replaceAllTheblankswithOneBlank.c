#include <stdio.h>

#define NONBLANK 'a'
/*copy input to output and replace single blank or more blanks with only one blank*/
main()
{
    int c, lastc;
    lastc = NONBLANK;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ')
        {
            putchar(c);
        }
        else
        {
            if (lastc != ' ')
            {
                putchar(' ');
            }
        }
        lastc = c;
    }
}