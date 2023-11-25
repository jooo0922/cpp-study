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
		out << teacher.m_name;
		return out;
	}
};