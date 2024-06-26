# 반복실행을 명령하는 반복문

## while문에 의한 문장의 반복

### while문은 반복을 명령하는 문장이다.
- 반복문 안에도 들여쓰기를 한다.
- 반복의 대상이 하나의 문자이라면 중괄호는 생략 가능하다.
- while 문의 조건에 부합하는지 안하는지에 따라 반복문이 동작한다.
    - 조건 설정을 잘못하면 무한루프에 빠질 수 있다.

</br>

## do ~ while문에 의한 문장의 반복
while문과의 차이점은 '반복의 조건을 검사하는 시점'에 있다.

### do ~ while문의 기본구성
while문과 달리 반복조건을 뒷부분에 검사한다. 즉, 반복영역을 최소한 한 번은 실행하는 구조이다.
```c
do
{
    printf("Hello world! \n);
    num++;
} while(num < 3);
```
- 대부분의 경우 do ~ while문이 while문을 대체할 수 있으나, 일반적인 경우 while문을 선택한다.

</br>

## for문에 의한 문장의 반복
while, do~while과 달리 반복을 위한 변수의 선언과 반복조건을 '거짓'으로 만들기 위한 값의 증가 및 감소연산 등을 한데 묶을 수 있도록 만들어진 반복문이다.
```c
for (초기식; 조건식; 증감식)
{
    // 반복의 대상이 되는 문장들
}
```
- 반복의 횟수가 딱 정해진 경우라면 분명 for문이 최선이다.
- 초기식과 증감식은 비워도 동작할 수 있다.
- for문의 중간에 위치한 '조건식'이 비워지면 무조건 '참'으로 인식이 되어 무한루프를 형성하게 된다.
