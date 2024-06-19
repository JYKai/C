// 배열과 포인터를 멤버로 갖는 구조체 사용

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile
{
    char name[20];
    int age;
    double height;
    char *intro;
};

int main(void)
{
    struct profile yuni;

    strcpy(yuni.name, "김지윤");
    yuni.age = 30;
    yuni.height = 176.5;

    yuni.intro = (char *)malloc(80);
    printf("자기소개 : ");
    gets(yuni.intro);

    printf("이름 : %s\n", yuni.name);
    printf("나이 : %d\n", yuni.age);
    printf("키 : %.1lf\n", yuni.height);
    printf("자기소개 : %s\n", yuni.intro);

    free(yuni.intro);

    return 0;
}