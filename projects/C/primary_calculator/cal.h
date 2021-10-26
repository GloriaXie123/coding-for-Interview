#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "C/atof.c"
#define NUM '0'
int getnext(char[]);
double pop(void);
void push(double f);
int getch(void);
void ungetch(int);
