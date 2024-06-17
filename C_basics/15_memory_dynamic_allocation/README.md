# 메모리 동적 할당

## 동적 할당 함수

### malloc, free 함수
- ```malloc``` : 프로그램 실행 중에 메모리를 동적 할당 in ```stdlib.h```
    - 주어진 인수의 바이트 크기만큼 메모리에서 연속된 저장 공간을 할당한 후에 그 시작 주소를 반환한다.
    - 함수 원형 : ```void *malloc(unsigned int size);```
- ```free``` : 반환할 때 사용 in ```stdlib.h```
    - 함수 원형 : ```void free(void *p)```
```c
// 동적 할당한 저장 공간을 사용하는 프로그램

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;    // 동적 할당 영역을 연결할 포인터 선언
    double *pd;

    pi = (int *)malloc(sizeof(int));        // 메모리 동적 할당 후 포인터 연결
    if (pi == NULL)                         // 동적 할당에 실패하면 NULL 포인터 반환
    {
        printf("# 메모리가 부족합니다.\n");
        exit(1);                            // 프로그램 종료
    }
    pd = (double *)malloc(sizeof(double));

    *pi = 10;
    *pd = 3.4;

    printf("정수형으로 사용 : %d\n", *pi);
    printf("실수형으로 사용 : %.1lf\n", *pd);

    free(pi);
    free(pd);

    return 0;
}
```
- ```pi = (int *)malloc(sizeof(int));```
    - malloc(sizeof(int)) : 저장 공간을 할당하고 (void *)형 반환
        - sizeof(int) : int형 변수의 크기
    - (int *) : 반환되는 주소를 int형 변수의 주소로 형 변환
    - pi : int형을 가리키는 포인터에 저장
- ```exit(1)```
    - ```main``` 함수뿐만 아니라 어떤 함수에서든 프로그램을 바로 종료할 수 있으며 예외 상황이 발생하여 프로그램을 바로 종료하는 경우 인수로 1을 주고 호출한다.

**주의 사항**  
1. ```malloc``` 함수의 반환값이 널 포인트인지 반드시 확인하고 사용해야 한다.
    - 메모리 할당 함수는 원하는 크기의 공간을 할당하지 못하면 널 포인터를 반환한다.
    - 널 포인터는 포인터의 특별한 상태를 나타내기 위해 사용하므로 간접 참조 연산을 할 수 없다.

2. 사용이 끝난 저장 공간은 재활용할 수 있도록 반환해야 한다.
    - 동적으로 할당한 저장 공간은 함수가 반환된 후에도 그대로 메모리에 남아있다.
    - 동적으로 할당한 저장 공간은 해당 프로그램이 종료될 때 운영체제에 의해서 자동으로 회수되어 다른 프로그램이 실행될 때 재활용된다.


### 동적 할당 영역을 배열처럼 쓰기
많은 저장 공간을 한꺼번에 동적 할당하여 배열처럼 사용한다.
- 저장 공간의 시작 위치만 포인터에 저장하면 포인터를 배열처럼 쓸 수 있다.
```c
// 동적 할당 영역을 배열처럼 사용

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;
    int i, sum = 0;

    pi = (int *)malloc(5 * sizeof(int));        // 저장 공간 20바이트 할당
    if (pi == NULL)
    {
        printf("메모리가 부족합니다.\n");
        exit(1);
    }
    printf("다섯 명의 나이를 입력하세요 : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &pi[i]);
        sum += pi[i];
    }
    printf("다섯 명의 평균 나이 : %.1lf\n", (sum / 5.0));
    free(pi);

    return 0;
}
```


### 기타 동적 할당 함수
- ```calloc(배열 요소의 개수, 변수 하나의 바이트 크기)``` : 할당한 저장 공간을 0으로 초기화
    - 함수 원형 : ```void *calloc(unsigned int, unsigned int)```
- ```realloc(이미 할당한 저장 공간의 포인터, 재할당 후 전체 저장 공간의 크기)``` : 처음 예측한 크기가 너무 크거나 작을 때, 함수의 크기를 조절한다.
    - 함수 원형 : ```void *realloc(void *, unsigned int)```
    - 첫 번째 인수가 널 포인터인 경우에는 ```malloc``` 함수와 같은 기능을 수행하여 두 번째 인수의 크기만큼 동적 할당하고 그 주소를 반환한다.
