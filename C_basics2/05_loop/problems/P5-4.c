#include <stdio.h>

int main(void)
{
    int num, i = 9;
    printf("구구단을 위한 숫자를 입력하세요 : ");
    scanf("%d", &num);

    while (i > 0)
    {
        printf("%d x %d = %d\n", num, i, num * i);
        i--;
    }
    
    return 0;
}