# 포인터의 이해

## 포인터란 무엇인가?

### 주소 값의 저장을 목적으로 선언되는 포인터 변수
C언어에서는 시작번지만을 가지고 위치를 표현한다.
- 포인터 변수란 메모리의 주소 값을 저장하기 위한 변수이다.

### 포인터 변수 선언하기
가리킬 변수의 자료형에 따라서 포인터 변수의 선언방식이 달라진다.
- 포인터 변수의 선언형태만 보고도 포인터가 현재 가리키는 변수의 자료형을 알 수 있다.

</br>

## 포인터와 관련 있는 연산자: & 연산자와 * 연산자

### 변수의 주소 값을 반환하는 & 연산자
& 연산자의 피연산자는 변수이어야 하며, 상수는 피연산자가 될 수 없다.

### 포인터가 가리키는 메모리를 참조하는 * 연산자
포인터가 가리키는 메모리 공간에 접근할 때 사용하는 연산자이다.

### 다양한 '포인터 형'이 존재하는 이유!
포인터의 형은 메모리 공간을 참조하는 기준이 된다.
- \* 연산자를 통한 메모리 공간의 접근 기준을 마련하기 위함이다.

### 잘못된 포인터의 사용과 널 포인터
포인터 변수를 선언만하고 초기화하지 않으면, 포인터 변수는 쓰레기 값으로 초기화 된다.
- 만약 ptr이 가리키는 메모리 공간이 매우 중요한 위치였다면, 심각한 문제를 일으킬 수 있다.
- 포인터 변수를 우선 선언만 해 놓고, 이후에 유효한 주소 값을 채워 넣을 생각이라면 0 또는 NULL 값으로 초기화 하는 것이 좋다.
    - 값 0을 가리켜 '널 포인터'라 한다. 0번지를 의미하는 것이 아니라, 아무곳도 가리키지 않는다는 뜻이다.