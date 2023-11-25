#include <iostream>

using namespace std;

class Mother
{
private: // 자식 클래스에서 조차 접근 불가
//protected: // 자식 클래스까지는 접근 가능!
	int m_i;

public:
	/*Mother(const int& i_in)
		: m_i(i_in)
	{
		cout << "Mother constructor" << std::endl;
	}*/

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
	Mother mother;
	mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child;
	child.Mother::setValue(1024); // 이런 식으로 자식 클래스 인스턴스를 통해 부모 클래스에 정의된 멤버함수에 접근하는 것도 가능!
	child.setValue(128);
	cout << child.getValue() << endl;

    return 0;
}