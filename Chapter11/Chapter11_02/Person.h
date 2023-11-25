#pragma once

#include <iostream>
#include <string>

class Person
{
private:
	std::string m_name;

public:
	/*
		m_name 멤버가 부모 클래스인 Person 으로 이동한 이상,
		이 멤버변수 초기화 및 관리에 대한 책임이 Person 클래스로 이전한 것이다.

		따라서, 해당 멤버로 초기화하는 생성자 함수는
		Person 클래스에 구현을 해줘야 하고,

		Person 클래스를 상속받는 자식 클래스인
		Student 및 Teacher 의 생성자 함수에서 
		Person 의 생성자 함수를 호출하는 구조로 정리가 되어야 한다!
	*/
	Person(const std::string& name_in = "No Name")
		: m_name(name_in)
	{}

	// m_name setter 를 부모 클래스로 이동 
	// 이처럼 자식 클래스들에서 중복되는 코드들은 가급적 부모 클래스로 보내버리는 게 좋음!
	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	// m_name getter 를 부모 클래스로 이동 
	// 이때, 자식 클래스의 인스턴스가 const 로 선언된 상태에서 getName() 호출하려면 멤버함수도 상수 멤버함수로 지정되어야 함
	std::string getName() const
	{
		return m_name;
	}

	void doNothing() const
	{
		std::cout << m_name << " is doing nothing " << std::endl;
	}
};
