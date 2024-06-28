#include <stdio.h>

int strLen(char *);
void isPalindrome(char *, int);

int main(void)
{
    char str[50];
    int len;
    printf("문자열 입력: ");
    scanf("%s", str);

    len = strLen(str);
    isPalindrome(str, len);

    return 0;
}

int strLen(char * str)
{
    int count = 0;
    while (str[count] != '\0') { count++; }
    return count;
}

void isPalindrome(char * str, int len)
{
    int i;
    for (i = 0; i < (len / 2); i++)
    {
        if (str[i] != str[len - i - 1])
        {
            printf("회문이 아니다.\n");
            return;
        }
    }
    printf("회문 입니다.\n");
}