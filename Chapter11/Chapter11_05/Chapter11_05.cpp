#include <iostream>

using namespace std;

class Base
{
public:
	int m_public;

protected:
	int m_protected;

private:
	int m_private;
};

class Derived : public Base
{
public:
	Derived()
	{
		m_public = 123;

		// protected 접근 지정자는 상속받은 자식 클래스에서는 접근 가능!
		m_protected = 123;

		// private 접근 지정자는 상속받은 자식 클래스에서 조차 접근 불가!
		//m_private = 123;
	}
};

int main()
{
	Base base;

	base.m_public = 123;

	// 아래와 같이, protected, private 접근 지정자로 선언된 멤버에는 접근 불가!
	/*base.m_protected = 123; 
	base.m_private = 123; */

    return 0;
}