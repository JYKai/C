// 공용체를 사용한 학번과 학점 데이터 처리

#include <stdio.h>

union student
{
    int num;
    double grade;
};

int main(void)
{
    union student s1 = { 315 };

    printf("학번 : %d\n", s1.num);          // 학번 : 315
    s1.grade = 4.4;
    printf("학점 : %.1lf\n", s1.grade);     // 학점 : 4.4
    printf("학번 : %d\n", s1.num);          // 학번 : -1717986918

    return 0;
}