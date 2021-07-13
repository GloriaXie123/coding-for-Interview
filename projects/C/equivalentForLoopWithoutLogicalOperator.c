#include <stdio.h>

main()
{
	int c;
	int limit = 1000;
	int s[limit];
	for (int i = 0; i < limit - 1; ++i)
	{
		c = getchar();
		if (c != 'EOF')
		{
			if (c != '\n')
			{
				s[i] = c;
			}
		}
	}
}
