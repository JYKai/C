// 개행 문자로 인해 gets 함수가 입력을 못하는 경우

#include <stdio.h>

int main(void)
{
    int age;
    char name[20];

    printf("나이 입력 : "); // 나이 입력 : 30
    scanf("%d", &age);

    fgetc(stdin);

    printf("이름 입력 : ");
    gets(name);
    printf("나이 : %d, 이름 : %s\n", age, name);    // 나이 : 30, 이름 : 김지윤

    return 0;
}