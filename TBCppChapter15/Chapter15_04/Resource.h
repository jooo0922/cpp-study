#pragma once

#include <iostream>

// 메모리가 동적 할당된 데이터(resource)를 담고 있는 클래스
class Resource
{
public:
	int* m_data = nullptr; // 이 포인터 멤버변수에 동적 배열의 메모리를 할당하게 됨
	unsigned m_length = 0; // 동적 배열의 길이

public:
	// default constructor (기본 생성자)
	Resource()
	{
		std::cout << "Resource default constructed" << std::endl;
	}

	// 매개변수로 입력받은 길이만큼 메모리를 할당하는 생성자 함수 오버로딩
	Resource(unsigned length)
	{
		std::cout << "Resource length constructed" << std::endl;

		// 이 클래스의 인스턴스를 가리키는 포인터(this)를 통해 동적 배열의 메모리 할당
		this->m_data = new int[length];
		this->m_length = length;
	}

	// 복사 생성자 오버로딩
	Resource(const Resource& res)
	{
		std::cout << "Resource copy constructed" << std::endl;

		// 매개변수로 전달받은 Resource 인스턴스와 동일한 크기의 메모리를 동적 할당함
		Resource(res.m_length);

		// 매개변수로 전달받은 Resource 인스턴스의 데이터들을 일일이 복사함
		// 이를 'deep copy' 라고 하며, 이는 시간이 걸리는 작업!
		for (unsigned i = 0; i < m_length; i++)
		{
			m_data[i] = res.m_data[i];
		}
	}

	// 소멸자 함수
	~Resource()
	{
		std::cout << "Resource destroyed" << std::endl;

		// 동적 할당된 메모리의 주소값이 존재하면, 해당 메모리를 반납함
		if (m_data != nullptr)
		{
			delete[] m_data;
		}
	}

	// 대입 연산자(=) 오버로딩을 통해 '메모리 복사' 구현
	Resource& operator = (Resource& res)
	{
		std::cout << "Resource copy assignment" << std::endl;

		// 인스턴스가 자기 자신으로 대입될 경우 아무 것도 하지 않고 함수 종료
		if (&res == this)
		{
			return *this;
		}

		// 이미 자신이 갖고 있는 동적 할당 메모리는 반납해버림.
		if (this->m_data != nullptr)
		{
			delete[] m_data;
		}

		// 대입된 인스턴스 res 에 할당된 크기 만큼의 메모리를 새롭게 동적 할당받음
		m_length = res.m_length;
		m_data = new int[m_length];

		// 매개변수로 전달받은 Resource 인스턴스의 데이터들을 일일이 복사함
		// 이를 'deep copy' 라고 하며, 이는 시간이 걸리는 작업!
		for (unsigned i = 0; i < m_length; i++)
		{
			m_data[i] = res.m_data[i];
		}

		// 마지막으로, 자기 자신을 de-referencing 하여 반환
		return *this;
	}

	// 복사된 데이터를 출력하는 util
	void print()
	{
		for (unsigned i = 0; i < m_length; i++)
		{
			std::cout << m_data[i] << " ";
		}

		std::cout << std::endl;
	}
};