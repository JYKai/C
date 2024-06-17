// 여러 개의 동물 이름을 입출력하는 프로그램

#include <stdio.h>

int main(void)
{
    char animal[5][20];     // 2차원 char 배열 선언
    int i;
    int count;

    count = sizeof(animal) / sizeof(animal[0]);
    for (i = 0; i < count; i++)
    {
        scanf("%s", animal[i]);
    }

    for (i = 0; i < count; i++)
    {
        printf("%s\t", animal[i]);
    }

    return 0;
}