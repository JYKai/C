#include <stdio.h>

int main(void)
{
    int scores[5][5] = {0};
    int i, j, temp;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("점수를 입력하세요: ");
            scanf("%d", &scores[i][j]);
        }
    }

    for (i = 0; i < 4; i++)
    {
        temp = 0;
        for (j = 0; j < 5; j++)
        {
            if (j == 4){ scores[i][j] = temp; }
            else { temp += scores[i][j]; }
        }
    }

    for (i = 0; i < 4; i++)
    {
        temp = 0;
        for (j = 0; j < 5; j++)
        {
            if (j == 4){ scores[j][i] = temp; }
            else { temp += scores[j][i]; }
        }
    }

    temp = 0;
    for (i = 0; i < 5; i++)
    {
        if (i == 4){ scores[4][i] = temp; }
        else { temp += scores[4][i]; }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}