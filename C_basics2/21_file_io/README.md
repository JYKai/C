# 파일 입출력

## 파일과 스트림(Stream), 그리고 기본적인 파일의 입출력

### 저기 저 파일에 저장되어 있는 데이터를 읽고 싶어요.
프로그램과 파일 사이에 스트림을 형성해야 데이터를 주고받을 수 있다.
- 스트림이 형성되었단 말은 파일로부터 데이터를 읽어 들일(파일에 데이터를 쓸) 기본적인 준비가 완료된 것이다.

### fopen 함수호출을 통한 파일과의 스트림 형성 FILE 구조체
```c
#include <stdio.h>
FILE * fopen(const char * filename, const char * mode);
```
- 성공 시 해당 파일의 FILE 구조체 변수의 주소 값, 실패 시 NULL 포인터 반환
    - 첫 번째 인자 : 스트림을 형성할 파일의 이름
    - 두 번째 인자 : 형성하고자 하는 스트림의 종류
- ```fopen``` 함수가 호출되면 FILE 구조체 변수가 생성된다.
- 생성된 FILE 구조체 변수에는 파일에 대한 정보가 담긴다.
- FILE 구조체의 포인터는 사실상 파일을 가리키는 '지시자'의 역할을 한다.

### 입력 스트림과 출력 스트림의 생성
```c
FILE * fp = fopen("data.txt", "wt"); // 출력 스트림의 형성
FILE * fp = fopen("data.txt", "rt"); // 입력 스트림의 형성
```

### 파일에 데이터를 써봅시다.
```c
#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("data.txt", "wt");
    if (fp == NULL) 
    { 
        puts("파일오픈 실패!");
        return -1;
    }

    fputc('A', fp);
    fputc('B', fp);
    fputc('C', fp);
    fclose(fp);     // 스트림의 종료
    return 0;
}
```

### 스트림의 소멸을 요청하는 fclose 함수
```fclose``` 함수는 스트림을 해제하는 함수이다.  
개방되었던 파일을 닫아줘야 하는 이유
- 운영체제가 할당한 자원의 반환
- 버퍼링 되었던 데이터의 출력

### fflush 함수
스트림을 종료하지 않고 버퍼만 비우고 싶을 때 사용한다.

### 파일로부터 데이터를 읽어 봅시다.
```c
#include <stdio.h>

int main(void)
{
    int ch, i;
    FILE * fp = fopen("data.txt", "rt");
    if (fp == NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }

    for (i = 0; i < 3; i++)
    {
        ch = fgetc(fp);
        printf("%c \n", ch);
    }
    
    fclose(fp);
    return 0;
}
```

</br>

## 파일의 개방 모드(Mode)

### 스트림을 구분하는 기준1: 읽기 위한 스트림? 쓰기 위한 스트림?
| Mode | 스트림의 성격 | 파일이 없으면? |
| ---- | ---- | ---- |
|  r   | 읽기 가능 | 에러 |
|  w   | 쓰기 가능 | 생성 |
|  a   | 파일의 끝에 덧붙여 쓰기 가능 | 생성 |
|  r+  | 읽기/쓰기 가능 | 에러 |
|  w+  | 읽기/쓰기 가능 | 생성 |
|  a+  | 읽기/덧붙여 쓰기 가능 | 생성 |
- 모드의 +는 읽기, 쓰기가 모두 가능한 스트림의 형성을 의미한다.
- 모드의 a는 쓰기가 가능한 스트림을 형성하는데, 여기에서 쓰기는 덧붙이기이다.
- 웬만하면 r, w, a 중에서 선택하자.

### 텍스트 파일과 바이너리 파일
사람이 인식할 수 있는 문자를 담고 있는 파일을 '텍스트 파일'이라 하며, 그 이외에 컴퓨터가 인식할 수 있는 데이터를 담고 있는 파일을 '바이너리 파일'이라 한다.
- 개인이 소유하는 도서의 목록 : 문자 데이터
- 슈퍼마켓의 물품 가격 : 문자 데이터
- 제임스 캐머런 감독의 타이타닉 영상파일 : 바이너리 데이터
- 소녀시대의 히트곡 음원파일 : 바이너리 데이터

### 개행이 \n이 아니라고요?
개행은 줄이 바뀌었다는 일종의 현상이지 그 자체가 하나의 데이터로 존재하는 대상은 아니다.
- C언어에서는 개행을 \n으로 표시한다. 그런데 이는 C언어만의 약속이다.

