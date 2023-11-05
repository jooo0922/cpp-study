#include <iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; };
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }
	
	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out;
	}

	/* 단항연산자 오버로딩 */

	// 참고로, 단항 연산자는 앞서 배웠던 것처럼, +a, -a 이런 식으로 하나의 항에만 붙어 작동하는 연산자를 의미!
	// const 를 붙여서 상수 멤버함수로 등록함!
	Cents operator - () const
	{
		return Cents(-m_cents);
	}

	// !(not) operator 단항연산자 오버로딩
	// ! 연산자는 반환값이 boolean 이므로, 반환 타입을 bool 로 정의
	bool operator ! () const
	{
		// 오버로딩 함수에서 반환값을 어떤 기준으로 true / false 로 반환할 지는 문맥 상 결정해야 함!
		// 예를 들어, !Cents(...) 로 했을 때, 
		// m_cents 값이 0 이면 돈이 없으니 true, 0이 아니면 돈이 있으니 false 를 반환하도록 오버로딩 해보자!
		return (m_cents == 0) ? true : false;
	}
};

int main()
{
	Cents cents1(6);
	Cents cents2(0);

	// 단항연산자 오버로딩 테스트
	cout << cents1 << endl;
	cout << -cents1 << endl;
	cout << -Cents(-10) << endl;

	// 여기서 오버로딩된 ! 연산자를 유지하면 auto 는 반환값을 bool 로 자동 형변환 해주고,
	// ! 연산자를 제거하면, auto 는 반환값을 Cents 로 자동 형변환 해줌! -> 오버로딩이 잘 작동한다는 것을 알 수 있음!
	auto temp = !cents1;
	cout << !cents1 << " " << !cents2 << endl;

    return 0;
}