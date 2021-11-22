#include <stdio.h>
#include <stlib.h>

#define MAXLINES 5000 //max lines to be sorted
#define MAXLINE 100		//max length of line
/*the program will sort text lines into alphabetic order*/

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void qsort(char *lineptr[], int start, int end);
void writelines(char *lineprt[], int nlines);
void main()
{
	int nlines; /*number of input lines read*/

	if ((nlines = readlines(lineptr, MAXLINES)) > 0)
	{
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input to big to sort\n");
		return 1;
	}
}

int getline(char *p, int maxline);
/*read input lines*/
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p = malloc(n * sizeof(char));

	nlines = 0;
	while ((len = getline(p, MAXLINE)) > 0)
	{
		if (maxlines-- <= 0 || p == NULL)
		{
			return -1;
		}

		*lineptr++ = p;
		nlines++;
	}
	return nlines;
}

int getline(char *p, int maxline)
{
	int c;
	int len = 0;
	while ((c = getchar()) != EOF && c != '\n' && maxline-- > 0)
	{
		*p++ = c;
		len++;
	}
	*--p = '\0';
	return len--;
}

void qsort(char *lineptr[], int start, int end)
{
	char *flag;
	flag = *(lineptr + end);

	int i, j;
	i = start;
	j = end + 1;
	while (i < j)
	{
		if (strcmp(*flag, *(lineptr + i)) > 0)
		{
			j--;
			if (i < j)
			{
				swap(*(lineptr + j), *(lineptr + i));
			}
		}
		else
		{
			i++;
		}
	}
	swap(*flag, *(lineptr + j - 1));

	qsort(*lineptr[], start, j - 2);
	qsort(*lineptr[], j, end);
}

void swap(*p, *g)
{
	char *tmp;
	*tmp = *p;
	*p = *g;
	*g = *tmp;
}

/*write output lines*/
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
	{
		printf("%s\n", *lineptr++);
	}
}
