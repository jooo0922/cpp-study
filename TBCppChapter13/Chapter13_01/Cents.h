#pragma once

#include <iostream>

// user-defined 자료형 (== 클래스) 구현
class Cents
{
private:
	int m_cents;

public:
	// 생성자 함수
	Cents(int cents)
		: m_cents(cents)
	{

	}
};