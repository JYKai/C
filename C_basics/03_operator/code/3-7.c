// 콤마 연산자

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    int res;

    res = (++a, ++b);
    
    printf("a: %d, b: %d\n", a, b); // a: 11, b: 21
    printf("res: %d\n", res); // res: 21

    return 0;
}