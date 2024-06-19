// 5명의 나이를 저장할 배열을 선언하고 사용하는 방법

#include <stdio.h>

int main(void)
{
    int ary[5];

    ary[0] = 10;
    ary[1] = 20;
    ary[2] = ary[0] + ary[1];
    scanf("%d", &ary[3]);

    printf("%d\n", ary[2]);
    printf("%d\n", ary[3]);
    printf("%d\n", ary[4]); // 쓰레기 값

    return 0;
}