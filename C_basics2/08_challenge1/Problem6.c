#include <stdio.h>

int main(void)
{
    int second;
    int h = 0, m = 0, s = 0;
    printf("초(second) 입력: ");
    scanf("%d", &second);

    while (second > 0)
    {
        if (second >= 3600)
        {
            int temp = 0;
            temp = second / 3600;
            h += temp;
            second -= (temp * 3600) ;
        }

        else if (second >= 60)
        {
            int temp = 0;
            temp = second / 60;
            m += temp;
            second -= (temp * 60);
        }

        else
        {
            s += second;
            second = 0;
        }
    }
    printf("[h: %d, m: %d, s: %d]", h, m, s);
    return 0;
}