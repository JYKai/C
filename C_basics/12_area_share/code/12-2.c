// auto 지역 변수와 static 지역 변수의 비교

#include <stdio.h>

void auto_func(void);
void static_func(void);

int main(void)
{
    int i;

    printf("일반 지역 변수(auto)를 사용한 함수...\n");
    for (i = 0; i < 3; i++)
    {
        auto_func();
    } // 1 1 1

    printf("정적 지역 변수(static)를 사용한 함수...\n");
    for (i = 0; i < 3; i++)
    {
        static_func();
    } // 1 2 3

    return 0;
}

void auto_func(void)
{
    auto int a = 0;

    a++;
    printf("%d\n", a);
}

void static_func(void)
{
    static int a = 0;

    a++;
    printf("%d\n", a);
}