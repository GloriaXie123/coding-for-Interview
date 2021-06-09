#include <stdio.h>

#define LOWER 0.0
#define UPPER 300.0
#define STEP 20.0

main()
{
    float fah;
    for(fah = LOWER;fah <= UPPER; fah = fah + STEP){
        printf("%3.0f\t%6.1f\n",fah,5.0 * (fah - 32.0) /9.0);
    }
}