```c
// calloc, realloc 함수를 사용한 양수 입력

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;
    int size = 5;
    int count = 0;

    int num, i;
    pi = (int *)calloc(size, sizeof(int));
    
    while (1)
    {
        printf("양수만 입력하세요 => ");
        scanf("%d", &num);
        if (num < 0) { break; }
        if (count == size)
        {
            size += 5;
            pi = (int *)realloc(pi, size * sizeof(int));
        }
        pi[count++] = num;
    }

    for (int i = 0; i < count; i++) { printf("%5d", pi[i]); }
    free(pi);

    return 0;
}
```
- 이미 사용하던 저장 공간의 위치를 포인터가 기억하고 있더라도 재할당 과정에서 메모리의 위치가 바뀔 수 있으므로 항상 ```realloc``` 함수가 반환한 주소를 다시 포인터에 저장해 사용하는 것이 좋다.

### 프로그램이 사용하는 메모리 영역과 특징

**기억 분류(storage class)**  
- 코드 영역 : 프로그램이 올라가는 영역
- 데이터 영역 : 데이터가 저장되는 영역
    - 스택 영역 : 지역 변수들이 할당되는 영역
    - 힙 영역 : 동적 할당되는 영역
        - 프로그램이 종료될 때까지 메모리에 존재한다.
        - 주소만 알면 특정 함수에 구애받지 않고 어디서나 사용할 수 있다.
        - 지역 변수와 달리 동적 할당된 저장 공간은 함수가 반환되어도 메모리가 회수되지 않는다.
        - 메모리의 사용과 반환이 불규칙적이기 때문에 사용 가능한 영역이 조각나서 흩어져 있을 수 있어 저장 공간이 넉넉히 남아 있어도 메모리 할당 함수들이 널 포인터를 반환할 수 있다.
    - 기타 데이터 영역 : 전역 변수, 정적 변수 영역

</br>

## 동적 할당 저장 공간의 활용
저장 하기 위한 각 단어의 길이가 달라 메모리 공간 낭비가 발생이 우려될 때 동적 할당을 통해 각 단어의 길이만큼만 메모리를 확보하고 처리할 수 있다.

### 동적 할당을 사용한 문자열 처리
입력할 문자열의 길이를 알 수 없는 경우 무조건 큰 배열을 선언하는 것은 저장 공간의 낭비를 초래할 수 있다.
```c
// 3개의 문자열을 저장하기 위한 동적 할당

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char temp[80];
    char *str[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("문자열을 입력하세요 : ");
        gets(temp);
        str[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(str[i], temp);
    }

    for (i = 0; i < 3; i++) { printf("%s\n", str[i]); }
    for (i = 0; i < 3; i++) { free(str[i]); }

    return 0;
}
```

### 동적 할당 영역에 저장한 문자열을 함수로 처리하는 예
```c
// 동적 할당 영역의 문자열을 함수로 출력

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char **ps);

int main(void)
{
    char temp[80];
    char *str[21] = { 0 };
    int i = 0;

    while (i < 20)
    {
        printf("문지열을 입력하세요 : ");
        gets(temp);
        if (strcmp(temp, "end") == 0) { break; }
        str[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(str[i], temp);
        i++;
    }
    print_str(str);

    for (i = 0; str[i] != NULL; i++) { free(str[i]); }

    return 0;
}

void print_str(char **ps)
{
    while (*ps != NULL)
    {
        printf("%s\n", *ps);
        ps++;
    }
}
```
- 포인터나 포인터 배열을 auto 지역변수로 선언하면 쓰레기 값이 주소로 존재한다.
- 포인터 배열은 선언과 동시에 널 포인터로 초기화하고 참조할 때 널 포인터인지를 검사하면 더 안정적인 프로그래밍이 가능하다.
    - 최소한 포인터 배열의 마지막 요소는 널 포인터의 자리로 남겨둬야 한다.


### main 함수의 명령행 인수 사용
명령행에서 프로그램을 실행시킬 때 프로그램의 이름 외에도 프로그램에 필요한 정보를 함께 줄 수 있는데 이들을 모두 명령행 인수(command line argument)라고 한다.
```c
// 명령행 인수를 출력하는 프로그램

#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    for (i = 0; i < argc; i++) { printf("%s\n", argv[i]); }

    return 0;
}
```
- 매개변수의 이름은 임의로 작성할 수 있으나 관례적으로 argc(argument count), argv(argument vector)를 사용한다.