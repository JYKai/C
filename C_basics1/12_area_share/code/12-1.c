// 블록 안에서 지역 변수를 사용하여 두 변수를 교환하는 프로그램

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;

    printf("교환 전 a와 b의 값 : %d, %d\n", a, b);  // 교환 전 a와 b의 값 : 10, 20
    {
        int temp;

        temp = a;
        a = b;
        b = temp;
    }
    printf("교환 후 a와 b의 값 : %d, %d\n", a, b);  // 교환 후 a와 b의 값 : 20, 10

    return 0;
}