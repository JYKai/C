// 버퍼를 공유함으로 인해 발생하는 문제

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int age;
    char name[20];

    fp = fopen("../data/f.txt", "r");

    fscanf(fp, "%d", &age);
    fgets(name, sizeof(name), fp);

    printf("나이 : %d, 이름 : %s", age, name); // 나이 : 17, 이름 : 
    fclose(fp);

    return 0;
}