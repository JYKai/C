#include <stdio.h>

int main(void)
{
    int count = 0, start = 2;
    while (count < 10)
    {
        int i, check = 0;
        for (i = 1; i <= start; i++)
        {
            if (start % i == 0) { check += 1; }
        }
        if (check == 2)
        {
            count += 1;
            printf("%d ", start);
        }
        start++;
    }

}