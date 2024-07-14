# 문자와 문자열 관련 함수

## 스트림과 데이터의 이동

### 데이터의 이동수단이 되는 스트림
프로그램상에서 모니터와 키보드를 대상으로 데이터를 입출력 하기 위해서는 이들을 연결시켜주는 다리가 필요하고 이러한 역할을 하는 매개체를 '스트림(stream)'이라 한다.

### 스트림의 생성과 소멸
콘솔 입출력을 위한 '입력 스트림'과 '출력 스트림'은 프로그램이 실행되면 자동으로 생성되고, 프로그램이 종료되면 자동으로 소멸되는 스트림이다.
- stdin : 표준 입력 스트림 -> 키보드 대상으로 입력
- stdout : 표준 출력 스트림 -> 모니터 대상으로 출력
- stderr : 표준 에러 스트림 -> 모니터 대상으로 출력

</br>

## 문자 단위 입출력 함수

### 문자 출력 함수 : putchar, fputc
모니터로 하나의 문자를 출력할 때 일반적으로 사용한다.

```c
#include <stdio.h>

int putchar(int c);
int fputc(int c, FILE * stream);
```
- 함수호출 성공 시 쓰여진 문자정보가, 실패 시 EOF 반환
- ```putchar```
    - 인자로 전달된 문자정보를 stdout으로 표현되는 표준 출력 스트림으로 전송하는 함수
- ```fputc```
    - 문자를 전송할 스트림을 지정할 수 있다. 즉, stdout뿐만 아니라, 파일을 대상으로도 데이터를 전송할 수 있다.

### 문자 입력 함수 : getchar, fgetc
```c
#include <stdio.h>
int getchar(void);
int fgetc(FILE * stream);
```
- 파일의 끝에 도달하거나 함수호출 실패 시 EOF 반환
- ```getchar```
    - stdin으로 표현되는 표준 입력 스트림으로부터 하나의 문자를 입력 받아서 반환하는 함수
- ```fgetc```
    - ```getchar``` 함수와 달리 문자를 입력 받을 스트림을 지정할 수 있다.

```c
#include <stdio.h>

int main(void)
{
    int ch1, ch2;

    ch1 = getchar();
    ch2 = fgetc(stdin);

    putchar(ch1);
    fputc(ch2, stdout);

    return 0;
}
```

### 문자 입출력에서의 EOF
EOF(End Of File)는 파일의 끝을 표현하기 위해서 정의해 놓은 상수이다.
- 키보드를 대상으로 하는 ```fgetc```, ```getchar``` 함수는 언제 EOF를 반환할까?
    - 함수호출의 실패
    - Windows의 Ctrl+Z, Linux의 Ctrl+D 키가 입력되는 경우
```c
#include <stdio.h>

int main(void)
{
    int ch;

    while (1)
    {
        ch = getchar();
        if (ch == EOF) { break; }
        putchar(ch);
    }

    return 0;
}
```

### 반환형이 int이고, int형 변수에 문자를 담는 이유는?
```getchar```, ```fgetc```가 반환하는 값 중 하나인 EOF는 -1로 정의된 상수이다.
- 반환형이 char형 이라면, char를 unsigned char로 처리하는 컴파일러에 의해 컴파일 된다면, EOF는 반환의 과정에서 엉뚱한 양이 정수로 형 변환된다.

</br>

## 문자열 단위 입출력 함수

### 문자열 출력 함수 : puts, fputs
```c
#include <stdio.h>
int puts(const char * s);
int fputs(const char * s, FILE * stream);
```
- 성공 시 음수가 아닌 값을, 실패 시 EOF 반환

```c
#include <stdio.h>

int main(void)
{
    char * str = "Simple String";

    printf("1. puts test -------- \n");
    puts(str);
    puts("So Simple String");

    printf("2. fputs test -------- \n");
    fputs(str, stdout); printf("\n");
    fputs("So Simple String", stdout); printf("\n");

    printf("3. end of main ------- \n");
    return 0;
}
```
- ```puts```함수가 호출되며 문자열 출력 후 자동으로 개행이 이뤄지지만, ```fputs``` 함수가 호출되면 문자열 출력 후 자동으로 개행이 이뤄지지 않는다.

