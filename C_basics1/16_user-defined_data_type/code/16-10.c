// 열거형을 사용한 프로그램

#include <stdio.h>

enum season {SPRING, SUMMER, FALL, WINTER};

int main(void)
{
    enum season ss;
    char *pc = NULL;

    ss = SPRING;
    switch (ss)
    {
    case SPRING:
        pc = "inline"; break;
    case SUMMER:
        pc = "swimming"; break;
    case FALL:
        pc = "trip"; break;
    case WINTER:
        pc = "skiing"; break;
    }
    printf("나의 레저 활동 => %s\n", pc);   // 나의 레저 활동 => inline

    return 0;
}