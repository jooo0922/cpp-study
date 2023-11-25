#include <iostream>

using namespace std;

class Mother
{
private:
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
class Child : public Mother
{

};

int main()
{
	Mother mother;
	mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child;
	child.setValue(128);
	cout << child.getValue() << endl;

    return 0;
}