### 문자열 입력 함수 : gets, fgets
```c
#include <stdio.h>
char * gets(char * s);
char * fgets(char * s, int n, FILE * stream);
```
- 파일의 끝에 도달하거나 함수호출 실패 시 NULL 포인터 반환
- ```gets```
    - 미리 마련해 놓은 배열을 넘어서는 길이의 문자열이 입력되면, 할당 받지 않은 메모리 공간을 침범하여 실행 중 오류를 발생시킬 수 있다. 가급적 ```fgets``` 함수 호출
- ```fgets```
    - 입력으로 주어지는 크기 - 1 만큼의 문자열이 저장된다.
        - 널 문자 저장을 위한 것
    - 문자열을 입력 받으면 문자열의 끝에 자동으로 널 문자가 추가된다.
```c
#include <stdio.h>

int main(void)
{
    char str[7];
    int i;

    for (i = 0; i < 3; i++)
    {
        fgets(str, sizeof(str), stdin);
        printf("Read %d: %s \n", i + 1, str);
    }
    return 0;
}
```
- ```fgets``` 함수는 \n을 만날 때까지 문자열을 읽어 들이는데, \n을 제외시키거나 버리지 않고 문자열의 일부로 받아들인다.
    - 따라서, 중간에 공백문자가 삽입되어도 문자열의 일부로 읽어 들인다.

</br>

## 표준 입출력과 버퍼

### 표준 입출력 기반의 버퍼
표준 입출력 함수를 통해서 입출력 하는 경우, 해당 데이터들은 운영체제가 제공하는 '메모리 버퍼'를 중간에 통과하게 된다.

### '버퍼링(buffering)'을 하는 이유는 무엇인가?
정보를 목적지로 바로 이동시키는 것보다 중간에 메모리 버퍼를 둬서 데이터를 한데 묶어서 이동시키는 것이 보다 효율적이고 빠르다.

### 출력버퍼를 비우는 fflush 함수
출력버퍼가 비워진다는 것은 출력버퍼에 저장된 데이터가 버퍼를 떠나서 목적지로 이동됨을 뜻한다.
- 버퍼가 비워지는 시점은 시스템에 따라 그리고 버퍼의 성격에 따라 달라지므로 ```fflush``` 함수를 알아 둘 필요가 있다.

```c
#include <stdio.h>
int fflush(FILE * stream);
```
- 함수호출 성공 시 0, 실패 시 EOF 반환
- ```fflush(stdout);```
    - 표준 출력버퍼를 지워라!

### 입력버퍼는 어떻게 비워야 하나요?
'출력버퍼의 비워짐'이 저장된 데이터가 목적지로 전송됨을 의미한다면, '입력버퍼의 비워짐'은 데이터의 소멸을 의미한다.

```c
#include <stdio.h>

int main(void)
{
    char perID[7];
    char name[10];

    fputs("주민번호 앞 6자리 입력: ", stdout);
    fgets(perID, sizeof(perID), stdin);

    fputs("이름 입력: ", stdout);
    fgets(name, sizeof(name), stdin);

    printf("주민번호: %s \n", perID);
    printf("이름: %s \n", name);

    return 0;
}
```
- 주민번호 앞 6자리 입력의 경우 번호와 엔터키의 입력으로 총 7문자가 입력된다.
- ```fgets``` 함수의 인자로 7이 전달되었으니, 널 문자를 제외하고 최대 6문자를 읽어들이게 된다.
    - 따라서, \n을 제외한 나머지 여섯 문자만 읽혀지고 \n은 버퍼에 남겨지게 된다.
    - 다음 ```fgets``` 함수는 버퍼에 남아있는 \n을 읽어버리고 말아서 이름을 입력할 수 없게 된다.

```c
#include <stdio.h>

void ClearLineFromReadBuffer(void)
{
    while (getchar() != '\n');
}

int main(void)
{
    char perID[7];
    char name[10];

    fputs("주민번호 앞 6자리 입력: ", stdout);
    fgets(perID, sizeof(perID), stdin);
    ClearLineFromReadBuffer();

    fputs("이름 입력: ", stdout);
    fgets(name, sizeof(name), stdin);

    printf("주민번호: %s \n", perID);
    printf("이름: %s \n", name);
}
```
- ```ClearLineFromReadBuffer``` 함수는 \n이 읽혀질 때까지 입력버퍼에 저장된 문자들을 지움으로써 입력버퍼를 비우게 된다.

</br>

## 입출력 이외의 문자열 관련 함수

