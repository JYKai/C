#include <stdio.h>

int main(void)
{
    int i = 0, total = 0;

    do
    {
        if (i % 2 == 0) {  total += i; }
        i++;
    } while (i <= 100);
    
    printf("total = %d", total);
    return 0;
}