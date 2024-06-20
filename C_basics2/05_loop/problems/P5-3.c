#include <stdio.h>

int main(void)
{
    int num, sum = 0;
    printf("더하고 싶은 양의 정수를 입력하세요(0 입력 시 종료) : ");
    scanf("%d", &num);

    while (num != 0)
    {
        sum += num;
        printf("더하고 싶은 양의 정수를 입력하세요(0 입력 시 종료) : ");
        scanf("%d", &num);
    }

    printf("sum = %d \n", sum);
    return 0;
}