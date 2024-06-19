// 여러 개의 1차원 배열을 2차원 배열처럼 사용

#include <stdio.h>

int main(void)
{
    int ary1[4] = { 1, 2, 3, 4 };
    int ary2[4] = { 11, 12, 13, 14 };
    int ary3[4] = { 21, 22, 23, 24 };
    int *pary[3] = { ary1, ary2, ary3 };
    
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pary[i][j]);
        }
        printf("\n");
    }

    return 0;
}