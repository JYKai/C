# 구조체와 사용자 정의 자료형

## 구조체란 무엇인가?

### 구조체의 정의
'구조체(structure)'라는 것은 하나 이상의 변수(포인터 변수와 배열 포함)를 묶어서 새로운 자료형을 정의하는 도구이다.

### 구조체 변수의 선언과 접근
```c
#include <stdio.h>
#include <math.h>

struct point
{
    int xpos;
    int ypos;
};

int main(void)
{
    struct point pos1, pos2;
    double distance;

    fputs("point1 pos: ", stdout);
    scanf("%d %d", &pos1.xpos, &pos1.ypos);

    fputs("point2 pos: ", stdout);
    scanf("%d %d", &pos2.xpos, &pos2.ypos);

    distance = sqrt((double)(pos1.xpos - pos2.xpos) * (pos1.xpos - pos2.xpos) + 
            (pos1.ypos - pos2.ypos) * (pos1.ypos - pos2.ypos));
    
    printf("두 점의 거리는 %g 입니다. \n", distance);
    return 0;
}
```

### 구조체 변수의 초기화
초기화 방법은 배열의 초기ㅗ하와 유사하다(동일하다). 즉 멤버의 순서대로 초기화할 대상을 나열하면 된다.
```c
#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
};

struct person
{
    char name[20];
    char phoneNum[20];
    int age;
};

int main(void)
{
    struct point pos = { 10, 20 };
    struct person man = { "김지윤", "010-1111-2222", 21};
    
    printf("%d %d \n", pos.xpos, pos.ypos);
    printf("%s %s %d \n", man.name, man.phoneNum, man.age);

    return 0;
}

```
- 초기화 과정에서는 문자열 저장을 위해서 strcpy 함수를 호출하지 않아도 된다.

</br>

## 구조체와 배열 그리고 포인터

### 구조체 배열의 선언과 접근
```c
#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
};

int main(void)
{
    struct point arr[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("점의 좌표 입력 : ");
        scanf("%d %d", &arr[i].xpos, &arr[i].ypos);
    }

    for (i = 0; i < 3; i++)
    {
        printf("[%d, %d] ", arr[i].xpos, arr[i].ypos);
    }

    return 0;
}

```
- 구조체 배열의 선언방법과 접근방법은 새로운 것이 아니다.

### 구조체 배열의 초기화
중괄호를 통해서 초기화할 값을 명시한다.
```c
#include <stdio.h>

struct person
{
    char name[20];
    char phoneNum[20];
    int age;
};

int main(void)
{
    struct person arr[2] = {
        {"이승기", "010-1111-2222", 21},
        {"정지영", "010-2222-3333", 24}
    };

    int i;
    for (i = 0; i < 2; i++)
    {
        printf("%s %s %d \n", arr[i].name, arr[i].phoneNum, arr[i].age);
    }

    return 0;
}

```

### 구조체 변수와 포인터
구조체 포인터 변수의 선언 및 연산의 방법도 일반적인 포인터 변수의 선언 및 연산의 방법과 다르지 않다.
```c
#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
};

int main(void)
{
    struct point pos1 = {1, 2};
    struct point pos2 = {100, 200};
    struct point *pptr = &pos1;

    (*pptr).xpos += 4;
    (*pptr).ypos += 5;
    printf("[%d, %d] \n", pptr->xpos, pptr->ypos);

    pptr = &pos2;
    pptr->xpos += 1;
    pptr->ypos += 2;
    printf("[%d, %d] \n", pptr->xpos, pptr->ypos);

    return 0;
}
```
- '->' 연산자의 사용에 익숙해지자.

