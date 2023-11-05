#include <iostream>

using namespace std;

class Digit
{
private:
	int m_digit;
public:
	Digit(int digit = 0) : m_digit(digit) {}

	friend ostream& operator << (ostream& out, const Digit& d)
	{
		out << d.m_digit;
		return out;
	}

	/* 증감 연산자 오버로딩 */
	
	// 증감 연산자는 prefix 냐 postfix 냐에 따라 작동 방식이 달랐음!
	// ex> ++i 와 i++ 가 작동 방식이 달랐음!

	// 먼저 prefix 증감 연산자부터 오버로딩 해보자
	// 증감 연산자는 변수 자기 자신에 저장된 값에 변화를 주는 것이므로,
	// 반환 타입도 인스턴스 자기 자신(Digit& 즉, 참조변수 타입)으로 선언해줘야 함.
	Digit& operator ++ ()
	{
		++m_digit;
		return *this; // 반환값이 자기 자신이어야 하므로, 인스턴스 자신을 가리키는 포인터 this 의 de-referencing 을 반환
	}

	// postfix 증감 연산자 오버로딩도 마저 구현해보자
	// 여기서 외워야 할 부분이 있는데, postfix 증감 연산자 오버로딩과 prefix 오버로딩을 구분하는 방법은,
	// 아래와 같이 파라미터에 더미로 아무거나(int) 를 넣으면 postfix 오버로딩이고,
	// 파라미터에 아무 것도 넣지 않으면 prefix 오버로딩으로 컴파일러가 인식함.
	Digit operator ++ (int)
	{
		// postfix 증감연산자는 먼저 자기 자신을 반환하고 증감을 시키는 특이한 구조이므로,
		// 반환할 자기 자신을 임시로 저장해 둘 변수를 먼저 생성해줘야 함.
		Digit temp(m_digit);
		
		// 그리고 나서, 자기 자신을 증감시킴
		//++m_digit; // 이렇게 할 수도 있지만, 우리는 prefix 증감 연산자를 이미 오버로딩 해놨었지?
		++(*this); // 따라서, 인스턴스 자기 자신의 de-referencing 을 통해, 이미 오버로딩한 prefix 증감 연산자를 사용하는 것도 가능!
		
		return temp;
	}
};

int main()
{
	/* 증감 연산자 오버로딩 멤버 함수 테스트 */

	Digit d(5);

	// prefix
	cout << ++d << endl;
	cout << d << endl;
	
	// postfix
	cout << d++ << endl;
	cout << d << endl;
    
	return 0;
}