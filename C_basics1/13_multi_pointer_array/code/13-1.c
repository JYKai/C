// 학생 3명과 네 과목 총점과 평균을 구하는 프로그램

#include <stdio.h>

int main(void)
{
    int score[3][4];                // 3명과 네 과목 점수를 저장할 2차원 배열 선언
    int total;
    double avg;
    int i, j;

    for (i = 0; i < 3; i++)
    {
        printf("4과목의 점수 입력 : ");
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &score[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        total = 0;
        for (j = 0; j < 4; j++)
        {
            total += score[i][j];
        }
        avg = total / 4.0;
        printf("총점 : %d, 평균 : %.1lf\n", total, avg);
    }

    return 0;
}