#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int rarr[6] = {0};
    int *ptr = &arr[5];
    int i;

    for (i = 0; i < 6; i++)
    {
        rarr[i] = *(ptr - i);
        printf("rarr[%d] = %d \n", i, rarr[i]);
    }

    return 0;
}