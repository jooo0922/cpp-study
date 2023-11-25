#include <iostream>

using namespace std;

class Mother
{
private: // 자식 클래스에서 조차 접근 불가
//protected: // 자식 클래스까지는 접근 가능!
	int m_i;

public:
	Mother(const int& i_in)
		: m_i(i_in)
	{
		cout << "Mother constructor" << std::endl;
	}

	// 자식 클래스 생성자 함수가 찾아서 호출하도록 만든 비어있는 기본 생성자
	Mother()
		: m_i(0)
	{

	}

	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}
};

// Mother 클래스를 상속받는 Child 클래스를 선언!
class Child : public Mother // 상속'받은' 클래스를 derived class 라고도 표현함.
{
private:
	double m_d;

public:
	// 자식 클래스 생성자를 추가하면, 자식 클래스 생성자는 기본적으로 부모 클래스의 기본 생성자를 자동으로 호출함.
	// 이때, 부모 클래스의 생성자가 별도로 정의되어 있다면, 자식 클래스 생성자와 매개변수 등이 맞지 않을 경우 컴파일 에러를 발생시킴.
	// 따라서, 부모 클래스에서 정의한 생성자 이외에 비어있는 기본 생성자 아무거나 추가해놓으면, 자식 클래스는 해당 기본 생성자를 자동으로 찾아와서 호출함!
	Child(const int& i_in, const double& d_in)
		//: m_i(i_in), m_d(d_in) // 멤버 초기화 리스트 기본 문법으로는 부모 클래스의 멤버변수까지 초기화할 수 없음!
		: Mother(i_in), m_d(d_in) // 멤버 초기화 리스트에서 부모 클래스의 기본 생성자에 곧바로 매개변수를 전달하여 초기화하는 더 우아한 방식!
	{}

	void setValue(const int& i_in, const double& d_in)
	{
		// m_i 를 protected 접근지정자로 지정해서 직접 부모 클래스 멤버에 할당하는 방법도 있겠지만,
		// 부모 클래스의 int 타입 setter 멤버함수를 가져와서 사용하도록 Mother::~ 문법을 사용하는 것도 가능함!
		//m_i = i_in;
		Mother::setValue(i_in);

		// 자식 클래스 멤버 m_d 별도로 할당
		m_d = d_in;
	}

	// 부모 클래스에 있는 동일한 이름의 멤버함수와 별개로 double 타입에 대한 getter 를 자식 킅래스에서 별도로 구현 
	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};

int main()
{
	Mother mother(1024);
	//mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child(1024, 128);
	//child.Mother::setValue(1024); // 이런 식으로 자식 클래스 인스턴스를 통해 부모 클래스에 정의된 멤버함수에 접근하는 것도 가능!
	//child.setValue(128);
	cout << child.Mother::getValue() << endl;
	cout << child.getValue() << endl;

    return 0;
}