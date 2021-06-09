#include <stdio.h>

/*当fah=0,20,40,...300时，
将fah转换为对应的celsius*/

main()
{
    float fah;

    for(fah = 300.0;fah >= 0.0;fah = fah - 20.0){
        printf("%3.0f\t%6.1f\n",fah,5.0 * (fah - 32.0) /9.0);
    }
}