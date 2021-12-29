#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);

void main(int argc, char *argv[])
{
	char line[MAXLINE];
	int except, number = 0, c = 0, lineno = 0, found = 0;
	/*process the command line arguments*/
	while (--argc > 0 && *(++argv)[0] == '-')
	{
		while (c = *++argv[0])
		{
			switch (c)
			{
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: illegal command arguments %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
		}
	}

	if (argc != 1)
	{
		printf("Usage : find -x -n pattern\n");
	}
	else
	{
		while (getline(line, MAXLINE) > 0)
		{
			if ((strstr(line, argv) != NULL) != except)
			{
				if (number)
				{
					lineno++;
					printf("%ld	", lineno);
					printf("%s\n", line);
				}
				found++;
			}
		}
	}
	return found;
}
