#include <stdio.h>

int recursive(int num, int under)
{
    if (num == 0) { return under; }
    int temp = recursive(num - 1, under * 2);
    return temp;
}

int main(void)
{
    int num, total = 0;
    printf("정수 입력 : ");
    scanf("%d", &num);

    total = recursive(num, 1);
    printf("2의 %d승은 %d \n", num, total);

    return 0;
}