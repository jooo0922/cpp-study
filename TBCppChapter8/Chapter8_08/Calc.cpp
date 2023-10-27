#include "Calc.h"

// Calc.cpp 는 헤더파일이 아니므로,
// using namespace 를 자유롭게 사용 가능!
using namespace std;

// 생성자 함수도 선언부와 구현부를 분리할 수 있음!
Calc::Calc(int init_value)
	: m_value(init_value)
{}

// Calc.h 헤더파일에 선언한 클래스 함수를 .cpp 파일에서 구현부 정의할 수 있음.
// 이때, 이 함수가 어느 클래스에 소속된 함수라는 것을 표시하기 위해 
// '<클래스명>::' 을 반드시 표기해줘야 함.
Calc& Calc::add(int value) 
{ 
	m_value += value; 
	return *this; 
}

// Visual Studio 의 리팩토링 기능을 사용하여 추출한 함수 구현부
// 이때, inline 키워드가 붙는데, 클래스 안에 멤버 함수 정의를 전부 구현해놓았을 경우,
// 컴파일러가 이 함수들을 inline 처리를 하고 싶은 것으로 간주해서 리팩터링 기능이 자동으로 inline 키워드를 붙여줌.
// 그러나, 우리는 inline 키워드는 잘 사용하지 않으므로, inline 은 생략 가능함!
// inline Calc& Calc::sub(int value) { m_value -= value; return *this; }
// 인라인 함수 관련 https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter7/Chapter7_06/Chapter7_06.cpp 참고
Calc& Calc::sub(int value) 
{ 
	m_value -= value; 
	return *this; 
}

Calc& Calc::mult(int value) 
{ 
	m_value *= value; 
	return *this; 
}

void Calc::print()
{
	cout << m_value << endl;
}