### 포인터 변수를 구조체의 멤버로 선언하기
배열이 구조체의 멤버로 선언될 수 있듯이, 포인터 변수도 구조체의 멤버가 될 수 있다.
```c
#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
};

struct circle
{
    double radius;
    struct point * center;
};

int main(void)
{
    struct point cen = {2, 7};
    double rad = 5.5;

    struct circle ring = {rad, &cen};
    printf("원의 반지름: %g \n", ring.radius);
    printf("원의 중심 [%d, %d] \n", (ring.center)->xpos, (ring.center)->ypos);
    return 0;
}
```
- TYPE형 구조체 변수의 멤버로 TYPE형 포인터 변수를 둘 수 있다.
```c
#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
    struct point * ptr;
};

int main(void)
{
    struct point pos1 = {1, 1};
    struct point pos2 = {2, 2};
    struct point pos3 = {3, 3};

    pos1.ptr = &pos2;
    pos2.ptr = &pos3;
    pos3.ptr = &pos1;

    return 0;
}
```

### 구조체 변수의 주소 값과 첫 번째 멤버의 주소 값
구조체 변수의 주소 값은 구조체 변수의 첫 번째 멤버의 주소 값과 동일하다.

</br>

## 구조체의 정의와 typedef 선언

### typedef 선언
기존에 존재하는 자료형의 이름을 새 이름을 부여하는 것을 목적으로 하는 선언이다.
- 가장 마지막에 등장하는 단어를 중심으로 이뤄진다.
- 새롭게 정의되는 자료형의 이름은 대분자로 시작하는 것이 관레이다.
```c
#include <stdio.h>

typedef int INT;
typedef int * PTR_INT;

typedef unsigned int UINT;
typedef unsigned int * PTR_UINT;

typedef unsigned char UCHAR;
typedef unsigned char * PTR_UCHAR;

int main(void)
{
    INT num1 = 120;
    PTR_INT pnum1 = &num1;

    UINT num2 = 190;
    PTR_UINT pnum2 = &num2;

    UCHAR ch = 'Z';
    PTR_UCHAR pch = &ch;

    printf("%d, %u, %c \n", *pnum1, *pnum2, *pch);
    return 0;
}
```

### 구조체의 정의와 typedef 선언
```c
#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
};

typedef struct point Point;

typedef struct person
{
    char name[20];
    char phoneNum[20];
    int age;
} Person;
```

### 구조체의 이름 생략
```c
typedef struct person
{
    char name[20];
    char phoneNum[20];
    int age;
} Person;

typedef struct
{
    char name[20];
    char phoneNum[20];
    int age;
} Person;
```
- 프로그래머의 프로그래밍 성향에 따라서 구조체의 이름을 생략하는 경우도 흔하다. 생략할 수 있다는 것을 알고 있자.

</br>

## 함수로의 구조체 변수 전달과 반환

### 함수의 인자로 전달되고 return문에 의해 반환되는 구조체 변수
함수의 인자로 구조체 변수가 전달될 수 있으며, 이러한 인자를 전달받을 수 있도록 구조체 변수가 매개변수의 선언으로 올 수 있다.
- 전달되는 구조체 변수의 값은 매개변수에 통째로 복사가 된다.
```c
#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

void ShowPosition(Point pos)
{
    printf("[%d, %d] \n", pos.xpos, pos.ypos);
}

Point GetCurrentPosition(void)
{
    Point cen;
    printf("Input current pos: ");
    scanf("%d %d", &cen.xpos, &cen.ypos);
    return cen;
}

int main(void)
{
    Point curPos = GetCurrentPosition();
    ShowPosition(curPos);
    return 0;
}
```
- 구조체의 멤버로 배열이 선언되어도 복사가 진행된다.
```c
#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

void OrgSymTrans(Point * ptr)
{
    ptr->xpos = (ptr->xpos) * -1;
    ptr->ypos = (ptr->ypos) * -1;
}

void ShowPosition(Point pos)
{
    printf("[%d, %d] \n", pos.xpos, pos.ypos);
}

int main(void)
{
    Point pos = {7, -5};
    OrgSymTrans(&pos);
    ShowPosition(pos);
    OrgSymTrans(&pos);
    ShowPosition(pos);

    return 0;
}
```
- 구조체 변수를 대상으로 하는 Call-by-reference

