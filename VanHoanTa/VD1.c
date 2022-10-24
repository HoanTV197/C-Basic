#include<stdio.h>

 int main(void)
{
    double i,a[10];

    printf("please enter 10 number:\n");
    for (i=0; i<10; i++)
    scanf("%f", &a[i]);

    printf("numbers in resever order :\n");
    for (i=9; i>=0;i--)
       printf("%3.4f\n",a[i]);


       return 0;
}
