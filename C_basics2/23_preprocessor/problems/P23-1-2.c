#include <stdio.h>

#define PI          3.1414
#define AREA(R)     ((R) * (R) * PI)

int main(void)
{
    double rad;
    printf("원의 반지름 입력 : ");
    scanf("%lf", &rad);
    printf("원의 넓이: %g \n", AREA(rad));
    return 0;
}