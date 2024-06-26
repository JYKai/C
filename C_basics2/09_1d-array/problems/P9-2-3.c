#include <stdio.h>

int main(void)
{
    char word[100];
    int len = 0, i;
    char max = 0;

    scanf("%s", word);

    while (word[len] != '\0') { len++; }

    for (i = 0; i < len; i++)
    {
        if (max < word[i]) { max = word[i]; }
    }

    printf("%c \n", max);
    return 0;
}