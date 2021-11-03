#include <stdio.h>
#include <stdlib.h>
/*given the basic framework,it's straightforward to extend
the calculator, Add the modulus operator and provisions for 
negative numbers.*/
#define NUM 9
void main()
{
	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUM:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(op2 - pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			push(op2 / pop());
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
			{
				push(pop() % op2);
			}
			else
			{
				printf("error: invalid divisor\n");
			}
			break;
		case '\n':
			printf("%f\n", pop());
			break;
		default:
			printf("invalid command\n");
			break;
		}
	}
}

int getch(void);
void ungetch(int);
int getop(char s[])
{
	int i, c;
	i = 0;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	if (!isdigit(c) && c != '.' && c != '-')
	{
		return c;
	}
	if (c == '-')
	{
		s[++i] = c = getch();
		if (isdigit(c) || c == '.')
		{
			while (isdigit(c) || c == '.')
			{
				c = getch();
				++i;
				s[i] = c;
			}
		}
		else
		{
			if (c != 'EOF')
			{
				ungetch(c);
			}
			return '-';
		}
	}
	if (isdigit(c))
	{
		while (isdigit(c))
		{
			c = getch();
			++i;
			s[i] = c;
		}
	}
	if (c == '.')
	{
		s[++i] = c = getch();
		while (isdigit(c))
		{
			c = getch();
			++i;
			s[i] = c;
		}
	}
	s[i] = '\0';
	if (c != 'EOF')
	{
		ungetch(c);
	}
	return NUM;
}

/*Add the commands to print the top elements
of the stack without poping, to duplicate it,
and to swap the top two elements, add a command
to clear the stack.*/
void peek(void)
{
	int top;
	top = pop();
	push(top);

	one = pop();
	two = pop();
	push(two);
	push(one);
}
void clear(void)
{
	sp = 0;
}
