# 문자열

## 문자열과 포인터
컴파일 과정에서 문자열은 첫 번째 문자의 주소로 둔갑하고 그 이후는 배열을 출력하는 것과 같은 과정을 거친다.

### 문자열 상수 구현 방법
컴파일 과정에서 문자열을 char 배열 형태로 따로 보관하고 문자열 상수가 있는 곳에는 배열의 위치 값을 사용한다.
```c
// 문자열 상수가 주소란 증거

#include <stdio.h>

int main(void)
{
    printf("apple이 지정된 시작 주소 값 : %p\n", "apple");  // apple이 지정된 시작 주소 값 : 0x100d1bf1f
    printf("두 번째 문자의 주소 값 : %p\n", "apple" + 1);   // 두 번째 문자의 주소 값 : 0x100d1bf20
    printf("첫 번째 문자 : %c\n", *"apple");              // 첫 번째 문자 : a
    printf("두 번째 문자 : %c\n", *("apple" + 1));        // 두 번째 문자 : p
    printf("배열로 표현한 세 번째 문자 : %c\n", "apple"[2]);  // 배열로 표현한 세 번째 문자 : p

    return 0;
}
```
- 문자열은 컴파일 과정에서 char 변수의 주소로 바뀌는 것을 확인할 수 있다. 이를 통해, 직접 포인터 연산을 수행할 수 있다.
    - 단, 주소로 접근하여 문자열을 바꿔서는 안된다. ```(ex) *"apple" = 't';```
        - 연산 자체는 문제가 없으나 운영체제에 의해서 강제 종료될 가능성이 있다.
            - 운영 체제는 문자열 상수를 읽기 전용 메모리 영역에 저장하므로, 그 값을 바꾸는 명령의 실행을 제한할 수 있다.
- 컴파일러가 문자열 상수를 저장할 때 항상 마지막에 널 문자를 붙인다.


### char 포인터로 문자열 사용
문자열은 주소이므로 char 포인터에 대입하여 사용할 수 있다.
```c
// 포인터로 문자열을 사용하는 방법

#include <stdio.h>

int main(void)
{
    char *dessert = "apple";

    printf("오늘 후식은 %s입니다.\n", dessert); // 오늘 후식은 apple입니다.
    dessert = "banana";
    printf("내일 후식은 %s입니다.\n", dessert); // 내일 후식은 banana입니다.

    return 0;
}
```
- 문자열은 컴파일 과정에서 별도로 보관되고 첫 번째 문자의 주소로 바뀌므로 결국 포인터에는 문자열의 시작 위치 값만 저장된다.
    - 포인터 연산을 통해 해당 문자열 저네를 사용할 수 있다.
- ```printf``` 함수의 %s 변환 문자는 포인터 연산으로 문자열을 출력한다.

**같은 문자열 상수를 여러 번 사용할 때**  
컴파일러는 같은 문자열을 여러 번 사용한 경우 하나의 문자열만 메모리에 저장하고 그 주소를 공유하도록 번역한다. 따라서, 같은 문자열을 계속 사용해도 프로그램의 크기가 커지는 일은 없다.
- 단, 컴파일러에 따라 다르게 구현될 수 있으므로, 간은 문자열을 두 번 이상 사용하고 주소를 출력하여 같은 값인지 확인해보면 된다.
- 같은 문자열을 반복해서 사용할 때는 헤더 파일에 매크로명으로 정의해서 쓰는 것이 문자열을 수정할 때 관리하기 편한다.


### scanf 함수를 사용한 문자열 입력
```scanf``` 함수는 %s를 사용하여 공백이 없는 연속된 문자들을 입력받는다.

```c
// scanf 함수를 사용한 문자열 입력

#include <stdio.h>

int main(void)
{
    char str[80];

    printf("문자열 입력 : ");
    scanf("%s", str);                               // 문자열 입력 : apple jam
    printf("첫 번째 단어 : %s\n", str);                // 첫 번째 단어 : apple
    scanf("%s", str);
    printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str);   // 버퍼에 남아 있는 두 번째 단어 : jam

    return 0;
}
```
- 배열에 문자열을 저장할 때는 끝에 널 문자를 자동으로 붙인다.

