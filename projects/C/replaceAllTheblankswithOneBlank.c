#include<stdio.h>

/*copy input to output and replace single blank or more blanks with only one blank*/
main()
{
    int c, lastc;

    lastc = ' ';
    while ((c = getchar()) != EOF){
        if(c == ' ' && lastc == ' ')
            continue;

        printf("the character is:%d\n",c);
        lastc = c;
    }
}