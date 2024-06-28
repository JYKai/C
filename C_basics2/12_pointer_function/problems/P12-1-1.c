#include <stdio.h>

int SquareByValue(int);
void SquareByReference(int*);

int main(void)
{
    int num, snum;
    scanf("%d", &num);

    snum = SquareByValue(num);
    SquareByReference(&num);

    printf("SquareByValue result = %d \n", snum);
    printf("SquareByReference result = %d \n", num);

    return 0;
}

int SquareByValue(int num)
{
    return (num * num);
}
void SquareByReference(int *num)
{
    *num *= (*num);
}