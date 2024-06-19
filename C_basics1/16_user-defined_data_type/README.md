# 사용자 정의 자료형

## 구조체
구조체는 다양한 자료형을 하나로 묶을 수 있는 복합 자료형으로 다양한 데이터를 처리할 때 기본으로 사용된다.

### 구조체 선언과 멤버 사용
변수를 선언하기 전에 구조체의 형태를 컴파일러에 미리 알려주는 구조체 선언을 해야한다.
```c
// 구조체를 선언하고 멤버를 사용하는 방법

#include <stdio.h>

struct student
{
    int num;
    double grade;
};

int main(void)
{
    struct student s1;

    s1.num = 2;
    s1.grade = 2.7;
    printf("학번 : %d\n", s1.num);         // 학번 : 2
    printf("학점 : %.1lf\n", s1.grade);    // 학점 : 2.7

    return 0;
}
```
- ```struct student```
    - struct : 예약어
    - student : 구조체 이름
- 멤버 선언은 구조체를 구성하는 자료형 종류와 이름을 컴파일러에 알리는 것이며 실제 저장 공간이 할당되는 변수 선언과는 다르다.
- 구조체 선언이 main 함수 앞에 있으면 프로그램 전체에서 사용할 수 있고, 함수 안에 선언하면 그 함수 안에서만 사용할 수 있다.
- 구조체 변수를 선언하면 비로소 저장 공간이 할당된다.
    - 각 멤버의 공간이 메모리에 연속으로 할당되며 모든 멤버를 더한 전체 저장 공간이 하나의 구조체 변수가 되므로 변수의 크기는 각 멤버의 크기를 더한 값이 된다.
- 구조체 변수는 사용할 멤버에 접근할 때 멤버 접근 연산자 . 를 사용한다.

**구조체 변수의 크기**  
- 컴파일러는 구조체 멤버의 크기가 들쑥날쑥한 경우 멤버 사이에 패딩 바이트를 넣어 멤버를 정렬한다. = 바이트 얼라인먼트
    - 일반적으로 크기가 가장 큰 멤버가 메모리를 할당하는 기준 단위가 된다.
- 기준 블록 내에서 크기가 작은 멤버들은 각 자료형의 크기 단위로 할당된다.
    - 결국 멤버의 순서에 따라 구조체의 크기가 달라질 수 있으므로 패딩 바이트가 가장 작도록 구조체를 선언하면 메모리를 아낄 수 있다.
    - ```#pragma pack(1); // 바이트 얼라인먼트를 1로 설정하면 패딩 바이트가 필요 없음```
        - 데이터를 읽고 쓰는 시간은 더 걸릴 수 있지만 구조체의 크기는 모든 멤버의 크기를 더한 것과 같아지므로 사용하는 메모리의 크기는 최소화할 수 있다.
        - 구조체 선언 전에 적어주며, 보통 include 다음에 넣어준다.
- 임베디드 소프트웨어처럼 메모리 크기가 중요한 프로그램을 작성할 때는 꼭 메모리를 최소화할 방법을 고민하도록 한다.


### 다양한 구조체 멤버
```c
// 배열과 포인터를 멤버로 갖는 구조체 사용

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile
{
    char name[20];
    int age;
    double height;
    char *intro;
};

int main(void)
{
    struct profile yuni;

    strcpy(yuni.name, "김지윤");
    yuni.age = 30;
    yuni.height = 176.5;

    yuni.intro = (char *)malloc(80);
    printf("자기소개 : ");
    gets(yuni.intro);

    printf("이름 : %s\n", yuni.name);
    printf("나이 : %d\n", yuni.age);
    printf("키 : %.1lf\n", yuni.height);
    printf("자기소개 : %s\n", yuni.intro);

    free(yuni.intro);

    return 0;
}
```
- 구조체의 멤버로 다른 구조체를 사용할 수 있으며 . 를 통해 접근할 수 있다.


