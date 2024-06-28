#include <stdio.h>

int main(void)
{
    int arr[3][9] = {0};
    int i, j;
    int num = 2, cnt = 1;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 9; j++)
        {
            arr[i][j] = num * cnt;
            cnt++;
        }
        num++;
        cnt = 1;
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 9; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}