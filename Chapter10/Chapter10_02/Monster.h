#pragma once

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
};