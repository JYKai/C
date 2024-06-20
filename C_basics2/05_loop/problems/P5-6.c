#include <stdio.h>

int main(void)
{
    int num, count = 0;

    while (count < 5)
    {
        printf("1 이상의 정수를 입력하세요 : ");
        scanf("%d", &num);
        
        if (num < 1)
        {
            printf("1 이상의 정수를 다시 입력하세요 : ");
            scanf("%d", &num);
        }
        else
        {
            ++count;
        }
    }

    printf("%d개의 정수를 입력 완료하였습니다.\n", count);
    return 0;
}