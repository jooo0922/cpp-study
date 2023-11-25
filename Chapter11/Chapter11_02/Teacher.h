#pragma once

#include "Person.h"

// Teacher 클래스 구현
class Teacher : public Person
{
private:

public:
	Teacher(const std::string& name_in = "No Name")
		: Person(name_in)
	{}

	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	// 출력 스트림 연산자 오버로딩을 친구 함수로 등록
	friend std::ostream& operator << (std::ostream& out, const Teacher& teacher)
	{
		out << teacher.m_name;
		return out;
	}
};