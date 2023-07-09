#include <iostream>

// 함수명은 대문자를 많이 사용
// 최근에는 앞에 소문자를 사용하는 사람이 많아졌으니 개발팀 컨벤션에 따를 것!
// 함수명은 "동사 + 명사" 구조로 짓는 게 일반적 > 기능 설명에 용이
// 도저히 안될 경우 그냥 명사로 지어도 됨.
void GetNumber()
{

}

// 변수명 또는 함수명이 아주 길어질 경우, 옆에 주석을 달아주는 편이 낫다.
void addNumber() // .........
{

}

class MyClass
{
public:
	//int m_variable; // 보통 클래스의 멤버변수 표기 시, m_ 이런 접두어를 붙이기도 하는데, 요새는 커서를 갖다대면 멤버변수 표시가 다 뜨니까 굳이 안붙여도 됨.
	int variable;
};

int main()
{
	//int 3three; // 숫자로 시작하는 변수, 함수명, 클래스명은 금지!
	int n_apples, n_oranges; // underscore > 변수에 사용되는 이름끼리는 띄어쓰기 불가하므로, underscore 로 처리하기도 함.
	int VALUE; // 일반적으로 대문자는 변수명으로 잘 안씀. 타이핑이 불편하기도 하고, 변수명보다는 "매크로"에 관습적으로 많이 씀. > 가급적 소문자로 쓰는 걸 권장

	VALUE = 123;

	int nApples; // underscore 대신 이런 camelCase 로 사용하기도 함. > 개발팀에서 어떤 방식을 사용하는지에 따라 달라질 수 있음.
	int _apples; // 앞에 underscore 를 사용할 수도 있는데 일반적으로 이렇게는 안함.

	addNumber();
}