### 스트림을 구분하는 기준2: 텍스트 모드와 바이너리 모드
파일을 텍스트 모드로 개방하면 개행의 형태가 운영체제마다 자동으로 변환된다.  
바이너리 데이터를 저장하고 있는 파일의 경우에는 형태의 변환이 일어나면 안되기 때문에 바이너리 모드로 파일을 개방해야 한다.

</br>

## 파일 입출력 함수의 기본
```c
#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("simple.txt", "wt");
    if (fp == NULL)
    {
        puts("파일 오픈 실패!");
        return -1;
    }

    fputc('A', fp);
    fputc('B', fp);
    fputs("My name is Kim \n", fp);
    fputs("Yout name is Hong \n", fp);
    fclose(fp);
    return 0;
}
```
```c
#include <stdio.h>

int main(void)
{
    char str[30];
    int ch;
    FILE *fp = fopen("simple.txt", "rt");
    if (fp == NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }

    ch = fgetc(fp);
    printf("%c \n", ch);
    ch = fgetc(fp);
    printf("%c \n", ch);

    fgets(str, sizeof(str), fp);
    printf("%s", str);
    fgets(str, sizeof(str), fp);
    printf("%s", str);

    fclose(fp);

    return 0;
}
```
- 문자열이 파일에 저장될 때에는 문자열의 끝을 의미하는 널 문자는 저장하지 않는다. 따라서, 파일에서는 개행을 기준으로 문자열을 구분한다.

### feof 함수 기반의 파일복사 프로그램
파일의 마지막에 저장된 데이터까지 모두 읽어 들여야 하는 상황에 사용한다.
```c
#include <stdio.h>
inf feof(FILE * stream);
```
- 파일의 끝에 도달한 경우 0이 아닌 값을 반환
- 파일복사 프로그램과 같이 파일의 끝을 확인해야 하는 경우에 유용하게 사용된다.
```c
#include <stdio.h>

int main(void)
{
    FILE *src = fopen("data.txt", "rt");
    FILE *des = fopen("dst.txt", "wt");
    int ch;

    if (src == NULL || des == NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }

    while ((ch = fgetc(src)) != EOF)
        fputc(ch, des);
    
    if (feof(src) != 0) { puts("파일복사 완료!"); }
    else { puts("파일복사 실패!"); }

    fclose(src);
    fclose(des);
}
```
```c
#include <stdio.h>

int main(void)
{
    FILE * src = fopen("simple.txt", "rt");
    FILE * des = fopen("des.txt", "wt");
    char str[20];

    if (src == NULL || des == NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }

    while ((fgets(str, sizeof(str), src)) != NULL)
        fputs(str, des);
    
    if (feof(src) != 0)
        puts("파일복사 완료!");
    else 
        puts("파일복사 실패!");
    
    fclose(src);
    fclose(des);

    return 0;
}
```
- ```fgets``` 함수는 파일의 끝에 도달해서 더 이상 읽을 데이터가 존재하지 않거나 오류가 발생하는 경우에 NULL을 반환한다.

### 바이너리 데이터의 입출력: fread, fwrite
```c
#include <stdio.h>
size_t fread(void * buffer, size_t size, size_t count, FILE * stream);
```
- 성공 시 전달인자 count, 실패 또는 파일의 끝 도달 시 count보다 작은 값 반환

```c
#include <stdio.h>
size_t fwrite(const void * buffer, size_t size, size_t count, FILE * stream);
```
- 성공 시 전달인자 count, 실패 시 count보다 작은 값 반환

```c
#include <stdio.h>

int main(void)
{
    FILE * src = open("src.bin", "rb");
    FILE * des = open("dst.bin", "wb");
    char buf[20];
    int readCnt;

    if (src == NULL || des == NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }

    while (1)
    {
        readCnt = fread((void*)buf, 1, sizeof(buf), src);

        if (readCnt < sizeof(buf))
        {
            if (feof(src) != 0)
            {
                fwrite((void*)buf, 1, readCnt, des);
                puts("파일복사 완료!");
                break;
            }
            else
                puts("파일복사 실패!");
            break;
        }   
        fwrite((void*)buf, 1, sizeof(buf), des);
    }

    fclose(src);
    fclose(des);

    return 0;
}
```

</br>

## 텍스트 데이터와 바이너리 데이터를 동시에 입출력 하기

