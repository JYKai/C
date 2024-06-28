#include <stdio.h>

void Swap3(int*, int*, int*);

int main(void)
{
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);

    Swap3(&num1, &num2, &num3);
    printf("%d %d %d \n", num1, num2, num3);

    return 0;
}

void Swap3(int *num1, int *num2, int *num3)
{
    int temp1, temp2;
    temp1 = *num1;
    *num1 = *num2;
    *num2 = *num3;
    *num3 = temp1;
}