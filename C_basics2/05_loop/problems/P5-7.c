#include <stdio.h>

int main(void)
{
    int num, total = 0;
    printf("정수 입력(0 to quit): ");
    scanf("%d", &num);
    total += num;

    while (num != 0)
    {
        printf("정수 입력(0 to quit): ");
        scanf("%d", &num);
        total += num;
    }

    printf("합계: %d \n", total);
    return 0;
}