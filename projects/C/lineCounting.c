#include <stdio.h>

/*counting the new line in a program*/
main()
{
    int c, nl, nt, ns;

    nl = 0;
    nt = 0;
    ns = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++nt;
        if (c == ' ')
            ++ns;
    }
    printf("the lines are :%d，the tabs are:%d,the spaces are %d", nl, nt, ns);
}
