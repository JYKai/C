#include <stdio.h>

int main(void)
{
    int i;
    for (i = 1; i <= 100; i++)
    {
        if (i % 7 == 0 || i % 9 == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}