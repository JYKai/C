// 허용되지 않는 포인터의 대입

#include <stdio.h>

int main(void)
{
    int a = 10;
    int *p = &a;
    double *pd;

    pd = p;
    printf("%lf\n", *pd); // 0.000000

    return 0;
}