// 주소를 반환하여 두 정수의 합 계산

#include <stdio.h>

int *sum(int a, int b);

int main(void)
{
    int *resp;

    resp = sum(10, 20);
    printf("두 정수의 합 : %d\n", *resp);

    return 0;
}

int *sum(int a, int b)
{
    static int res;

    res = a + b;

    return &res;
}