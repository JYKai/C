#include <stdio.h>

int main(void)
{
    int num, cnt = 0;
    char binary[50];

    printf("10진수 정수 입력: ");
    scanf("%d", &num);

    if (num == 0) { printf("%d", num); }

    while (num > 0)
    {
        binary[cnt++] = num % 2;
        num /= 2;
    }

    while (cnt > 0)
    {
        printf("%d", binary[--cnt]);
    }
    
    return 0;
}