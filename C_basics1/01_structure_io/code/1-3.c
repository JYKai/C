// 정수와 실수 출력

#include <stdio.h>

int main(void)
{
    printf("%d\n", 10);
    printf("%lf\n", 3.14);
    printf("%.1lf\n", 3.45);
    printf("%.10lf\n", 3.4);

    printf("%d와 %d의 합흔 %d입니다.\n", 10, 20, 10 + 20);
    printf("%.1lf - %.1lf = %.1lf\n", 3.4, 2.3, 3.4 - 2.3);

    return 0;
}