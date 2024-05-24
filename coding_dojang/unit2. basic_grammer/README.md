# 기본 문법

## 세미콜론
```C
printf("Hello, world\n");
```
- C 언어는 구문이 끝날 때 ; (세미콜론)을 붙여야 한다.

## 주석
- 주석은 컴파일러가 처리하지 않으므로 프로그램의 실행에는 영향을 주지 않는다.
- 일반적으로 주석은 코드에 대한 자세한 설명을 작성하거나, 특정 코드를 임시로 컴파일되지 않도록 만들 때 사용한다.

```C
// Hello, world! 출력
printf("Hello, world!\n");
```

범위주석
```C
/*
printf("Hello, world!\n");
printf("1234567890");
*/

printf("Hello" /* 안녕하세요 */);
```

## 중괄호
- C 언어는 여러 문법에서 { } (중괄호)를 많이 사용하는데 보통 중괄호는 코드의 범위를 나타낼 때 사용한다.

1. 일반적인 경우
```C
int main()
{
    printf("Hello, world!\n");

    return 0;
}
```

2. for, if 문
```C
if (a > 10)
{
    printf("a");
}

for (int i = 0; i < 10; i++)
{
    printf("Hello, world!\n");
}
```

3. 구조체(공용체, 열거형)
```C
struct Hello {
    int a;
    int b;
};
```

## 들여쓰기