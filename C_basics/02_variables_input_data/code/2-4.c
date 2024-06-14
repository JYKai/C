// unsigned를 잘못 사용한 경우

#include <stdio.h>

int main(void)
{
    unsigned int a;

    a = 4294967295;
    printf("%d\n", a); // -1
    a = -1;
    printf("%u\n", a); // 4294967295

    return 0;
}