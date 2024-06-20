#include <stdio.h>

int main(void)
{
    int num, temp;
    int count = 0, total = 0;
    double avg;

    printf("입력하고 싶은 정수의 개수를 입력하세요 : ");
    scanf("%d", &num);

    while (count < num)
    {
        scanf("%d", &temp);
        total += temp;
        count++;
    }

    avg = total / (double)num;
    printf("평균: %lf", avg);

    return 0;
}