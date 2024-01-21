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
	T* m_ptr; // 템플릿 파라미터로 타입을 지정한 포인터 멤버변수

public:
	// 기본 생성자 함수 (default constructor)
	AutoPtr(T* ptr = nullptr)
		: m_ptr(ptr)
	{
		std::cout << "AutoPtr default constructor " << std::endl;
	}

	// 소멸자 함수
	~AutoPtr()
	{
		std::cout << "AutoPtr destructor " << std::endl;

		// 소멸자에서 포인터 멤버에 주소값이 할당되어 있을 경우, 
		// 동적 할당된 메모리를 반납함.
		if (m_ptr != nullptr) delete m_ptr;
	}

	// 복사 생성자를 통해 '메모리 deep copy' 구현
	// 복사 생성자 관련 https://github.com/jooo0922/cpp-study/blob/main/Chapter9/Chapter9_09/Chapter9_09.cpp 참고
	AutoPtr(const AutoPtr& a)
	{
		std::cout << "AutoPtr copy constructor " << std::endl;

		// 동일한 크기(T 타입)의 메모리를 동적 할당해놓고,
		// 매개변수로 전달된 동일한 타입의 인스턴스 a.m_ptr 이 가리키는 데이터를 de-referencing 하여
		// 현재 인스턴스의 m_ptr 에 동적 할당된 메모리에 그 데이터를 deep copy 함!
		// 만약, 이 템플릿 파라미터 T 가 Resource.h 에 있는 Resource 클래스라면,
		// Resource 클래스 내에 대입 연산자 오버로딩 함수가 실행됨으로써 deep copy 가 실행되겠지!
		// -> 그러면 마찬가지로 연산이 느려지겠군!
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// 대입 연산자(=) 오버로딩을 통해 '메모리 deep copy' 구현
	AutoPtr& operator = (const AutoPtr& a)
	{
		std::cout << "AutoPtr copy assignment " << std::endl;

		// 인스턴스가 자기 자신으로 대입될 경우 아무 것도 하지 않고 함수 종료
		if (&a == this)
		{
			return *this;
		}

		// 일단, 이미 자신이 갖고 있는 포인터 주소값이 가리키는 메모리는 반납해버림
		if (m_ptr != nullptr)
		{
			delete m_ptr;
		}

		// 동일한 크기(T 타입)의 메모리를 동적 할당해놓고,
		// 매개변수로 전달된 동일한 타입의 인스턴스 a.m_ptr 이 가리키는 데이터를 de-referencing 하여
		// 현재 인스턴스의 m_ptr 에 동적 할당된 메모리에 그 데이터를 deep copy 함!
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

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