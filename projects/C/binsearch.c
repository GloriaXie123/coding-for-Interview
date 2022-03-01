#include <stdio.h>
#include <string.h>

#define MAXWORD 100
int getword(char *word, int);
struct key *binsearch(char *, struct key *, int);

void main()
{
	char word[MAXWORD];
	sturct key *p;

	while (getword(word, MAXWORD) != EOF)
	{
		if (isalpha(word[0]))
		{
			if (p = binsearch(word, keytab, NKEYS) != NULL)
			{
				p->count++;
			}
		}

		for (p = keytab; p < keytab + NKEYS; p++)
		{
			if ((p->count) > 0)
			{
				printf("%4d %s\n", p->count, p->word);
			}
		}
	}
}
