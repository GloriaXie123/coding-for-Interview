#include <stdio.h>

/*print input to output,output in the form one word per line*/
#define IN 1
#define OUT 0
main()
{
	int c, status;

	status = IN;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			status == OUT;
		}
		else if (status == OUT)
		{
			status == IN;
			putchar('\n');
			putchar(c);
		}
		else
		{
			putchar(c);
		}
	}
}
