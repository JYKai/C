// 형 변환 연산자가 필요한 경우

#include <stdio.h>

int main(void)
{
    int a = 20, b = 3;
    double res;

    res = ((double)a) / ((double)b);
    printf("a = %d, b = %d\n", a, b);     // a = 20, b = 3
    printf("a / b의 결과 : %.1lf\n", res); // a / b의 결과 : 6.7

    a = (int)res;
    printf("(int) %.1lf의 결과 : %d\n", res, a); // (int) 6.7의 결과 : 6

    return 0;
}