#include <stdio.h>

int main(void)
{
    int num1 = 7, num2 = 13;
    printf("%o %#o \n", num1, num2);    // 7 015 
    printf("%x %#x \n", num1, num2);    // 7 0xd

    return 0;
}