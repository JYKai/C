// switch ~ case문의 사용

#include <stdio.h>

int main(void)
{
    int rank, m = 0;
    printf("rank를 입력하세요(정수): ");
    scanf("%d", &rank);

    switch (rank)
    {
        case 1:
            m = 300;
            break;
        case 2:
            m = 200;
            break;
        case 3:
            m = 100;
            break;
        default:
            m = 10;
            break;
    }

    printf("m : %d\n", m);
    return 0;
}