**scanf 함수를 사용할 때 몇 글자를 입력하나?**  
```scanf``` 함수는 문자열을 저장할 배열의 크기를 알지 못한다.
- 주소인 배열명을 인수로 받으므로 오로지 배열의 시작 위치만 알고 있다. 그 주소를 증가시키면 버퍼로부터 가져온 문자열을 배열에 저장한다.
    - 배열 크기보다 큰 문자열을 입력하면 포인터 연산을 통해 할당된 메모리 공간을 넘어서 저장하여 메모리 침범이 발생할 수 있다.
    - 문자열을 입력할 때는 널 문자까지 고려(배열의 크기 - 1)하여 배열의 크기를 넘지 않도록 주의한다.


### gets 함수를 사용한 문자열 입력
```gets``` 함수는 중간의 공백이나 탭 문자를 포함하여 문자열 한 줄을 입력한다. = 함수 원형 ```char *gets(char *str)```  
```c
// gets 함수로 한 줄의 문자열 입력

#include <stdio.h>

int main(void)
{
    char str[80];

    printf("공백이 포함된 문자열 입력 : ");     // 공백이 포함된 문자열 입력 : apple jam
    gets(str);
    printf("입력한 문자열은 %s입니다.", str);  // 입력한 문자열은 apple jam입니다.

    return 0;
}
```
- 버퍼에서 개행 문자를 가져오지만 배열에는 널 문자로 바꿔 저장한다.
- ```gets``` 함수도 ```scanf``` 함수와 마찬가지로 입력한 문자열을 포인터 연산으로 배열에 저장한다.
    - 배열의 크기보다 큰 문자열을 입력하면 배열에 할당된 메모리 공간을 벗어나 저장하므로 주의해야 한다.
- ```gets``` 함수는 Enter만 눌러도 입력을 끝낸다.
    - ```gets``` 함수는 화이트 스페이스를 문자열의 일부로 입력하므로 문자열 입력 없이 바로 Enter만 눌러도 입력을 끝낸다.


### fgets 함수를 사용한 문자열 입력
최대 배열의 크기까지만 문자열을 입력한다.
```c
// fgets 함수의 문자열 입력 방법

#include <stdio.h>

int main(void)
{
    char str[80];

    printf("공백이 포함된 문자열 입력 : ");  // 입력된 문자열은 apple jam
    fgets(str, sizeof(str), stdin);

    printf("입력된 문자열은 %s입니다\n", str);  // 입력된 문자열은 apple jam
                                          // 입니다.
    return 0;
}
```
- ```fgets(str, sizeof(str), stdin);```
    - str : 배열명
    - sizeof(str) : 배열의 크기
    - stdin : 표준 입력
        - 데이터를 입력할 때 키보드와 연결된 표준 입력 버퍼를 사용하라는 뜻
        - ```fgets``` 함수는 입력 버퍼를 선택할 수 있는 함수이므로 키보드로 입력할 때는 항상 stdin을 넣어야 한다.
- ```gets``` 함수와는 다르게 버퍼에 있는 개행 문자도 배열에 저장하고 널 문자를 붙여 문자열을 완성한다.
- ```strlen``` 함수는 배열명을 인수로 받아 널 문자 이전까지의 문자 수를 세어 반환한다. in ```string.h```
    - 개행 문자를 제거하려면 ```str[strlen(str) - 1] = '\0'``` 으로 바꾸어 출력하면 된다.
    ```c
    // fgets 함수의 문자열 입력 방법

    #include <stdio.h>
    #include <string.h>


    int main(void)
    {
        char str[80];

        printf("공백이 포함된 문자열 입력 : ");         // 공백이 포함된 문자열 입력 : apple jam
        fgets(str, sizeof(str), stdin);

        str[strlen(str) - 1] = '\0';
        printf("입력된 문자열은 %s입니다.\n", str);    // 입력된 문자열은 apple jam입니다.

        return 0;
    }
    ```

### 표준 입력 함수의 버퍼 공유 문제
같은 버퍼를 공유하는 ```gets``` 함수 또는  ```fgets``` 함수에서 개행 문자를 입력의 종료 조건으로 사용하면 문제를 일으킬 수 있다.
- 입력한 함수가 버퍼에 개행 문자를 남겨 놓는 경우 이어서 호출되는 함수가 버퍼에서 개행 문자만 가져오고 입력을 끝내는 문제가 생기기 때문이다.

