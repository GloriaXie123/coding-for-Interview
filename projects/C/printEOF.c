#include <stdio.h>

# define END EOF
/*print the integer value of EOF*/
main()
{
    int c ;

    c = putchar(END);

    printf("the corresponding interger value of eof is: %d",c);
}