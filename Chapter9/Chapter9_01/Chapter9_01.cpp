#include <iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; };
	int getCents() const { return m_cents; }
};

// 이것이 Cents 인스턴스 간 + 연산자를 사용할 때 어떤 기능을 수행할 것인지 오버로딩한 '연산자 오버로딩'
Cents operator + (const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	// 두 개의 Cents 클래스 인스턴스를 더하고 싶다면 어떻게 할까?
	// 즉, 내가 만든 자료형(user defined data type)을 원시 자료형처럼 연산하고 싶다면?
	// 방법이야 여러 가지가 있겠지만, 여기에 가장 적합한 방법은 '산술 연산자 오버로딩'을 활용하는 것!
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;

	return 0;
}