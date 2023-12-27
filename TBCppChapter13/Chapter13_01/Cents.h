#pragma once

#include <iostream>

using namespace std;

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

	// 비교 연산자 오버로딩
	friend bool operator > (const Cents& c1, const Cents& c2)
	{
		return (c1.m_cents > c2.m_cents);
	}

	// 출력 스트림 연산자 오버로딩을 친구함수로 등록
	friend ostream& operator << (ostream& out, const Cents& cents)
	{
		out << cents.m_cents << " cents ";
		return out;
	}
};