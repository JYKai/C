#include <stdio.h>

int main()
{
    char num1 = 0;
    short num2 = 0;
    printf("%d\n", sizeof(num1) + sizeof(num2) + sizeof(long long));
 
    return 0;
}