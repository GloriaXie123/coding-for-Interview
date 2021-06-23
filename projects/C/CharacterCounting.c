#include <stdio.h>

/*count the number of characters*/
main()
{
    long num;

    num = 0;
    while (getchar() != EOF)
    {
        ++num;
        printf("%ld\n", num);
    }
}