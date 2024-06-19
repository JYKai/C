// scanf 함수를 사용한 문자열 입력

#include <stdio.h>

int main(void)
{
    char str[80];

    printf("문자열 입력 : ");
    scanf("%s", str);                               // 문자열 입력 : apple jam
    printf("첫 번째 단어 : %s\n", str);                // 첫 번째 단어 : apple
    scanf("%s", str);
    printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str);   // 버퍼에 남아 있는 두 번째 단어 : jam

    return 0;
}