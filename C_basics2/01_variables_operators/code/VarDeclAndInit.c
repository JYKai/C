#include <stdio.h>

int main(void)
{
    int num1, num2;
    int num3 = 30, num4 = 40;

    printf("num1 : %d, num2 : %d \n", num1, num2);  // num1 : 18062224, num2 : 1 
    num1 = 10;
    num2 = 20;

    printf("num1 : %d, num2 : %d \n", num1, num2);  // num1 : 10, num2 : 20 
    printf("num3 : %d, num4 : %d \n", num3, num4);  // num3 : 30, num4 : 40 

    return 0;
}