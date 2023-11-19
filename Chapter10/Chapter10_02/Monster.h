#pragma once

#include <string>
#include "Position2D.h" // Position2D 클래스 사용을 위해 포함

// Monster 클래스 구현
class Monster
{
private:
	std::string m_name; // 몬스터 이름 멤버
	Position2D m_location; // 몬스터 위치 멤버를 클래스로 별도 추출 -> 깔끔해 짐.
	//int m_x; // 몬스터 위치 멤버
	//int m_y;

public:
	Monster(const std::string name_in, const Position2D& pos_in)
		: m_name(name_in), m_location(pos_in)
	{}

	// 몬스터 위치 변경 멤버 함수
	void moveTo(const Position2D& pos_target)
	{
		/*
			아래와 같이,

			상위 클래스인 Monster 는
			하위 클래스인 Position2D 가 '잘은 모르지만, set() 으로 위치값을 변경할 수 있구나'
			라는 인터페이스만 알면 충분하고,

			내부에서 그 동작이 '어떻게(How)' 구현되는지는 모를수록 좋다!
		*/
		m_location.set(pos_target);
		/*m_x = x_target;
		m_y = y_target;*/
	}

	// 출력 스트림 연산자 오버로딩을 친구 함수로 등록해서 구현
	friend std::ostream& operator << (std::ostream& out, const Monster& monster)
	{
		// 아래와 같이 monster.m_location 을 출력 스트림 중간에 끼워주면,
		// Position2D 클래스 안에 등록된 출력 스트림 오버로딩도 같이 실행된다!
		out << monster.m_name << " " << monster.m_location;

		return out;
	}
};