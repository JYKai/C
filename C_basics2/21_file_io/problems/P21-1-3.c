#include <stdio.h>

int main(void)
{
    char str[100];
    FILE *fp = fopen("mystory.txt", "rt");

    while ((fgets(str, sizeof(str), fp)) != NULL)
        printf("%s", str);
    fclose(fp);
    return 0;
}