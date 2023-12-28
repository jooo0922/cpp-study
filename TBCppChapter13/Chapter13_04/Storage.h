#pragma once

#include <iostream>

// 클래스 템플릿
template <typename T>

class Storage
{
private:
	T m_value;

public:
	// 생성자 함수
	Storage(T value)
	{
		m_value = value;
	}

	// 소멸자 함수
	~Storage()
	{

	}

	void print()
	{
		std::cout << m_value << '\n';
	}
};