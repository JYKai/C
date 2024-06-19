// 중첩된 if문

#include <stdio.h>

int main(void)
{
    int a = 20, b = 10;

    if (a > 10)
    {
        if (b >= 0)
        {
            b = 1;
        }
        else
        {
            b = -1;
        }
    }

    printf("b = %d\n", b);
    return 0;
}