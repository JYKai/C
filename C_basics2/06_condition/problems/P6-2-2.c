#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (i + j == 9 && j + i == 9)
            {
                printf("i = %d, j = %d \n", i, j);
            }
        }
    }

    return 0;
}