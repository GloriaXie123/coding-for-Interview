#include <stdio.h>

/*当farh=0, 20, ... ,300时，分别打印华氏温度
与摄氏温度对照表*/
main()
{
    float fahr, celsius;
    float lower , upper , step;

    lower = 0;
    upper = 300;
    step = 20.0;

    fahr == lower;
    printf("convert fahrenheit to celsius\n");
    while (fahr <= upper){
        celsius = 5 * (fahr - 32.0) /9.0;
        printf("%3.0f\t%6.1f\n",fahr,celsius);
        fahr = fahr + step;
    }

}
