#include <stdio.h>

void printEven(int *nums, int len);
void printOdd(int *nums, int len);

int main(void)
{
    int arr[10];
    int i, len;
    int *aptr = arr;
    len = sizeof(arr) / sizeof(int);

    printf("총 10개의 숫자 입력\n");
    for (i = 0; i < 10; i++)
    {
        printf("입력: ");
        scanf("%d", &arr[i]);
    }
    printOdd(aptr, len);
    printEven(aptr, len);

    return 0;
}

void printEven(int *nums, int len)
{
    int i;
    printf("홀수 출력: ");
    for (i = 0; i < len; i++)
    {
        if (nums[i] % 2 != 0) { printf("%d, ", nums[i]); }
    }
}
void printOdd(int *nums, int len)
{
    int i;
    printf("짝수 출력: ");
    for (i = 0; i < len; i++)
    {
        if (nums[i] % 2 == 0) { printf("%d, ", nums[i]); }
    }
}