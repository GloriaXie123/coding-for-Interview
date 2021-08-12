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
