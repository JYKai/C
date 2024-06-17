// 2개 반 3명의 학생과 4과목 점수를 저장하는 3차원 배열

#include <stdio.h>

int main(void)
{
    int score[2][3][4] = {
        { { 72, 80, 95, 60}, {86, 21, 44, 53}, {23, 76, 88, 98} },
        { { 71, 10, 35, 40}, {56, 61, 47, 58}, {93, 26, 38, 48} }
    };

    int i, j, k;

    for (i = 0; i < 2; i++)
    {
        printf("%d반의 점수...\n", i + 1);
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                printf("%5d", score[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}