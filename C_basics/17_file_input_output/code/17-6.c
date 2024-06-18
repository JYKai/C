// 여러 줄의 문장을 입력하여 한 줄로 출력

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *ifp, *ofp;
    char str[80];                   // 입력한 문자열을 저장할 배열
    char *res;                      // fgets 함수의 반환값을 저장할 변수

    ifp = fopen("../data/a.txt", "r");
    if (ifp == NULL)
    {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    ofp = fopen("../data/b.txt", "w");
    if (ofp == NULL)
    {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    while (1)
    {
        res = fgets(str, sizeof(str), ifp);
        if (res == NULL) { break; }
        str[strlen(str) - 1] = '\0';        // 개행 문자 제거
        fputs(str, ofp);
        fputs(" ", ofp);
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}