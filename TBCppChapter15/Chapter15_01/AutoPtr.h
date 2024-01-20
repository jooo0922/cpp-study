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

	// de-referencing 연산자(*)를 상수 함수로 오버로딩
	T& operator*() const { return *m_ptr; }

	// 포인터 멤버 참조 연산자(->)를 상수 함수로 오버로딩
	T* operator->() const { return m_ptr; }

	// 현재 포인터 멤버변수가 null 인지 검사하는 상수 멤버함수
	bool isNull() const { return m_ptr == nullptr; }
};