```c
// 개행 문자로 인해 gets 함수가 입력을 못하는 경우

#include <stdio.h>

int main(void)
{
    int age;
    char name[20];

    printf("나이 입력 : "); // 나이 입력 : 30
    scanf("%d", &age);

    printf("이름 입력 : ");
    gets(name);
    printf("나이 : %d, 이름 : %s\n", age, name);    // 이름 입력 : 나이 : 30, 이름 : 

    return 0;
}
```
- ```scanf("%d", &age);``` = 버퍼 [1, 7, \n]
    - 17 -> scanf, \n -> gets -> name 배열 [\0]
    - ```gets``` 함수는 버퍼에서 개행 문자를 가져와 입력을 끝내므로 이름을 입력하는 과정이 생력된다.
- 입력 함수들이 버퍼를 공유할 때 필요한 경우 버퍼의 남아 있는 개행 문자를 제거하기 위해 개행 문자를 읽어 들이는 문자 입력 함수를 호출한다.
    - ```getchar(); // 버퍼에서 하나의 문자를 읽어서 반환, 반환 문자는 버림```
    - ```scanf("%*c"); // 버퍼에서 하나의 문자를 읽어서 버림, 변수는 필요 없음```
    - ```fgetc(stdin); // 버퍼에서 하나의 문자를 읽어서 반환, 반환 문자는 버림```
```c
// 개행 문자로 인해 gets 함수가 입력을 못하는 경우

#include <stdio.h>

int main(void)
{
    int age;
    char name[20];

    printf("나이 입력 : "); // 나이 입력 : 30
    scanf("%d", &age);

    fgetc(stdin);

    printf("이름 입력 : ");
    gets(name);
    printf("나이 : %d, 이름 : %s\n", age, name);    // 나이 : 30, 이름 : 김지윤

    return 0;
}
```


### 문자열을 출력하는 puts, fputs 함수
- ```puts``` 함수의 원형 = ```int puts(const char *str) // 문자열을 출력하고 자동 줄 바꿈```
- ```fputs``` 함수의 원형 = ```int fputs(const char *str, FILE *stream) // 문자열을 출력ㅎ고 줄 바꾸지 않음```
- 두 함수 모두 정상 출력되면 0을 반환하고 출력에 실패하면 -1(EOF)을 반환한다.
```c
// 문자열을 출력하는 puts, fputs 함수

#include <stdio.h>

int main(void)
{
    char str[80] = "apple juice";
    char *ps = "banana";

    puts(str);              // apple juice
    fputs(ps, stdout);      // bananamilk
    puts("milk");

    return 0;
}
```
- 두 함수 모두 문자열의 시작 위치부터 널 문자가 나올 때까지 모든 문자를 출력한다.
    - char 배열의 배열명이나 문자열 상수를 연결하고 있는 포인터를 인수로 줄 수 있다. 직접 문자열 상수를 사용하는 것도 가능하다.


**gets 함수 구현**  
```c
// gets 함수 구현

#include <stdio.h>

int main(void)
{
    int i = 0;              // 배열 요소 첨자 변수
    char str[20];           // 문자열을 저장할 배열
    char ch;                // 입력한 문자를 받아둘 임시 변수

    do
    {
        ch = getchar();     // 일단 문자 하나 입력
        str[i] = ch;        // 배열에 저장
        i++;                // 첨자 증가
    } while (ch != '\n');   // 입력한 문자가 개행이면 종료
    
    str[--i] = '\0';        // 개행 문자가 입력된 위치에 널 문자 저장
    
    return 0;
}
```

</br>

## 문자열 연산 함수

