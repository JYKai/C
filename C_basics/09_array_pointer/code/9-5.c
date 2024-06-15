// 배열을 처리하는 함수

#include <stdio.h>

void print_ary(int *pa, int count);

int main(void)
{
    int ary[5] = { 10, 20, 30, 40, 50 };
    int count = sizeof(ary) / sizeof(ary[0]);
    print_ary(ary, count);

    return 0;
}

void print_ary(int *pa, int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        printf("%d ", pa[i]);
    }
}