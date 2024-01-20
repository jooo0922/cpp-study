#pragma once

#include <iostream>

// 데이터(resource)를 담고 있는 클래스
class Resource
{
public:
	int m_data[100];

public:
	// 생성자 함수
	Resource()
	{
		std::cout << "Resource constructed" << std::endl;
	}

	// 소멸자 함수
	~Resource()
	{
		std::cout << "Resource destroyed" << std::endl;
	}
};