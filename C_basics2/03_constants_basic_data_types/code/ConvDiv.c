#include <stdio.h>

int main(void)
{
    int num1 = 3, num2 = 4;
    double divResult;
    divResult = (double)num1 / num2;

    printf("나눗셈 결과 = %.1lf \n", divResult); // 0.8
    return 0;
}