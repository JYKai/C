#include <stdio.h>

int main(void)
{
    int i = 1;
    int j = 1;

    while (i < 10)
    {
        if (i % 2 != 0)
        { 
            i++;
            continue; 
        }
        
        while (j < 10)
        {
            printf("%d x %d = %d\n", i, j, j * j);
            if (j == i)
            {
                j = 1;
                break;
            }
            j++;
        }
        i++;
    }

    return 0;
}