### 문자열을 대입하는 strcpy 함수
char 배열에 문자열을 복사하는 대입 연상 기능을 수행한다. = ```strcpy(str1 : 복사 받을 곳, str2 : 복사할 내용)```
- 문자열을 복사하는 방식은 문자열의 첫 번재 문자부터 널 문자가 나올 때까지 문자를 하나씩 배열에 옮겨 저장한다.
- 복사할 문자열의 시작 위치를 알 수 있다면 어떤 것이든 두 번째 인수로 사용할 수 있다.
- 첫 번째 인수인 복사 받을 곳은 char 배열이나 그 배열명을 저장한 포인터만 가능하다. 문자열 상수는 값을 바꿀 수 없으므로 첫 번째 인수로 사용하면 프로그램을 실행할 때 에러가 발생한다. (ex) ```strcpy("banana", "apple");```
    - 첫 번째 인수는 char 배열이나 배열명을 저장한 포인터만 사용할 수 있다.
    - 두 번째 인수는 문자열의 시작 위치를 알 수 있다면 어떤 것이든 사용할 수 있다.
```c
// strcpy 함수의 사용법

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80] = "strawberry";
    char str2[80] = "apple";
    char *ps1 = "banana";
    char *ps2 = str2;

    printf("최초 문자열 : %s\n", str1);     // 최초 문자열 : strawberry
    strcpy(str1, str2);
    printf("바뀐 문자열 : %s\n", str1);     // 바뀐 문자열 : apple

    strcpy(str1, ps1);
    printf("바뀐 문자열 : %s\n", str1);     // 바뀐 문자열 : banana

    strcpy(str1, ps2);
    printf("바뀐 문자열 : %s\n", str1);     // 바뀐 문자열 : apple

    strcpy(str1, "banana");
    printf("바뀐 문자열 : %s\n", str1);     // 바뀐 문자열 : banana

    return 0;
}
```


### 원하는 개수의 문자만을 복사하는 strncpy 함수
문자열을 복사할 때 문자의 수를 지정할 수 있다. 널 문자는 저장하지 않는다. (ex) ```strncpy(str, "apple-pie", 5);```
```c
// strncpy 함수를 사용한 문자열 복사

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[20] = "mango tree";

    strncpy(str, "apple-pie", 5);

    printf("%s\n", str);        // apple tree

    return 0;
}
```


### 문자열을 붙이는 strcat, strncat 함수
붙여넣을 배열에서 널 문자의 위치를 찾고 그 위치부터 붙여넣을 문자열을 복사한다. 붙여넣기가 끝난 후에는 널 문자를 저장하여 마무리한다.
- ```strncpy``` 함수는 붙여넣은 후에는 널 문자를 저장하여 문자열을 완성한다.

```c
// strcat, strncat 함수를 사용한 문자열 붙이기

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80] = "straw";

    strcat(str, "berry");
    printf("%s\n", str);        // strawberry

    strncat(str, "piece", 3);
    printf("%s\n", str);        // strawberrypie

    return 0;
}
```

**strcat 함수 사용 시 주의 사항**  
1. ```strcat``` 함수는 메모리를 침범할 수 있다.
- 붙여넣기가 되는 배열의 크기가 충분히 커야한다. 
    - 붙여넣을 공간의 주소를 증가시키므로 공간이 부족한 경우 할당하지 않은 다른 메모리 영역을 침범할 수 있다.
    - 컴파일할 때 발견하지 못하고 프로그램이 완성된 후 실행할 때 발생하므로 더욱 주의해야 한다.

2. ```strcat``` 함수를 사용할 때는 배열을 초기화해야 한다.
- 붙여넣기 전에 먼저 널 문자의 위치를 찾으므로 반드시 초기화를 해야 한다. 그렇지 않으면 쓰레기 값의 중간부터 붙여넣을 가능성이 크다.
    - 명시적으로 널 문자를 초기화 : ```char str[80] = {'\0'};```
    - 널 문자의 아스키 코드 값으로 초기화 : ```char str[80] = {0};```
    - 큰따옴표 안에 아무것도 없으므로 널 문자만 초기화 : ```char str[80] = "";```
    - 첫 번째 배열 요소만 별도로 초기화 : ```str[0] = '\0';```


