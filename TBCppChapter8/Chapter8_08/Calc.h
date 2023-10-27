#pragma once

#include <iostream>

// 헤더파일 안에 클래스 선언
// 참고로, 클래스의 헤더파일 이름은 클래스 이름과 같게 맞춰야 함!
class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}

	// 이 메서드들은 반환타입이 클래스 자신의 '참조변수'로 선언됨. (포인터 변수 아님 주의!)
	// (참조변수 관련 https://github.com/jooo0922/cpp-study/blob/main/TBCppStudy/Chapter6_14/Chapter6_14.cpp 참고)
	// 즉, 실제 값(인스턴스)이 저장된 변수를 반환해야 하므로, 
	// 인스턴스 자신의 주소값이 담긴 this 를 de-referencing 하여 실제 인스턴스 자신을 반환함.
	// 이처럼, 메서드 마지막에 인스턴스 자신(*this)을 반환하면, 해당 함수를 멤버함수 체이닝에 사용할 수 있음!
	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }

	void print()
	{
		// 헤더파일 안에서는 가급적 using namespace 사용을 자제
		// why? 헤더파일을 include 하는 모든 파일들이 영향을 받게 됨
		using namespace std;

		cout << m_value << endl;
	}
};