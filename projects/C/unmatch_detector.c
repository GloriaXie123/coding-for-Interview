#include <stdio.h>
/*write a program to check a C program for
rudimentary syntax errors like: unmatched parentheses,
brackets and braces, don't forget about quotes,
both single and double, escape sequences and comments
(the program is hard if you do it in full generality)*/
void in_quote(int);
void in_comment(void);
void search(int);

int brace = 0;
int brack = 0;
int parentheses = 0;

void main()
{
	int c;
	extern int brace, brack, parentheses;

	while ((c = getchar()) != EOF)
	{
		if (c == '\'' || c == '"')
		{
			in_quote(c);
		}
		else if (c == '/')
		{
			c = getchar();
			if (c == '*')
			{
				in_comment();
			}
			else
			{
				search(c);
			}
		}
		else
		{
			search(c);
		}

		if (brace < 0)
		{
			printf("unbalanced brace\n");
			brace = 0;
		}
		else if (brack < 0)
		{
			printf("unbalanced brack\n");
			brack = 0;
		}
		else if (parentheses < 0)
		{
			printf("unbalanced parentheses\n");
			parentheses = 0;
		}

		if (brace > 0)
		{
			printf("unbalanced brace\n");
		}
		else if (brack > 0)
		{
			printf("unbalanced brack\n");
		}
		else if (parentheses > 0)
		{
			printf("unbalanced parentheses\n");
		}
	}
}

void in_quote(int c)
{
	int d;
	while ((d = getchar()) != c)
	{
		if (d == '\\')
		{
			getchar();
		}
	}
}

void in_comment()
{
	int c, d;
	c = getchar();
	d = getchar();
	while (c != '*' || d != '/')
	{
		c = d;
		d = getchar();
	}
}

void search(int c)
{
	// extern int brace, brack, parentheses;
	if (c == '{')
	{
		++brace;
	}
	else if (c == '}')
	{
		--brace;
	}
	else if (c == '[')
	{
		++brack;
	}
	else if (c == ']')
	{
		--brack;
	}
	else if (c == '(')
	{
		++parentheses;
	}
	else if (c == ')')
	{
		--parentheses;
	}
}
