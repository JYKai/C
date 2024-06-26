#include <stdio.h>

int main(void)
{
    char voca[100];
    int i, len = 0;
    char temp;

    scanf("%s", voca);

    while (voca[len] != 0) { len++; }   // 길이 확인
    
    for (i = 0; i < len/2; i++)
    {
        temp = voca[i];
        voca[i] = voca[(len - i) - 1];
        voca[(len - i) - 1] = temp;
    }

    printf("%s \n", voca);
    return 0;
}