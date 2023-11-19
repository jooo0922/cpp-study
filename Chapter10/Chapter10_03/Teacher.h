#pragma once

#include <string>

// Teacher 클래스 구현
class Teacher
{
private:
	std::string m_name; // 강사 이름 멤버
	// TODO : more members like home address, salary, age, evaluatio, etc.

public:
	Teacher(const std::string& name_in = "No Name")
		: m_name(name_in)
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
