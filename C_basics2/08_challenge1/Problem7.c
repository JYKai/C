#include <stdio.h>

int square(int num)
{
    if (num == 0) { return 1; }

    int temp = 1;
    int i;

    for (i = 1; i <= num; i++)
    {
        temp *= 2;
    }
    return temp;
}

int main(void)
{
    int n, start = 1;
    int kmax = 0;
    printf("상수 n 입력: ");
    scanf("%d", &n);

    while (square(start) <= n)
    {
        kmax = start++;
    }

    printf("공식을 만족하는 k의 최댓값은 %d \n", kmax);
    return 0;
}