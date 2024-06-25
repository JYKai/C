#include <stdio.h>

int compare_max_integers(int, int, int);
int compare_min_integers(int, int, int);

int main(void)
{
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("셋 중에 가장 큰 수 = %d\n", compare_max_integers(num1, num2, num3));
    printf("셋 중에 가장 작은 수 = %d\n", compare_min_integers(num1, num2, num3));

    return 0;
}

int compare_max_integers(int num1, int num2, int num3)
{
    int max1 = num1;
    int max2;
    int final;

    if (num2 > num3) { max2 = num2; }
    else { max2 = num3; }

    if (max1 > max2) { final = max1; }
    else { final = max2; }

    return final;
}

int compare_min_integers(int num1, int num2, int num3)
{
    int min1 = num1;
    int min2;
    int final;

    if (num2 > num3) { min2 = num3; }
    else { min2 = num2; }

    if (min1 > min2) { final = min2; }
    else { final = min1; }

    return final;
}