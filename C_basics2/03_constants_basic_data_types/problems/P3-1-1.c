#include <stdio.h>

int main(void)
{
    int lx, ly;
    int rx, ry;
    scanf("%d %d %d %d", &lx, &ly, &rx, &ry);

    printf("두 점이 이루는 직사각형의 넓이는 %d입니다.\n", (rx - lx) * (ry - ly));
    return 0;
}