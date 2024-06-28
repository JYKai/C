#include <stdio.h>

void MaxAndMin(int arr[], int len, int ** maxPtr, int ** minPtr);

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int len = 0;
    int *maxPtr, *minPtr;

    maxPtr = 0;
    minPtr = 0;

    MaxAndMin(arr, sizeof(arr)/sizeof(int), &maxPtr, &minPtr);

    printf("maxPtr, minPtr = %d, %d \n", *maxPtr, *minPtr);
    return 0;
}

void MaxAndMin(int arr[], int len, int ** maxPtr, int ** minPtr)
{
    int *max, *min;
    int i;

    max = min = &arr[0];
    for (i = 0; i < len; i++)
    {
        if (*(arr + i) > *max) { max = &arr[i]; }
        if (*(arr + i) < *min) { min = &arr[i]; }
    }

    *maxPtr = max;
    *minPtr = min;
}   