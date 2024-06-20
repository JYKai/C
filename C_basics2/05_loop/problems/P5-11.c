#include <stdio.h>

int main(void)
{
    int num, result;
    int count = 0;
    printf("양의 정수를 입력하세요 : ");
    scanf("%d", &num);

    for (result = 1; num > 0; num--)
    {
        result *= num;
        count++;
    }

    printf("%d! = %d \n", count, result);
}