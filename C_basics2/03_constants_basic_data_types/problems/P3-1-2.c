#include <stdio.h>

int main(void)
{
    double f1, f2;
    printf("두 실수를 입력하세요 : ");
    scanf("%lf %lf", &f1, &f2);

    printf("두 실수의 덧셈 = %.1lf\n", f1 + f2);
    printf("두 실수의 뺄셈 = %.1lf\n", f1 - f2);
    printf("두 실수의 곱셈 = %.1lf\n", f1 * f2);
    printf("두 실수의 나눗셈 = %.1lf\n", f1 / f2);

    return 0;
}