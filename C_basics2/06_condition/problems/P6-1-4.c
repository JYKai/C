#include <stdio.h>

int main(void)
{
    int i, j;
    int diff;
    scanf("%d %d", &i, &j);

    diff = i > j ? i - j : j - i;
    printf("두 값의 차이 = %d\n", diff);

    return 0;
}