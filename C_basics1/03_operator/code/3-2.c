// 증감 연산자의 연산

#include <stdio.h>

int main(void)
{
    int a = 10, b = 10;

    ++a;
    --b;

    printf("%d\n", a); // 11
    printf("%d\n", b); // 9

    return 0;
}