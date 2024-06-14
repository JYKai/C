// 복합대입 연산자

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    int res = 2;

    a += 20;
    res *= b + 10;

    printf("a = %d, b = %d\n", a, b); // a = 30, b = 20
    printf("res = %d\n", res); // res = 60

    return 0;
}