### 서식에 따른 데이터 입출력: fprintf, fscanf
두 함수는 입출력의 대상이 콘솔이 아닌 파일이다.
```c
#include <stdio.h>

int main(void)
{
    char name[10];
    char sex;
    int age;

    FILE *fp = fopen("friend.txt", "wt");
    int i;

    if (fp == NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }

    for (i = 0; i < 3; i++)
    {
        printf("이름 성별 나이 순 입력: ");
        scanf("%s %c %d", name, &sex, &age);
        fprintf(fp, "%s %c %d", name, sex, age);
    }
    fclose(fp);
    return 0;
}
```
- ```fprintf``` 함수의 호출을 통해서 저장된 데이터는, 동일하게 서식을 지정해서 ```fscanf``` 함수의 호출을 통해서 읽어들일 수 있다.
```c
#include <stdio.h>

int main(void)
{
    char name[10];
    char sex;
    int age;

    FILE *fp = fopen("friend.txt", "rt");
    int ret;

    if (fp == NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }

    while (1)
    {
        ret = fscanf(fp, "%s %c %d", name, &sex, &age);
        if (ret == EOF) { break; }
        printf("%s %c %d \n", name, sex, age);
    }
    fclose(fp);
    return 0;
}
```
- ```fscanf``` 함수는 파일의 끝에 도달하거나 오류가 발생하면 EOF를 반환한다.

### 텍스트와 바이너리 데이터의 집합체인 구조체 변수의 입출력
구조체 변수를 하나의 바이너리 데이터로 인식하고 처리하면 된다.
```c
#include <stdio.h>

typedef struct fren
{
    char name[10];
    char sex;
    int age;
} Friend;

int main(void)
{
    FILE * fp;
    Friend myfren1;
    Friend myfren2;

    /*** file write ***/
    fp = fopen("friend.bin", "wb");
    printf("이름, 성별, 나이 순 입력: ");
    scanf("%s %c %d", myfren1.name, &(myfren1.sex), &(myfren1.age));
    fwrite((void*)&myfren1, sizeof(myfren1), 1, fp);
    fclose(fp);

    /*** file read ***/
    fp = fopen("friend.bin", "rb");
    fread((void*)&myfren2, sizeof(myfren2), 1, fp);
    printf("%s %c %d \n", myfren2.name, myfren2.sex, myfren2.age);
    fclose(fp);
    return 0;
}
```
- ```fwrite``` 함수는 데이터를 바이트 단위로 단순저장하기 때문에 이렇듯 구조체 변수를 통째로 저장할 수 있다.
- ```fread``` 함수를 호출하여 통째로 구조체 변수를 복원할 수 있다.

</br>

## 임의 접근을 위한 '파일 위치 지시자'의 이동

### 파일 위치 지시자란?
FILE 구조체의 멤버 중에는 파일의 위치 정보를 저장하고 있는 멤버가 있으며, 이 멤버의 값은 ```fgets```, ```fputs```, ```fread```, ```fwrite``` 와 같은 함수가 호출될 때마다 참조 및 갱신된다.

### 파일 위치 지시자의 이동: fseek
```c
#include <stdio.h>
int fseek(FILE * stream, long offset, int wherefrom);
```
- 성공 시 0, 실패 시 0이 아닌 값을 반환
- stream으로 전달된 파일 위치 지시자를 wherefrom에서부터 offset 바이트 만큼 이동시켜라.
    - SEEK_SET(0) : 파일 맨 앞에서부터 이동을 시작
        - 전달 시 첫 번째 바이트에서부터 이동을 시작한다.
    - SEEK_CUR(1) : 현재 위치에서부터 이동을 시작
    - SEEK_END(2) : 파일 맨 끝에서부터 이동을 시작
        - 전달 시 EOF에서부터 이동을 시작한다.
        - 파일의 끝을 표시하기 위해서 삽입이 되는 EOF를 의미함에 특히 주의해야한다.
```c
#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("text.txt", "wt");
    fputs("123456789", fp);
    fclose(fp);

    fp = fopen("text.txt", "rt");

    fseek(fp, -2, SEEK_END);
    putchar(fgetc(fp));

    fseek(fp, 2, SEEK_SET);
    putchar(fgetc(fp));

    fseek(fp, 2, SEEK_CUR);
    putchar(fgetc(fp));

    fclose(fp);
    return 0;
}
```

### 현재 파일 위치 지시자의 위치는? : ftell
```c
#include <stdio.h>
long ftell(FILE * fp);
```
- 파일 위치 지시자의 위치 정보 반환
    - 가장 앞 부분의 바이트 위치를 0으로 간주한다.