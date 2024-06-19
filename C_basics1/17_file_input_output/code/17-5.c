// a+ 모드로 파일의 내옹을 확인하며 출력

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char str[20];

    fp = fopen("../data/a.txt", "a+");
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    while (1)
    {
        printf("과일 이름 : ");
        scanf("%s", str);
        if (strcmp(str, "end") == 0) { break; }
        else if (strcmp(str, "list") == 0)  // list를 입력하면 파일의 내용 확인
        {
            fseek(fp, 0, SEEK_SET);         // 버퍼의 위치 지시자를 맨 처음으로 이동
            while (1)
            {
                fgets(str, sizeof(str), fp);    // 과일 이름을 읽는다.
                if (feof(fp))                   // 파일의 내용을 모두 읽으면 종료
                {
                    break;
                }
                printf("%s", str);              // 읽은 과일 이름을 화면 출력
            }
        }
        else { fprintf(fp, "%s\n", str);}       // 입력한 과일 이름을 파일에 출력
    }
    fclose(fp);

    return 0;
}