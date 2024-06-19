// 포인터 배열로 여러 개 문자열 출력

#include <stdio.h>

int main(void)
{
    char *pary[5];          // 포인터 배열 선언. pointer와 array의 약어로 pary
    int i;

    pary[0] = "dog";
    pary[1] = "elephant";
    pary[2] = "horse";
    pary[3] = "tiger";
    pary[4] = "lion";

    for (i = 0; i < 5; i++) { printf("%s\n", pary[i]); }

    return 0;
}