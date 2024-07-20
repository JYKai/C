#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("mystory.txt", "wt");
    if (fp == NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }

    fputs("#이름: 김지윤 \n", fp);
    fputs("#주민번호: 941222-1111111 \n", fp);
    fputs("#전화번호: 010-1111-2222 \n", fp);
    fclose(fp);
    return 0;
}