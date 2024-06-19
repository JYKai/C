// 자기 참조 구조체로 list 만들기

#include <stdio.h>

struct list
{
    int num;
    struct list *next;  // 구조체 자신을 가리키는 포인트 멤버
};

int main(void)
{
    struct list a = {10, 0}, b = {20 ,0}, c = {30, 0};
    struct list *head = &a, *current;

    a.next = &b;
    b.next = &c;

    printf("head -> num: %d\n", head -> num);           // head가 가리키는 a의 num 멤버 사용
    printf("head -> next -> num : %d\n", head -> next -> num);  // head로 b의 num 멤버 사용

    printf("list all : ");
    current = head;     // 최초 current 포인터가 a를 가리킴
    
    while (current != NULL)
    {
        printf("%d  ", current -> num);     // current가 가리키는 구조체 변수의 num 출력
        current = current -> next;
    }

    printf("\n");

    return 0;
}