### 문자열 길이를 계산하는 strlen 함수
배열에 저장된 문자열에서 널 문자가 나올 때까지 문자 수를 세어 반환한다.
- 배열의 크기와는 상관없이 실제 저장된 문자열의 길이를 확인할 수 있다.
```c
// 두 문자열 중 길이가 긴 단어 출력

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80], str2[80];
    char *resp;

    printf("2개의 과일 이름 입력 : ");
    scanf("%s%s", str1, str2);                          // 2개의 과일 이름 입력 : banana strawberry

    if (strlen(str1) > strlen(str2)) { resp = str1; }
    else { resp = str2; }

    printf("이름이 긴 과일은 : %s\n", resp);                // 이름이 긴 과일은 : strawberry

    return 0;
}
```


### 문자열을 비교하는 strcmp, strncmp 함수
- ```strcmp```
    - 두 문자열의 사전 순서를 판단하여 그 결과를 반환한다. = (ex) ```strcmp(str1, str2);```
        - 사전 순서는 사전에 단어가 수록되는 알파벳 순서를 말한다.
        - str1이 str2보다 사전에 나중에 나오면 1 반환
        - str1이 str2보다 사전에 먼저 나오면 -1 반환
        - str1과 str2가 같은 문자열이면 0 반환
    - 두 문자열에서 문자의 아스키 코드 값을 비교한다.
- ```strncmp```
    - 
```c
// strcmp, strncmp 함수를 사용한 문자열 비교

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80] = "pear";
    char str2[80] = "peach";

    printf("사전에 나중에 나오는 과일 이름 : "); // 사전에 나중에 나오는 과일 이름 : pear
    if (strcmp(str1, str2) > 0) { printf("%s\n", str1); }
    else { printf("%s\n", str2); }

    return 0;
}
```

**strcmp 함수의 반환값이 항상 사전 순서를 의미하는 것은 아니다.**  
- 아스키 코드 값을 비교하므로 대소문자가 섞인 경우는 반환값이 사전 순서와 다를 수 있다.
    - 반환값으로 사전 순서를 판단할 때는 반드시 대소문자를 일치시켜야 한다.
- 한글은 2바이트로 구현하는데 첫 번째 바이트의 코드 값이 어떤 아스키 코드 값보다 크므로 아스키 문자로 구성된 단어보다 사전에서 뒤에 나오는 단어로 처리된다. 한글 자체의 코드 값은 가나다순으로 커진다.


### 연산 함수 직접 구현

**strcpy**  
```strcpy``` 함수는 포인터를 써서 문자열을 복사한다.
- 문자열이 저장된 메모리에서 첫 번째 문자의 주소를 인수로 받는다.
```c
// strcpy와 기능이 같은 함수의 구현

#include <stdio.h>

char *my_strcpy(char *pd, char *ps);

int main(void)
{
    char str[80] = "strawberry";

    printf("바꾸기 전 문자열 : %s\n", str);
    my_strcpy(str, "apple");
    printf("바꾼 후 문자열 : %s\n", str);
    printf("다른 문자열 대입 : %s\n", my_strcpy(str, "kiwi"));

    return 0;
}

char *my_strcpy(char *pd, char *ps)
{
    char *po = pd;

    while (*ps != '\0') // ps가 가리키는 문자가 널 문자가 아닌 동안
    {
        *pd = *ps;      // ps가 가리키는 문자를 pd가 가리키는 위치에 대입
        pd++;
        ps++;
    }
    *pd = '\0';         // 복사가 모두 끝난 후 복사 받을 곳에 널 문자로 마무리

    return po;          // 복사가 끝난 저장 공간의 시작 주소 반환
}
```

**strcat**  
```c
char *my_strcat(char *pd, char *ps)
{
    char *po = pd;

    while (*pd != '\0')
    {
        pd++;
    }

    while (*ps != '\0')
    {
        *pd = *ps;
        pd++;
        ps++;
    }
    *pd = '\0';

    return po;
}
```

**strlen**  
```c
int my_strlen(char *ps)
{
    int cnt = 0;
    while (*ps != '\0')
    {
        cnt++;
        ps++;
    }
    return cnt;
}
```

**strcmp**  
```c
int my_strcmp(char *pa, char *pb)
{
    while ((*pa == *pb) && (*pa != '\0'))
    {
        pa++;
        pb++;
    }

    if (*pa > *pb) { return 1; }
    else if (*pa < *pb) { return -1; }
    else { return 0; }
}
```