### 문자열의 길이를 반환하는 함수 : strlen
```c
#include <string.h>
size_t strlen(const char * s);
```
- 전달된 문자열의 길이를 반환하되, 널 문자는 길이에 포함하지 않는다.
- ```typedef unsigned int size_t;```
    - unsigned int의 선언을 size_t로 대신할 수 있다.

```c
#include <stdio.h>
#include <string.h>

void RemoveBSN(char str[])
{
    int len = strlen(str);
    str[len - 1] = 0;
}

int main(void)
{
    char str[100];
    printf("문자열 입력: ");
    fgets(str, sizeof(str), stdin);
    printf("길이 : %d, 내용 : %s \n", strlen(str), str);

    RemoveBSN(str);
    printf("길이 : %d, 내용 : %s \n", strlen(str), str);
    return 0;
}
```
- ```RemoveBSN```을 통해 \n 문자가 소멸하였다.

### 문자열을 복사하는 함수들 : strcpy, strncpy
```c
#include <string.h>
char * strcpy(char * dest, const char * src);
char * strncpy(char * dest, const char * src, size_t n);
```
- 복사된 문자열의 주소 값 반환

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[20] = "1234567890";
    char str2[20];
    char str3[5];

    /*** case1 ****/
    strcpy(str2, str1);
    puts(str2);

    /*** case2 ****/
    strncpy(str3, str1, sizeof(str3));
    puts(str3);

    /*** case3 ****/
    strncpy(str3, str1, sizeof(str3) - 1);
    str3[sizeof(str3) - 1] = 0;
    puts(str3);

    return 0;
}
```
- ```strncpy``` 함수는 문자열을 단순하게 복사한다. 즉, 마지막 문자가 널 문자인지 아닌지는 상관하지 않는다.
    - 출력을 하기 위해서 널 문자가 존재해야 그 이전까지 출력을 할 텐데, 널 문자가 존재하지 않으니 엉뚱한 영역까지 출력을 하게 된다.
    - 따라서, 배열의 실제길이보다 하나 작은 값을 전달해서 널 문자가 삽입될 공간을 남겨두고 복사를 진행한 뒤, 배열의 끝에 널 문자를 삽입해야 한다.

### 문자열을 덧붙이는 함수들 : strcat, strncat
```c
#include <string.h>
char * strcat(char * dest, const char * src);
char * strncat(char * dest, const char * src, size_t n);
```
- 덧붙여진 문자열의 주소 값 반환
    - 널 문자가 저장된 위치에서부터 덧붙여진다.
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[20] = "First~";
    char str2[20] = "Second";

    char str3[20] = "Simple num: ";
    char str4[20] = "1234567890";

    /**** case 1 ****/
    strcat(str1, str2);
    puts(str1);

    /**** case 2 ****/
    strncat(str3, str4, 7);
    puts(str3);

    return 0;
}
```
- ```strncat``` 함수는 지정된 문자열의 개수만큼 문자열을 뒤에 덧붙이되 마지막에 널 문자를 포함해서 입력으로 주어진 문자열의 개수 + 1 개의 문자가 덧붙여진다.

### 문자열을 비교하는 함수들 : strcmp, strncmp
```c
#include <string.h>
int strcmp(const char * s1, const char * s2);
int strncmp(const char * s1, const char * s2, size_t n);
```
- 두 문자열의 내용이 같으면 0, 같지 않으면 0이 아닌 값을 반환
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[20];
    char str2[20];

    printf("문자열 입력 1: ");
    scanf("%s", str1);
    printf("문자열 입력 2: ");
    scanf("%s", str2);

    if (!strcmp(str1, str2))
    {
        puts("두 문자열은 완벽히 동일합니다.");
    }
    else
    {
        puts("두 문자열은 완벽히 동일하지 않습니다.");
        if (!strncmp(str1, str2, 3))
            puts("그러나 앞 세 글자는 동일합니다.");
    }
    return 0;
}
```

### 그 이외의 변환 함수들
```c
#include <stdlib.h>
int atoi(const char * str);     // 문자열의 내용을 int형으로 반환
long atol(const char * str);    // 문자열의 내용을 long형으로 반환
double atof(const char * srt);  // 문자열의 내용을 double형으로 반환
```

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[20];
    printf("정수 입력: ");
    scanf("%s", str);
    printf("%d \n", atoi(str));

    printf("실수 입력: ");
    scanf("%s", str);
    printf("%g \n", atof(str));
    
    return 0;
}
```