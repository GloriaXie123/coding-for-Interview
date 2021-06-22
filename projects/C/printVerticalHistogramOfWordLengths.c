#include <stdio.h>

/*print vertical histogram of word lengths*/
#define MAXWN 30
#define MAXWL 100
main(){
	int c, index;
	int word[MAXWN];

	for(int i = 0; i < MAXWN; i++){
		word[i] = 0;
	}

	index = 0;
	while ((c = getchar()) != EOF && index < MAXWN)
	{
		if(c == ' ' || c == '\t' || c == '\n'){
			if(word[index] > 0){
				++index;
			}
			continue;
		}
		++word[index];
	}

	for(int i = 0; i < MAXWL; i++){
		for(int j = 0;j < MAXWN; j++){
			if(i < word[j])
				putchar('*');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}