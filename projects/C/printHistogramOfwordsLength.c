#include <stdio.h>

/*print histogram of word length*/
#define MAXWL 100
#define MAXWN 30
#define IN 1
#define OUT 0

main()
{
	int c, nw, nc ,status;
	int word[MAXWN];

	nc = nw = 0;
	status = OUT;

	for(int i = 0;i < MAXWN; i++){
		word[i] = 0;
	}

	// while((c = getchar()) != EOF && nw < MAXWN)
	// {
	// 	if(c == ' ' || c == '\t' || c == '\n'){
	// 		status = OUT;
	// 		if(nc > 0){
	// 			word[nw] = nc;
	// 			++nw;
	// 			nc = 0;
	// 		}
	// 	}
	// 	else if (status == OUT){
	// 		status = IN;
	// 		++nc;
	// 	}
	// 	else if(status == IN){
	// 		++nc;
	// 	}
	// }

	while((c = getchar()) != EOF && nw < MAXWN)
	{
		if(c == ' ' || c == '\t' || c == '\n'){
			if (word[nw] > 0){
				nw++;
			}
			continue;
		}
		word[nw]++;
		
	}

	for(int i = 0; i < MAXWN; i++){
		for(int j = 0; j < MAXWL && j < word[i]; j++){
			putchar('*');
		} 
		putchar('\n');
	}
}