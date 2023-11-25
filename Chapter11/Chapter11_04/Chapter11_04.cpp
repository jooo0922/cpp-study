#include <iostream>

using namespace std;

class Mother
{
public:
	int m_i;

	Mother(const int& i_in = 0)
		: m_i(i_in)
	{
		cout << "Mother construction " << endl;
	}
};

// derived class (= 유도된 클래스. 자식 클래스)
class Child : public Mother
{
public:
	float m_d;

public:
	Child()
		: Mother(1024), m_d(1.0f)
	{
		cout << "Child construction " << endl;
	}
};

int main()
{
	Child c1;

	// 부모 클래스와 이를 상속받은 자식 클래스의 메모리 사이즈 비교
	cout << sizeof(Mother) << endl;
	cout << sizeof(Child) << endl;

	return 0;
}