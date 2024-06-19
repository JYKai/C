// 비트 연산식의 결과

#include <stdio.h>

int main(void)
{
    int a = 10; // 비트열 00000000 00000000 00000000 00001010
    int b = 12; // 비트열 00000000 00000000 00000000 00001100

    printf("a & b : %d\n", a & b);  // a & b : 8
    printf("a ^ b : %d\n", a ^ b);  // a ^ b : 6
    printf("a | b : %d\n", a | b);  // a | b : 14
    printf("~a : %d\n", ~a);        // ~a : -11
    printf("a << 1 : %d\n", a << 1); // a << 1 : 20
    printf("a >> 2 : %d\n", a >> 2); // a >> 2 : 2

    return 0;
}