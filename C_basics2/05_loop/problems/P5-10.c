#include <stdio.h>

int main(void)
{
    int num1, num2;
    int sum = 0;
    printf("두 정수를 입력하세요 : ");
    scanf("%d %d", &num1, &num2);

    for (num1; num1 <= num2; num1++)
    {
        sum += num1;
    }

    printf("sum = %d", sum);
    return 0;
}