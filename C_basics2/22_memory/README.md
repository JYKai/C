# 메모리 관리와 메모리의 동적 할당

## C언어의 메모리 구조

### 메모리 영역별로 저장되는 데이터 유형

**코드 영역(Code Area)**  
실행할 프로그램의 코드가 저장되는 메모리 공간이다.

**데이터 영역(Data Area)**  
전역변수와 static으로 선언되는 static 변수가 할당된다.
- 이 영역에 할당되는 변수들은 프로그램의 시작과 동시에 메모리 공간에 할당되어 프로그램 종료 시까지 남아있게 된다.

**스택 영역(Stack Area)**  
지역변수와 매개변수가 할당된다.
- 선언된 함수를 빠져나가면 소멸된다는 특징이 있다.

**힙 영역(Heap Area)**  
C언어에서는 프로그래머가 원하는 시점에 변수를 할당하고 또 소멸하도록 지원을 하는데, 그러한 유형의 변수들이 할당되는 영역이다.

</br>

## 메모리의 동적 할당

### 힙 영역의 메모리 공간 할당과 해제: malloc과 free 함수
```c
#include <stdlib.h>
void * malloc(size_t size);     // 힙 영역으로의 메모리 공간 할당
void free(void * ptr);          // 힙 영역에 할당된 메모리 공간 해제
```
- ```malloc``` 함수는 성공 시 할당된 메모리의 주소 값, 실패 시 NULL 반환

### malloc 함수의 반환형이 void형 포인터인 이유와 힙 영역으로의 접근
원하는 크기만큼 메모리 공간을 할당하고 그 메모리의 주소 값을 반환한다. 이후 어떻게 사용할지는 포인터 형의 변환을 통해 직접 결정한다.
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int * ptr1 = (int *)malloc(sizeof(int));
    int * ptr2 = (int *)malloc(sizeof(int) * 7);
    int i;

    *ptr1 = 20;
    for (i = 0; i < 7; i++) { ptr2[i] = i + 1; }

    printf("%d \n", *ptr1);
    for (i = 0; i < 7; i++) { printf("%d ", ptr2[i]); }

    free(ptr1);
    free(ptr2);

    return 0;
}
```
- 동적 할당이라고 불리는 이유는 할당되는 메모리의 크기를 컴파일러가 결정하기 않고, 프로그램의 실행 중간에 호출되는 ```malloc``` 함수가 결정하기 때문이다.

### free 함수를 호출하지 않으면 프로그램 종료 후에도 메모리가 남게 되나요?
프로그램 실행 시 할당된 모든 메모리 공간은 프로그램이 종료되면 운영체제에 의해서 전부 해제된다.

### 문자열을 반환하는 함수를 정의하는 문제의 해결
함수가 호출될 때마다 문자열 저장을 위한 메모리 공간의 할당이 가능해야 하고, 이 메모리 공간은 함수를 빠져나가도 소멸되지 않고 존재해야 한다.

```c
#include <stdio.h>
#include <stdlib.h>

char * ReadUserName(void)
{
    char * name = (char *)malloc(sizeof(char) * 30);
    printf("What's your name? ");
    gets(name);
    return name;
}

int main(void)
{
    char * name1;
    char * name2;

    name1 = ReadUserName();
    printf("name1: %s \n", name1);

    name2 = ReadUserName();
    printf("name2: %s \n", name2);

    printf("again name1: %s \n", name1);
    printf("again name2: %s \n", name2);

    free(name1);
    free(name2);

    return 0;
}
```

### malloc 함수의 사촌 뻘 되는 calloc 함수
```c
#include <stdlib.h>
void * calloc(size_t elt_count, size_t elt_size);
```
- 성공 시 할당된 메모리의 주소 값, 실패 시 NULL 반환
- 첫 번째 전달인자 : 할당할 블록의 갯수 정보
- 두 번째 전달인자 : 하나당 바이트 크기 정보
- 할당된 메모리 공간을 별도의 값으로 초기화하지 않는 ```malloc``` 함수와 달리, ```calloc``` 함수는 할당된 메모리 공간의 모든 비트를 0으로 초기화시킨다.

### 힙에 할당된 메모리 공간 확장 시 호출하는 realloc 함수
```c
#include <stdlib.h>
void * realloc(void * ptr, size_t size);
```
- 성공 시 새로 할당된 메모리의 주소 값, 실패 시 NULL 반환
- ptr가 가리키는 메모리의 크기를 size 크기로 조절한다.