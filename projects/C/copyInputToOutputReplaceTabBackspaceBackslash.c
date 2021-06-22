#include<stdio.h>

/*copy input to output,replacing all the tabs,backspaces 
and backslashes with \t,\b and \\ */
main()
{
    int c;
    while ((c = getchar()) != EOF){
        if(c == '\t'){
            putchar('\\');
            putchar('\t');
            continue;
        }
        if(c == '\b'){
            putchar('\\');
            putchar('\b');
            continue;
        }
        if(c == '\\'){
            putchar('\\');
            putchar('\\');
            continue;
        }
        putchar(c);
    }
}