// fprintf와 fwrite 함수의 차이

#include <stdio.h>

int main(void)
{
    FILE *afp, *bfp;
    int num = 10;
    int res;

    afp = fopen("../data/g.txt", "wt");
    fprintf(afp, "%d", "num");

    bfp = fopen("../data/h.txt", "wb");
    fwrite(&num, sizeof(num), 1, bfp);

    fclose(afp);
    fclose(bfp);

    bfp = fopen("../data/h.txt", "rb");
    fread(&res, sizeof(res), 1, bfp);
    printf("%d", res);

    fclose(bfp);

    return 0;
}