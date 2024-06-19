// 파일의 형태와 개방 모드가 다른 경우

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int ary[10] = { 13, 10, 13, 13, 10, 23, 23, 33, 31, 12};
    int i, res;

    fp = fopen("../data/c.txt", "wb");      // 바이너리 파일로 개방
    for (i = 0; i < 10; i++) { fputc(ary[i], fp);}
    fclose(fp);

    fp = fopen("../data/c.txt", "rt");      // 같은 파일을 텍스트 파일로 개방
    while (1)
    {
        res = fgetc(fp);
        if (res == EOF) { break; }
        printf("%4d", res);
    }
    fclose(fp);

    return 0;
}