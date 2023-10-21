#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	int m_id;
	string m_name;

public:
	// 만약, m_name 만 직접 입력받아서 초기화하고, m_id 는 적당한 기본값으로 넣어주는 생성자를 또 만들고 싶다면?
	/*
		아래와 같이, 또 다른 형태의 생성자를 오버로딩 하는 것도 가능은 함!

		그러나, 이런 방법은 객체지향 설계에서 매우 비추천되는 방식!

		왜?
		이렇게 하면 멤버를 초기화하는 로직이 여러 군데에 산재하게 됨.

		멤버를 초기화하는 로직은 한 곳에만 존재하는 것이 좋음!

		이럴 때, 이미 첫 빠따로 만들어 둔 생성자에 구현해 둔
		멤버 초기화 리스트 로직을 가져다 쓸 수 있도록 '위임 생성자',
		즉, 생성자가 생성자를 가져다 쓰는 문법을 사용할 수 있음!
	*/
	Student(const string& name_in)
		//: m_id(0), m_name(name_in)
		: Student(0, name_in)
	{}

	Student(const int& id_in, const string& name_in)
		: m_id(id_in), m_name(name_in)
	{}

	void print()
	{
		cout << m_id << " " << m_name << endl;
	}
};

int main()
{
	Student st1(0, "Jack Jack");
	st1.print();

	Student st2("Dash");
	st2.print();

    return 0;
}