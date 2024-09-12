#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int duplicate(int num, int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

int get_strike(int my_arr[], int comp_arr[], int size)
{
    int strike = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (my_arr[i] == comp_arr[i])
        {
            strike++;
        }
    }
    
    return strike;
}

int get_ball(int my_arr[], int comp_arr[], int size)
{
    int ball = 0;
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i != j && my_arr[i] == comp_arr[j])
            {
                ball++;
            }
        }
    }
    return ball;
}

int main()
{
    printf("Start Game!\n");
    srand((unsigned int)time(NULL));

    int arr[3] = { -1, -1, -1 };
    int i; 

    for (i = 0; i < 3; i++)
    {
        while (1)
        {
            int temp = rand() % 10;
            if (!duplicate(temp, arr, i))
            {
                arr[i] = temp;
                break;
            }
        }
    }

    int count = 1;
    while (1)
    {   
        int my_arr[3];
        int strike, ball;

        printf("3개의 숫자 선택 (0 ~ 9): ");
        scanf("%d %d %d", &my_arr[0], &my_arr[1], &my_arr[2]);

        strike = get_strike(my_arr, arr, 3);
        ball = get_ball(my_arr, arr, 3);

        printf("%d번째 도전 결과: %dstrike, %dball!! \n", count, strike, ball);
        count++;
        
        if (strike == 3)
            break;
    }

    printf("Game Over!");
    return 0;
}