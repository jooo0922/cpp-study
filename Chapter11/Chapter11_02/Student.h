#pragma once

#include <iostream>
#include <string>

class Student
{
private:
	std::string m_name; // 학생 이름 멤버
	int m_intel; // 학생의 지적능력 지수 멤버

	// TODO : add more members like address, phone, favorate food, habits, ...

public:
	Student(const std::string& name_in = "No Name", const int& intel_in = 0)
		: m_name(name_in), m_intel(intel_in)
	{}

	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	void setIntel(const int& intel_in)
	{
		m_intel = intel_in;
	}

	int getIntel()
	{
		return m_intel;
	}

	// 출력 스트림 연산자 오버로딩을 친구 함수로 등록
	friend std::ostream& operator << (std::ostream& out, const Student& student)
	{
		out << student.m_name << " " << student.m_intel;
		return out;
	}
};