### 구조체 변수의 초기화와 대입 연산
일반 변수와 같이 선언과 동시에 초기화할 수 있다.
- 초깃값을 중괄호로 묶고 각 멤버의 형태에 맞는 값으로 초기화한다.
```c
// 최고 학점의 학생 데이터 출력

#include <stdio.h>

struct student
{
    int id;
    char name[20];
    double grade;
};

int main(void)
{
    struct student s1 = { 315, "홍길동", 2.4 },
                   s2 = { 316, "이순신", 3.7 },
                   s3 = { 317, "세종대왕", 4.4 };

    struct student max;

    max = s1;       // 대입 연산으로 복사
    if (max.grade < s2.grade) { max = s2; }
    if (max.grade < s3.grade) { max = s3; }

    printf("학번 : %d\n", max.id);          // 학번 : 317
    printf("이름 : %s\n", max.name);        // 이름 : 세종대왕
    printf("학점 : %.1lf\n", max.grade);    // 학점 : 4.4

    return 0;
}
```


### 구조체 변수를 함수 매개변수에 사용하기
구조체 변수를 사용해 값을 주고받으면 포인터 없이도 두 변수의 값을 바꾸는 함수를 만들 수 있다.
```c
// 구조체를 반환하여 두 변수의 값 교환

#include <stdio.h>

struct vision
{
    double left;
    double right;
};


struct vision exchange(struct vision robot);

int main(void)
{
    struct vision robot;

    printf("시력 입력 : ");     // 시력 입력 : 15.5 20.0
    scanf("%lf%lf", &(robot.left), &(robot.right));

    robot = exchange(robot);  // 바뀐 시력 : 20.0, 15.5
    printf("바뀐 시력 : %.1lf, %.1lf\n", robot.left, robot.right);

    return 0;
}

struct vision exchange(struct vision robot)
{
    double temp;

    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;

    return robot;
}
```
- 함수를 호출할 때 인수로 구조체 변수를 사용하면 멤버들의 값을 한번에 함수에 줄 수 있다.
- 멤버가 배열이라도 모든 배열 요소의 값이 함수에 복사된다.
- ```struct vision exchange(struct vision robot)```
    - 매개변수와 반환형 모두 구조체
- ```scanf("%lf%lf", &(robot.left), &(robot.right));```
    - 멤버 접근 연산자 . 는 주소 연산자보다 우선순위가 높으므로 괄호가 없어도 멤버에 먼저 접근하고 주소 연산을 수행할 수 있다.

</br>

## 구조체 활용, 공용체, 열거형

### 구조체 포인터와 -> 연산자
구조체 변수는 그 안에 여러 개의 변수를 멤버로 가질 수 있으나, 그 자신은 단지 하나의 변수이다.
- 구조체 변수에 주소 연산자를 사용하면 특정 멤버의 주소가 아니라 구조체 변수 전체의 주소가 구해진다. 그 값을 저장할 때 구조체 포인터를 사용한다.
```c
// 구조체 포인터 사용

#include <stdio.h>

struct score
{
    int kor;
    int eng;
    int math;
};

int main(void)
{
    struct score yun = { 90, 80, 100 };
    struct score *ps = &yun;

    printf("국어 : %d\n", (*ps).kor);
    printf("영어 : %d\n", ps -> eng);
    printf("수학 : %d\n", ps -> math);

    return 0;
}
```
- ```(*ps).kor```
    - 멤버에 접근하는 . 연산자가 * 연산자보다 우선순위가 높으므로 구조체 포인터 ps를 괄호로 묶어야 한다.
- ```ps -> eng```
    - ->(간접 멤버 접근 연산자) 연산자를 사용하여 멤버를 쉽게 사용할 수 있다.


### 구조체 배열
```c
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
```


### 구조체 배열을 처리하는 함수
구조체 배열의 이름을 인수로 받는 함수는 구조체 포인터를 매개변수로 선언한다.
```c
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
```
- 배열명 list는 첫 번째 요소의 주소로 struct address 구조체 변수를 가리킨다.
    - 포인터가 배열명을 저장하면 배열명처럼 사용할 수 있으므로, 매개변수 lp로 각 배열 요소를 참조하고 멤버들을 출력할 수 있다.


### 자기 참조 구조체
개별적으로 할당된 구조체 변수들을 포인터로 연결하면 관련된 데이터를 하나로 묶어 관리할 수 있으며, 이때 자기 참조 구조체를 사용한다.
- 자기 참조 구조체는 자신의 구조체를 가리키는 포인터를 멤버로 가진다.
```c
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
```
- 구조체 변수를 포인터로 연결한 것을 연결 리스트라고 한다.
    - 첫 번째 변수의 위치만 알면 나머지 변수는 포인터를 따라가 모두 사용할 수 있다.
