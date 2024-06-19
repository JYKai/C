// 최고 학점의 학생 데이터 출력

#include <stdio.h>

struct student
{
    int id;
    char name[20];
    double grade;
};

int main(void)
{
    struct student s1 = { 315, "홍길동", 2.4 },
                   s2 = { 316, "이순신", 3.7 },
                   s3 = { 317, "세종대왕", 4.4 };

    struct student max;

    max = s1;
    if (max.grade < s2.grade) { max = s2; }
    if (max.grade < s3.grade) { max = s3; }

    printf("학번 : %d\n", max.id);          // 학번 : 317
    printf("이름 : %s\n", max.name);        // 이름 : 세종대왕
    printf("학점 : %.1lf\n", max.grade);    // 학점 : 4.4

    return 0;
}