#include <stdio.h>

#define IN 1
#define OUT 0
/*counting lines,characters,words*/
main()
{
    int c, nl, nc, nw, status;

    nl = nc = nw = 0;

    status = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
        if (c == '\n' || c == '\t' || c == ' ')
            status = OUT;
        else if (status == OUT)
        {
            status = IN;
            ++nw;
        }
        ++nc;
    }
    printf("there are lines:%d,there are words:%d,there are characters:%d", nl, nw, nc);
}
