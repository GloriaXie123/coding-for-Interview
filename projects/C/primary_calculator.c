#include <stdio.h>
#include <ctype.h>
#include "atof.c"
/*using inverse polish notation to
implement a primary calculator
we don't think about those invalid case
in which we didn't input enough oprands
or we miss operators*/

#define MAXOP 100
#define MAXVAL 100
#define NUM '0'
int getnext(char[]);
double pop(void);
void push(double f);

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

int sp = 0;
double stack[MAXVAL];

double pop()
{
	if (sp > 0)
	{
		--sp;
		return stack[sp];
	}
	else
	{
		printf("stack is empty\n");
		return 0.0;
	}
}

void push(double f)
{
	if (sp < MAXVAL)
	{
		stack[sp] = f;
		++sp;
	}
	else
	{
		printf("stack is full, cant push %.8g\n", f);
	}
}

int getch(void);
void ungetch(int);

int getnext(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
	{
		return c;
	}
	i = 0;
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}
	if (c == '.')
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';
	if (c != EOF)
	{
		ungetch(c);
		return NUM;
	}
	return c;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch: too many characters");
	}
	else
	{
		buf[bufp++] = c;
	}
}
