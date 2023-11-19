#pragma once

#include <iostream> // 출력 스트림 연산자 오버로딩을 위해 포함
#include <string>

// Monster 클래스 구현
class Monster
{
private:
	std::string m_name; // 몬스터 이름 멤버
	int m_x; // 몬스터 위치 멤버
	int m_y;

public:
	Monster(const std::string name_in, const int& x_in, const int& y_in)
		: m_name(name_in), m_x(x_in), m_y(y_in)
	{}

	// 몬스터 위치 변경 멤버 함수
	void moveTo(const int& x_target, const int& y_target)
	{
		m_x = x_target;
		m_y = y_target;
	}

	// 출력 스트림 연산자 오버로딩을 친구 함수로 등록해서 구현
	friend std::ostream& operator << (std::ostream& out, const Monster& monster)
	{
		out << monster.m_name << " " << monster.m_x << " " << monster.m_y << std::endl;

		return out;
	}
};