#include <stdio.h>

int main(void)
{
    int n1 = 1, n2 = 2;
    int n3 = 3, n4 = 4, n5 = 5, n6 = 6;
    int * arr1[2] = { &n1, &n2 };
    int * arr2[2][2] = { &n3, &n4, &n5, &n6 };

    int ** darr1 = arr1;
    int* (*darr2)[2] = arr2;    // arr2가 가리키는 것은 int * 이고, 가로길이 = 5 이므로

    int i, j;

    for (i = 0; i < 5; i++)
    {
        printf("%d ", *darr1[i]);
    }
    printf("\n");

    return 0;
}