#pragma once

#include "Person.h"

// Teacher 클래스 구현
class Teacher : public Person
{
private:

public:
	Teacher(const std::string& name_in = "No Name")
		: Person(name_in)
	{
		// 자식 클래스 인스턴스 포인터 변수인 this 를 통해 부모 클래스의 getter 함수에 접근 및 사용이 가능함! 
		//this->getName();
	}

	// 출력 스트림 연산자 오버로딩을 친구 함수로 등록
	friend std::ostream& operator << (std::ostream& out, const Teacher& teacher)
	{
		// m_name 이 부모 클래스 Person 의 멤버이긴 하지만, private 접근 지정자로 막혀 있음.
		// public, protected 로 변경하면 쉽게 접근 가능하나, 이러한 초보적인 방법보다 
		// 아래와 같이 부모 클래스의 getter 를 사용해서 우회적으로 접근하는 게 더 권장됨!
		//out << teacher.m_name;

		// 또한, 자식 클래스 Teacher 의 인스턴스가 const 로 (위 두 번째 매개변수 참고) 지정되어 있으므로,
		// 부모 클래스 Person 에 정의된 getter 함수인 getName() 은 '상수 멤버함수' 로 정의되어 멤버변수의 불변을 보장해줘야 함!
		// https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter8/Chapter8_09/Chapter8_09.cpp 상수 멤버함수 관련 참고!
		out << teacher.getName();
		return out;
	}
};