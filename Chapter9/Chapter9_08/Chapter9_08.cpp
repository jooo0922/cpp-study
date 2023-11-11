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

// Dollar 클래스
class Dollar
{
private:
	int m_dollars = 0;

public:
	Dollar(const int& input) : m_dollars(input) {};
	
	// 이번에는 Cents 타입 클래스를 Dollar 타입 클래스로 형변환하는, 즉 형변환 오버로딩을 화폐 단위를 변환에 응용해보자!
	operator Cents()
	{
		// 1 달러는 100 센트니까 현재 m_dollars 멤버에 100배를 곱한 값으로 Cents 인스턴스를 생성하여 반환
		return Cents(m_dollars * 100); 
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

	
	/* 클래스 간 형변환 오버로딩 */

	Dollar dol(2);

	// 타입이 다른 클래스 변수에 인스턴스를 할당할 경우, 암시적 형변환에 의해 
	// Dollar 클래스 내에 정의된 Cents 형변환 연산자의 오버로딩이 실행됨
	Cents cents2 = dol; 

	printInt(cents2);

	return 0;
}
