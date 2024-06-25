#include <stdio.h>

int main(void)
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    if (num1 < num2)
    {
        for (; num1 <= num2; num1++)
        {
            int i = 1;
            while (i < 10)
            {
                printf("%d x %d = %d \n", num1, i, num1 * i);
                i++;
            }
        }
    }
    else
    {
        for (; num2 <= num1; num2++)
        {
            int i = 1;
            while (i < 10)
            {
                printf("%d x %d = %d \n", num2, i, num2 * i);
                i++;
            }
        }
    }

    return 0;
}