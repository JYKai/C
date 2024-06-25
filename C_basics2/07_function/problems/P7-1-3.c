#include <stdio.h>

void fibo(int);

int main(void)
{
    int num;
    scanf("%d", &num);

    fibo(num);

    return 0;
}

void fibo(int num)
{
    int f1 = 0, f2 = 1, f3, i;
    if (num == 1) { printf("%d ", f1); }
    else { printf("%d %d ", f1, f2); }

    for (i = 0; i < num - 2; i++)
    {
        f3 = f1 + f2;
        printf("%d ", f3);
        f1 = f2;
        f2 = f3;
    }
}