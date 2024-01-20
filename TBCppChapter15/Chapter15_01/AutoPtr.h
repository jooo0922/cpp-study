#pragma once

#include <iostream>

/*
	아래 클래스는

	c++ 98 부터 도입되었던
	std::auto_ptr<int> 를 직접 구현한 클래스임.

	이는 동적 할당된 메모리를 자동으로 관리해주는
	스마트 포인터의 한 종류였지만,

	좀 더 복잡한 경우에서는 잘 작동하지 않는 경우가 발생해서
	c++ 11 부터는 잘 사용하지 않게 되었고,
	c++ 17 부터는 완전히 사라졌다고(deprecated) 함.

	지금 예제에서는
	이해를 위해 간단한 스마트 포인터의 한 종류로써
	auto_ptr 을 직접 구현해 본 것이고,

	다음 강의에 나올 또 다른 스마트 포인터를
	사용하는 것을 권장한다고 함.
*/

template<class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr; // 템플릿 파라미터로 타입을 지정한 포인터 멤버변수를 nullptr 로 초기화

public:
	// 생성자 함수
	AutoPtr(T* ptr = nullptr)
		: m_ptr(ptr)
	{

	}

	// 소멸자 함수
	~AutoPtr()
	{
		// 소멸자에서 포인터 멤버에 주소값이 할당되어 있을 경우, 
		// 동적 할당된 메모리를 반납함.
		if (m_ptr != nullptr) delete m_ptr;
	}

	// 복사 생성자를 통해 '메모리 소유권 이동' 구현
	// 복사 생성자 관련 https://github.com/jooo0922/cpp-study/blob/main/Chapter9/Chapter9_09/Chapter9_09.cpp 참고
	AutoPtr(AutoPtr& a)
	{
		// 매개변수로 전달된 동일한 타입의 인스턴스 a 에서 현재 인스턴스로 m_ptr 의 주소값을 '이동'시킴
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
	}

	// 대입 연산자(=) 오버로딩을 통해 '메모리 소유권 이동' 구현
	AutoPtr& operator = (AutoPtr& a)
	{
		// 인스턴스가 자기 자신으로 대입될 경우 아무 것도 하지 않고 함수 종료
		if (&a == this)
		{
			return *this;
		}

		// 일단, 이미 자신이 갖고 있는 포인터 주소값이 가리키는 메모리는 반납해버림
		delete m_ptr;

		// 그리고, 대입된 인스턴스 a 로부터 m_ptr 주소값을 '이동'시킴 (메모리 소유권이 '이전'됨)
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		// 마지막으로, 자기 자신을 de-referencing 하여 반환
		return *this;
	}

	// de-referencing 연산자(*)를 상수 함수로 오버로딩
	T& operator*() const { return *m_ptr; }

	// 포인터 멤버 참조 연산자(->)를 상수 함수로 오버로딩
	T* operator->() const { return m_ptr; }

	// 현재 포인터 멤버변수가 null 인지 검사하는 상수 멤버함수
	bool isNull() const { return m_ptr == nullptr; }
};