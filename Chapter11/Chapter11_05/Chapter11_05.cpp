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

//class Derived : public Base
class Derived : protected Base
{
public:
	Derived()
	{
		m_public = 123;

		// protected 접근 지정자는 상속받은 자식 클래스에서는 접근 가능!
		m_protected = 123;

		// private 접근 지정자는 상속받은 자식 클래스에서 조차 접근 불가!
		//m_private = 123;

		// protected inherit 으로 상속받은 자식 클래스 내부에서는
		// 모든 멤버를 '최소한 protected 보다 엄격하게' 다루더라도 부모의 public, protected 멤버에는 접근 가능! 
		Base::m_public; // 이는 this->m_public; m_public; 으로 선언한 것과 동일함. 부모로부터 상속받은 멤버임을 강조하기 위함!
		Base::m_protected;
		//Base::m_private; // 이건 protected inherit 으로 상속 받을 때에도 접근 불가!
	}
};

int main()
{
	Base base;

	base.m_public = 123;

	// 아래와 같이, protected, private 접근 지정자로 선언된 멤버에는 접근 불가!
	/*base.m_protected = 123; 
	base.m_private = 123; */


	// Derived 클래스가 protected inherit 으로 상속받았다면,
	// 상속받은 모든 멤버를 '최소한 protected 보다 엄격하게 다루겠다'는 의미로 해석하면 됨.
	// 따라서, public 으로 선언된 멤버 m_public 조차 protected 처럼 다뤄져서 외부에서는 접근 불가!
	Derived derived;
	//derived.m_public = 123;

    return 0;
}