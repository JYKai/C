// 포인터의 선언과 사용

#include <stdio.h>

int main(void)
{
    int a;
    int *pa;

    pa = &a;
    *pa = 10; // 포인터로 변수 a에 10 대입

    printf("포인터로 a 값 출력 : %d\n", *pa);
    printf("변수명으로 a 값 출력 : %d\n", a);

    return 0;
}