### 구조체 변수를 대상으로 가능한 연산
구조체 변수를 대상으로는 매우 제한된 형태의 연산만 허용이 된다.
- 대입연산
- 주소값 반환을 위한 &연산
- 크기를 반환하는 sizeof 연산
```c
#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

int main(void)
{
    Point pos1 = {1, 2};
    Point pos2;
    pos2 = pos1;

    printf("크기 : %lu \n", sizeof(pos1));
    printf("[%d, %d] \n", pos1.xpos, pos1.ypos);
    
    printf("크기 : %lu \n", sizeof(pos2));
    printf("[%d, %d] \n", pos2.xpos, pos2.ypos);

    return 0;
}
```
- 구조체 변수간 대입연산의 결과로 멤버 대 멤버의 복사가 이뤄진다.
- 구조체 변수를 대상으로 덧셈이나 뺄셈을 하려면 함수를 따로 정의해야한다.
```c
#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

Point AddPoint(Point pos1, Point pos2)
{
    Point pos = {pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos};
    return pos;
}

Point MinPoint(Point pos1, Point pos2)
{
    Point pos = {pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos};
    return pos;
}

int main(void)
{
    Point pos1 = {5, 2};
    Point pos2 = {2, 9};
    Point result;

    result = AddPoint(pos1, pos2);
    printf("[%d, %d] \n", result.xpos, result.ypos);
    
    result = MinPoint(pos1, pos2);
    printf("[%d, %d] \n", result.xpos, result.ypos);

    return 0;
}
```

</br>

## 구조체의 유용함에 대한 논의와 중첩 구조체

### 구조체를 정의하는 이유
구조체를 통해서 연관 있는 데이터를 하나로 묶을 수 있는 자료형을 정의하면, 데이터의 표현 및 관리가 용이해지고, 그만큼 합리적인 코드를 작성할 수 있게 된다.
```c
#include <stdio.h>

typedef struct student
{
    char name[20];
    char stdnum[20];
    char school[20];
    char major[20];
    int year;
} Student;

void ShowStudentInfo(Student * sptr)
{
    printf("학생 이름 : %s \n", sptr->name);
    printf("학생 고유번호 : %s \n", sptr->stdnum);
    printf("학교 이름 : %s \n", sptr->school);
    printf("선택 전공 : %s \n", sptr->major);
    printf("학년 : %d \n", sptr->year);
}

int main(void)
{
    Student arr[7];
    int i;

    for (i = 0; i < 7; i++)
    {
        printf("이름: "); scanf("%s", arr[i].name);
        printf("번호: "); scanf("%s", arr[i].stdnum);
        printf("학교: "); scanf("%s", arr[i].school);
        printf("전공: "); scanf("%s", arr[i].major);
        printf("학년: "); scanf("%s", &arr[i].year);
    }

    for (i = 0; i < 7; i++)
        ShowStudentInfo(&arr[i]);
    
    return 0;
}
```

### 중첩된 구조체의 정의와 변수의 선언
구조체 변수도 구조체의 멤버로 선언될 수 있다.
```c
#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

typedef struct Circle
{
    Point cen;
    double radius;
} Circle;

void ShowCircleInfo(Circle *cptr)
{
    printf("[%d, %d] \n", (cptr->cen).xpos, (cptr->cen).ypos);
    printf("radius = %g \n", cptr->radius);
}

int main(void)
{
    Circle c1 = {{1, 2}, 3.5};
    Circle c2 = {2, 4, 3.9};

    ShowCircleInfo(&c1);
    ShowCircleInfo(&c2);

    return 0;
}
```
- 중괄호를 이용해서 구조체 변수의 초기화를 구분 짓지 않으면, 순서대로 초기화 된다.
- 구조체 변수를 초기화하는 경우에도 배열의 초기화와 마찬가지로 초기화하지 않은 일부 멤버에 대해서는 0으로 초기화 된다.

</br>

## 공용체(Union Type)의 정의와 의미

