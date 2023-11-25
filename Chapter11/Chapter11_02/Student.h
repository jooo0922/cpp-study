#pragma once

#include "Person.h"

class Student : public Person
{
private:
	int m_intel; // 학생의 지적능력 지수 멤버

public:
	Student(const std::string& name_in = "No Name", const int& intel_in = 0)
		: Person(name_in), m_intel(intel_in) // 자식 클래스 생성자를 통해 부모 클래스(Person) 생성자를 호출함으로써, 부모 클래스 멤버변수 m_name 초기화에 대한 책임이 옮겨졌다!
	{}

	void setIntel(const int& intel_in)
	{
		m_intel = intel_in;
	}

	int getIntel()
	{
		return m_intel;
	}

	void study()
	{
		std::cout << getName() << " is studying " << std::endl;
	}

	// 출력 스트림 연산자 오버로딩을 친구 함수로 등록
	friend std::ostream& operator << (std::ostream& out, const Student& student)
	{
		out << student.getName() << " " << student.m_intel;
		return out;
	}
};