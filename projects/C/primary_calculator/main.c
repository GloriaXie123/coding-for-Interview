#include "cal.h"

#define MAXOP 100

void main()
{
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getnext(s)) != EOF)
	{
		// printf("%s", s);
		if (type == NUM)
		{
			push(atof(s));
		}
		else if (type == '+')
		{
			double op2 = pop();
			double op1 = pop();
			push(op1 + op2);
		}
		else if (type == '-')
		{
			op2 = pop();
			push(pop() - op2);
		}
		else if (type == '*')
		{
			push(pop() * pop());
		}
		else if (type == '/')
		{
			op2 = pop();
			push(pop() / op2);
		}
		else if (type == '\n')
		{
			printf("\t%.8g\n", pop());
		}
		else
		{
			printf("error: unkonwn command");
		}
	}
}
