#include <iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0)
	{
		m_cents = cents;
	};

	int getCents() { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	/* 형변환 연산자 int 오버로딩 */
	// 아래와 같이 선언하면, Cents 타입의 클래스를 int 타입으로 형변환하는 연산자 'int' 를 오버로딩 하는 것! 
	operator int()
	{
		cout << "cast here" << endl;
		return m_cents;
	}
};

void printInt(const int& value)
{
	cout << value << endl;
}

int main()
{
	Cents cents(7);

	// 이렇게 int 형변환 연산자를 사용하면 Cents 클래스에 정의된 int 형변환 연산자 오버로딩 내용이 실행된다!
	int value = (int)cents;
	value = int(cents);
	value = static_cast<int>(cents);

	// cents 는 Cents 클래스 타입이므로 int 타입의 입력 매개변수를 전달받는 printInt 함수에 암시적 형변환(= 자동 형변환)이 안되고 있음.
	// 이 때, Cents 클래스를 int 타입으로 형변환 시켜주는 'int' 연산자에 대해 오버로딩하면, 클래스를 암시적 형변환하는 것도 커스터마이징이 가능하다!
	printInt(cents);

	return 0;
}
