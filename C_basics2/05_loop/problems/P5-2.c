#include <stdio.h>

int main(void)
{
    int num, count = 1;
    printf("양의 정수를 입력하시오 : ");
    scanf("%d", &num);

    while (count <= num)
    {
        printf("%d ", 3 * count);
        count++;
    }

    return 0;
}