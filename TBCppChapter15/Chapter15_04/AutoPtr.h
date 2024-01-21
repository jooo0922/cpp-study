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


	/* 여기서부터는 move semantics 를 위해 구현한 이동 생성자 및 이동 대입 */

	// 이동 생성자를 통해 '메모리 소유권 이동' 구현
	// 이동 생성자의 매개변수는 R-value 참조변수(&&)로 선언됨.
	// R-value 는 어차피 소멸될 운명의(== 메모리에 제대로 자리잡지 못한, 잠깐 생겼다가 사라질)
	// 리터럴, 인스턴스, 표현식 등을 의미하기 때문에,
	// R-value 를 매개변수로 전달받아서 현재 인스턴스로 주소값이나 메모리 소유권을 '이동'시키더라도,
	// 어차피 외부에서 넘겨준 해당 R-value 에 접근할 일이 더 이상 없으므로, 아무런 지장이 없음!
	AutoPtr(AutoPtr&& a)
		: m_ptr(a.m_ptr) // 매개변수로 전달된 동일한 타입의 인스턴스 a 에서 현재 인스턴스로 m_ptr 의 주소값을 '이동'시킴
	{
		// 매개변수로 전달된 인스턴스 a 에서는 이동된 메모리 소유권 박탈
		/*
			근데, a 가 어차피 R-value 참조변수라면,
			어차피 사라질 운명의 변수인데 뭐하러 nullptr 로 초기화하지?

			그래도, 깔끔하게 코딩하는 입장에서는
			'이 변수에서는 메모리 소유권을 박탈한다'는 의미로
			명시를 해주는 게 좋다고 함.
		*/
		a.m_ptr = nullptr;

		std::cout << "AutoPtr move constructor " << std::endl;
	}

	// 대입 연산자(=) 오버로딩을 통해 '메모리 소유권 이동' 구현 -> '이동 대입'
	// 이동 대입 또한 마찬가지로, 소유권을 이동하더라도 아무런 지장이 없는 R-value 참조변수(&&)를 매개변수로 받도록 함.
	AutoPtr& operator = (AutoPtr&& a)
	{
		std::cout << "AutoPtr move assignment " << std::endl;

		// 인스턴스가 자기 자신으로 대입될 경우 아무 것도 하지 않고 함수 종료
		if (&a == this)
		{
			return *this;
		}

		// 일단, 이미 자신이 갖고 있는 포인터 주소값이 가리키는 메모리는 반납해버림
		if (!m_ptr) delete m_ptr;

		// 그리고, 대입된 인스턴스 a 로부터 m_ptr 주소값을 '이동'시킴 (메모리 소유권이 '이전'됨)
		// 이를 deep copy 와 대비하여 'shallow copy(얕은 복사)' 라고도 함!
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

/*
	복사 생성자 vs 이동 생성자의 성능 차이


	Chapter15_03.cpp > main 에서 Timer 가지고 실행시간 측정해보면,

	복사 생성자 및 복사 대입을 통해
	deep copy 를 실행할 때보다,

	이동 생성자 및 이동 대입을 통해
	'메모리 소유권 이동'을 실행할 때
	실행 시간이 훨씬 더 짧아지는 것을 알 수 있음!

	그만큼 deep copy 가 실행시간이 오래 걸리는
	무거운 작업이라는 것을 알 수 있지!
*/
