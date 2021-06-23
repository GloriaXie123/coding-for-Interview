#include <stdio.h>

/*当celsius为0,20,40,...,300时，分别打印摄氏温度
和华式温度的对照表*/
main()
{
    float celsius, fah;
    float lower, upper, step;

    lower = 0.0;
    upper = 300.0;
    step = 20.0;

    celsius = lower;
    printf("convert celsius to fahrenheit\n");
    while (celsius <= upper)
    {
        fah = celsius * 9.0 / 5.0 + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fah);
        celsius = celsius + step;
    }
}