### 구조체 vs. 공용체
```c
#include <stdio.h>

typedef struct sbox
{
    int mem1;
    int mem2;
    double mem3;
} SBox;

typedef union ubox
{
    int mem1;
    int mem2;
    double mem3;
} UBox;

int main(void)
{
    SBox sbx;
    UBox ubx;

    printf("%p %p %p \n", &sbx.mem1, &sbx.mem2, &sbx.mem3);
    printf("%p %p %p \n", &ubx.mem1, &ubx.mem2, &ubx.mem3);
    printf("%d %d \n", sizeof(sbx), sizeof(ubx));

    return 0;
}
```
- 구조체 변수가 선언되면, 구조체를 구성하는 멤버는 각각 할당이 된다.
- 공용체 변수가 선언되면, 공용체를 구성하는 멤버는 각각 할당되지 않고, 그 중 크기가 가장 큰 멤버의 변수만 하나 할당되어 이를 공유하게 된다.

### 공용체의 유용함은 다양한 접근방식을 제공하는데 있습니다.
```c
#include <stdio.h>

typedef struct dbshort
{
    unsigned short upper;
    unsigned short lower;
} DBShort;

typedef union rdbuf
{
    int iBuf;
    char bBuf[4];
    DBShort sBuf;
} RDBuf;

int main(void)
{
    RDBuf buf;
    printf("정수 입력: ");
    scanf("%d", &(buf.iBuf));

    printf("상위 2바이트: %u \n", buf.sBuf.upper);
    printf("하위 2바이트: %u \n", buf.sBuf.lower);
    printf("상위 1바이트 아스키 코드: %c \n", buf.bBuf[0]);
    printf("하위 1바이트 아스키 코드: %c \n", buf.bBuf[3]);

    return 0;
}
```
- 공용체의 적절한 정의를 통해 4바이트 메모리 공간을 나눠서 접근할 수 있다.

</br>

## 열거형(Enumerated Type)의 정의와 의미

### 열거형의 정의와 변수의 선언
변수에 저장이 가능한 값들을 열거하여 정의한다고 해서 '열거형'이라고 한다.
```c
enum syllable       // syllable 이라는 이름의 열거형 정의
{
    Do=1, Re=2, Mi=3, Fa=4, So=5, La=6, Ti=7
}
```
- Do를 정수 1을 의미하는 상수로 정의한다. 그리고 이 값은 syllable형 변수에 저장이 가능하다.
```c
#include <stdio.h>

typedef enum syllable
{
    Do=1, Re=2, Mi=3, Fa=4, So=5, La=6, Ti=7
} Syllable;

void Sound(Syllable sy)
{
    switch(sy)
    {
    case Do:
        puts("도는 하얀 도라지 ~"); return;
    case Re:
        puts("레는 둥근 레코드 ~"); return;
    case Mi:
        puts("미는 파란 미나리 ~"); return;
    case Fa:
        puts("파는 파란 미나리 ~"); return;
    case So:
        puts("솔은 작은 솔방울 ~"); return;
    case La:
        puts("라는 라디오고요 ~"); return;
    case Ti:
        puts("시는 졸졸 시냇물 ~"); return;
    }
    puts("다 함께 부르세~ 도레미파 솔라시도 솔 도~ 짠~");
}

int main(void)
{
    Syllable tone;
    for (tone = Do; tone <= Ti; tone++) { Sound(tone); }
    return 0;
}
```
- 열거형 상수들은 int형으로 표현되는 상수이다.

### 열거형 상수의 값이 결정되는 방식
열거형 상수의 이름만 선언되어 있으면 상수의 값은 0부터 시작된다.
- 값이 설정되어 있으면 그 값을 시작으로 1씩 증가된 값이 할당된다.

### 열거형의 유용함은 이름있는 상수의 정의를 통한 의미의 부여에 있습니다.
열거형의 유용함은 둘 이상의 연관이 있는 이름을 상수로 선언함으로써 프로그램의 가독성을 높이는데 있다.