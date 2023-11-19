#pragma once

#include <iostream> // 출력 스트림 연산자 오버로딩을 위해 포함

// 몬스터 위치를 나타내는 Position2D 클래스 구현
class Position2D
{
private:
	int m_x;
	int m_y;

public:
	Position2D(const int& x_in, const int& y_in)
		:m_x(x_in), m_y(y_in)
	{}

	// TODO : overload operator =

	void set(const Position2D& pos_target)
	{
		set(pos_target.m_x, pos_target.m_y);

		// 이렇게 하기보다는 위와 같이 이미 구현된 멤버함수를 재활용하는 게 낫다!
		// why? 나중에 set 멤버함수 쪽에 수정사항이 생길 때, 재활용된 코드 하나만 수정하면 될 것을,
		// 중복된 코드들이 여기저기 산재되어 있으면 일일이 찾아서 수정해줘야 하기 때문!
		//m_x = pos_target.m_x;
		//m_y = pos_target.m_y;
	}

	void set(const int& x_target, const int& y_target)
	{
		m_x = x_target;
		m_y = y_target;
	}

	// 출력 스트림 연산자 오버로딩을 친구 함수로 등록해서 구현
	friend std::ostream& operator << (std::ostream& out, const Position2D& pos2d)
	{
		out << pos2d.m_x << " " << pos2d.m_y;

		return out;
	}
};
