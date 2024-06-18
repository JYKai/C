// 구조체 포인터 사용

#include <stdio.h>

struct score
{
    int kor;
    int eng;
    int math;
};

int main(void)
{
    struct score yun = { 90, 80, 100 };
    struct score *ps = &yun;

    printf("국어 : %d\n", (*ps).kor);
    printf("영어 : %d\n", ps -> eng);
    printf("수학 : %d\n", ps -> math);

    return 0;
}