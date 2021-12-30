#include <stdio.h>
#define MAXOP 1000
/*Write the program expr, which evaluates a reverse Polish expression from the command line,
where each operator or operand is a seperate argument, for example:
expr 2 3 4 + *
evaluates 2*(3+4).
*/
int getop(char[]);
void main(int argc, char *argv[])
{
	int type, int op1, op2;
	char S[MAXOP];

	while (--argc > 0 && *(++argv) != NULL)
	{
		switch (type = getop(s))
		{
		case isdigit(type):
			break;
		case '+':
			op2 = pop();
			op1 = pop();
			push(op2 + op1);
			break;
		case '-':
			op2 = pop();
			op1 = pop();
			push(op1 - op2);
			break;
		case '*':
			op2 = pop();
			op1 = pop();
			push(op2 * op1);
			break;
		case '/':
			op2 = pop();
			op1 = pop();
			push(op1 / op2);
			break;
		case '\n':
			printf("the result of the expression is: %ld\n", pop());
		default:
			printf("Error: Invalid operations\n");
		}
	}
}
