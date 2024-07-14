#include <stdio.h>

void Rotate90(int (*arr)[4])
{
    int arr2[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr2[j][3 - i] = arr[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = arr2[i][j];
        }
    }
}

void ShowArray(int (*arr)[4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int arr[4][4];

    for (int i = 0; i < 16; i++)
    {
        arr[i / 4][i % 4] = i + 1;
    }

    printf("Before Turn\n");
    ShowArray(arr);

    Rotate90(arr);
    printf("First Turn\n");
    ShowArray(arr);

    Rotate90(arr);
    printf("Second Turn\n");
    ShowArray(arr);

    Rotate90(arr);
    printf("Third Turn\n");
    ShowArray(arr);

    Rotate90(arr);
    printf("Forth Turn\n");
    ShowArray(arr);

    return 0;
}   