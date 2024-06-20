#include <stdio.h>

int main(void)
{
    int num, count = 0;
    printf("반복하고 싶은 양의 정수를 입력하시오 : ");
    scanf("%d", &num);

    while (count < num)
    {
        printf("Hello world!\n");
        count++;
    }

    return 0;
}