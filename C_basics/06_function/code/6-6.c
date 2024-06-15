// 3번 실행되는 재귀호출 함수

#include <stdio.h>

void fruit(int count);

int main(void)
{
    fruit(1);

    return 0;
}

void fruit(int count)
{
    printf("apple\n");
    if (count == 3) { return; }
    fruit(count + 1);
}