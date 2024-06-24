#include <stdio.h>

int main(void)
{
    int i, j;
    scanf("%d %d", &i, &j);

    if (i > j) { printf("두 정수의 차이 = %d\n", i - j); }
    else { printf("두 정수의 차이 = %d\n", j - i); }

    return 0;
}