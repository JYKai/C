#include <stdio.h>

int main(void)
{
    int arr[10] = {0};
    int i;
    int lp = 0, rp = 9;
    printf("총 10개의 숫자 입력\n");
    
    for (i = 0; i < 10; i++)
    {
        int temp;
        printf("입력: ");
        scanf("%d", &temp);

        if (temp % 2 == 0) { arr[rp--] = temp; }
        else { arr[lp++] = temp; }
    }

    printf("배열 요소의 출력 : ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}