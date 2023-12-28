#pragma once

#include <assert.h> // for assert()
#include <iostream>

using namespace std;

template<typename T>

class MyArray
{
private:
	int m_length; // 배열 크기

	// 배열 첫 번째 요소 포인터 멤버변수
	/*
		이렇게 템플릿으로 타입을 지정하면,

		'이 정적 배열은 int, float, class 등 어떤 타입이라도 가능하다'
		라고 선언한 것으로 보면 됨!
	*/
	T* m_data;

public:
	// 생성자 함수
	MyArray()
	{
		// 멤버변수 초기화
		m_length = 0;
		m_data = nullptr;
	}

	// 생성자 함수 오버로딩
	MyArray(int length)
	{
		// 배열 힙 메모리 동적 할당
		m_data = new T[length];
		m_length = length;
	}

	// 소멸자 함수
	~MyArray()
	{
		reset();
	}

	void reset()
	{
		// 배열에 동적 할당된 메모리 반납 및 멤버변수 초기화
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	// [] 연산자 오버로딩
	T& operator[](int index)
	{
		// assert() 함수로 입력받은 index 가 유효한 지 검사
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	// 배열 크기 getter
	int getLength()
	{
		return m_length;
	}

	// 배열 요소 출력 멤버함수
	void print()
	{
		for (int i = 0; i < m_length; i++)
		{
			cout << m_data[i] << " ";
		}
		cout << endl;
	}
};
