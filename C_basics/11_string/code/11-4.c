// gets 함수로 한 줄의 문자열 입력

#include <stdio.h>

int main(void)
{
    char str[80];

    printf("공백이 포함된 문자열 입력 : ");     // 공백이 포함된 문자열 입력 : apple jam
    gets(str);
    printf("입력한 문자열은 %s입니다.", str);  // 입력한 문자열은 apple jam입니다.

    return 0;
}