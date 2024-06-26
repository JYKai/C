#include <stdio.h>

int main(void)
{
    int arr[5] = {0};
    int i, min, max, total;

    for (i = 0; i < 5; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (i == 0)
        {
            min = temp;
            max = temp;
            total = temp;
        }
        else
        {
            if (min > temp) { min = temp; }
            if (max < temp) { max = temp; }
            total += temp;
        }
    }
    printf("입력된 정수 중에서 최댓값 = %d \n", max);
    printf("입력된 정수 중에서 최솟값 = %d \n", min);
    printf("입력된 정수의 총 합 = %d \n", total);

    return 0;
}