- head 포인터의 값을 바꾸면 다시 처음 위치를 찾아갈 수 없으므로 항상 연결 리스트의 시작 위치를 기억하도록 그 값을 바꾸지 않는 것이 좋다.


### 공용체
구조체와 선언 방식이 비슷하지만 공용체는 모든 멤버가 하나의 저장 공간을 같이 사용한다.
```c
// 공용체를 사용한 학번과 학점 데이터 처리

#include <stdio.h>

union student
{
    int num;
    double grade;
};

int main(void)
{
    union student s1 = { 315 };

    printf("학번 : %d\n", s1.num);          // 학번 : 315
    s1.grade = 4.4;
    printf("학점 : %.1lf\n", s1.grade);     // 학점 : 4.4
    printf("학번 : %d\n", s1.num);          // 학번 : -1717986918

    return 0;
}
```
- 공용체 변수의 크기는 멤버 중에서 크기가 가장 큰 멤버로 결정된다.
    - 위의 예시에서 double형 멤버의 크기인 8바이트의 저장 공간이 할당되고 num과 grade가 하나의 공간을 공유한다.
- 공용체는 저장 공간을 공유하는 점 외에 구조체와 특별히 다르지 않다.
- 공용체 변수의 초기화는 중괄호를 사용하여 첫 번째 멤버만 초기화한다.
    - 첫 번째 멤버가 아닌 멤버를 초기화할 때는 멤버 접근 연산자 . 로 멤버를 직접 지정해야 한다.
        - ```union student a = { .grade = 3.4 };```
- 공용체 멤버는 언제든지 다른 멤버에 의해 값이 변할 수 있으므로 항상 각 멤버의 값을 확인해야 하는 단점이 있다.
- 여러 멤버가 하나의 저장 공간을 공유하므로 메모리를 절약할 수 있고, 같은 공간에 저장된 값을 여러 가지 형태로 사용할 수 있는 장점이 있다.


### 열거형
열거형은 변수에 저장할 수 있는 정수 값을 기호로 정의하여 나열한다.
```c
// 열거형을 사용한 프로그램

#include <stdio.h>

enum season {SPRING, SUMMER, FALL, WINTER};

int main(void)
{
    enum season ss;
    char *pc = NULL;

    ss = SPRING;
    switch (ss)
    {
    case SPRING:
        pc = "inline"; break;
    case SUMMER:
        pc = "swimming"; break;
    case FALL:
        pc = "trip"; break;
    case WINTER:
        pc = "skiing"; break;
    }
    printf("나의 레저 활동 => %s\n", pc);   // 나의 레저 활동 => inline

    return 0;
}
```
- 컴파일러는 멤버를 0부터 차례로 하나씩 큰 정수로 바꿔준다.
    - SPRING = 0, SUMMER = 1, FALL = 2, WINTER = 3
- 값이 새로 설정된 멤버 이후의 멤버들은 설정된 멤버보다 하나씩 큰 정수로 바뀐다.
    - ```enum season {SPRING = 5, SUMMER, FALL = 10, WINTER};```
        - SUMMER = 6, WINTER = 11
- 열거형 멤버는 정수로 바뀌므로 사실상 정수 상수를 써서 작성할 수 있지만, 열거형을 통해 계절 이름을 직접 사용할 수 있으므로 가독성이 좋은 코드를 만들 수 있다.


### typedef를 사용한 형 재정의
```typedef```를 사용하면 자료형 이름에서 struct와 같은 예약어를 생략할 수 있다.
```c
// typedef를 사용한 자료형 재정의

#include <stdio.h>

struct student
{
    int num;
    double grade;
};

typedef struct student Student;
void print_data(Student *ps);

int main(void)
{
    Student s1 = { 315, 4.2 };
    print_data(&s1);
    return 0;
}

void print_data(Student *ps)
{
    printf("학번 : %d\n", ps -> num);
    printf("학점 : %.1lf\n", ps -> grade);
}
```
- ```typedef 구조체_이름 새_자료형_이름```
- 재정의하기 전에 이름도 함께 사용할 수 있다.
```c
typedef struct
{
    int num;
    double grade;
} Student;
```