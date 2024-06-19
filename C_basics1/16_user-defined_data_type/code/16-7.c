// 함수에서 -> 연산자를 사용하여 구조체 배열의 값 출력

#include <stdio.h>

struct address
{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

void print_list(struct address *lp);

int main(void)
{
    struct address list[3] = {
        {"홍길동", 23, "111-1111", "울릉도 독도"},
        {"이순신", 35, "111-2222", "서울 건청동"},
        {"장보고", 18, "333-1111", "완도 청해진"}
    };

    print_list(list);

    return 0;
}

void print_list(struct address *lp)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("%10s%5d%15s%20s\n", (lp + i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr);
    }
}