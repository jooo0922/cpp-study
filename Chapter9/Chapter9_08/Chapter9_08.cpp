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
};

void printInt(const int& value)
{
	cout << value << endl;
}

int main()
{
	Cents cents(7);

	// cents 는 Cents 클래스 타입이므로 int 타입의 입력 매개변수를 전달받는 printInt 함수에 암시적 형변환이 안되고 있음.
	// 이러한 형변환을 오버로딩 할 수도 있다!
	//printInt(cents);

	return 0;
}
