// 구조체 배열을 초기화하고 출력

#include <stdio.h>

struct address
{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

int main(void)
{
    struct address list[3] = {
        {"홍길동", 23, "111-1111", "울릉도 독도"},
        {"이순신", 35, "111-2222", "서울 건청동"},
        {"장보고", 18, "333-1111", "완도 청해진"}
    };

    int i;

    for (i = 0; i < 3; i++)
    {
        printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
    }

    return 0;
}