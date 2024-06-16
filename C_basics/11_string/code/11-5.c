// fgets 함수의 문자열 입력 방법

#include <stdio.h>
#include <string.h>


int main(void)
{
    char str[80];

    printf("공백이 포함된 문자열 입력 : ");         // 공백이 포함된 문자열 입력 : apple jam
    fgets(str, sizeof(str), stdin);

    str[strlen(str) - 1] = '\0';
    printf("입력된 문자열은 %s입니다.\n", str);    // 입력된 문자열은 apple jam입니다.

    return 0;
}