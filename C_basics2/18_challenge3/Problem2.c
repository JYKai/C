#include <stdio.h>

int check(int num, int row, int col, int direction, int (*pmove_arr)[2], int (*parr)[num])
{
    int next_r = row + pmove_arr[direction][0];
    int next_c = col + pmove_arr[direction][1];
    
    if (0 <= next_r && next_r < num &&
        0 <= next_c && next_c < num &&
        parr[next_r][next_c] == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void snail(int num)
{
    int arr[num][num];
    int direction = 0;
    int start_r = 0, start_c = 0;
    int move_arr[4][2] = {
        {0, 1},  // 우
        {1, 0},  // 하
        {0, -1}, // 좌
        {-1, 0}, // 상
    };

    int r, c, i;
    for (r = 0; r < num; r++)
    {
        for (c = 0; c < num; c++)
        {
            arr[r][c] = 0;
        }
    }

    for (i = 1; i <= num * num; i++)
    {
        arr[start_r][start_c] = i;
        if (check(num, start_r, start_c, direction, move_arr, arr))
        {
            start_r += move_arr[direction][0];
            start_c += move_arr[direction][1];
        }
        else
        {
            direction = (direction + 1) % 4;
            start_r += move_arr[direction][0];
            start_c += move_arr[direction][1];
        }
    }

    for (r = 0; r < num; r++)
    {
        for (c = 0; c < num; c++)
        {
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }
}

int main(void)
{
    int num;
    printf("숫자를 입력하시오 : ");
    scanf("%d", &num);

    snail(num);
    return 0;
}