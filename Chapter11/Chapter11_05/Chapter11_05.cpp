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
//class Derived : protected Base // protected inherit
class Derived : private Base // private inherit -> 얘는 자식 클래스 내부보다는, 자식 클래스를 상속받는 "손자 클래스" 에서 차이점을 확인 가능! 
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

// private inherit 으로 상속된 Derived 클래스를 상속받는 손자 클래스
class GrandChild : public Derived
{
public:
	GrandChild()
	{
		// Derived 클래스는 private inherit 으로 상속을 받았기 때문에,
		// 현재 Derived 클래스에 존재하는 m_public 멤버는 private 으로 캡술화되어 있는 것과 같은 상태임.
		// 즉, Derived 에 상속된 멤버들은 '최소한 private 보다 엄격하게' 관리되고 있는 것!
		// 따라서, Derived 를 상속받은 손자 클래스 GrandChild 는 public 멤버였던 m_public 조차 내부에서 접근 불가!
		/*Derived::m_public;
		Derived::m_protected;*/
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