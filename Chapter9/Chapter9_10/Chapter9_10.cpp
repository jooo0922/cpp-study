#include <iostream>
#include <cassert> // assert() 함수 사용을 위해 포함

using namespace std;

class Fraction
{
private:
	int m_numerator; // 분자 멤버
	int m_denominator; // 분모 멤버

public:
	/* delete 키워드 */
	// 어떤 생성자 함수가 이전 버전에서는 허용되었다가,
	// 다음 버전에서는 허용을 못하도록 막아버리고 싶을 경우 사용
	// 힙 메모리 반납 시 사용하는 delete 키워드랑 별개!
	Fraction(char) = delete;

	/* explicit 키워드 */
	// 만약, 아래 main 함수의 예제 코드에서 살펴본 Converting constructor 기능을 막아버리고 싶다면,
	// 생성자 앞에 'explicit' 키워드를 붙여주면 됨! explicit == '명시적인, 엄격한' 이라는 뜻을 갖고 있는 키워드로써,
	// 말 그대로, 암시적으로 변환하지 말고, 명시적으로, 더 엄격하게 생성자 함수를 호출하라는 의미!
	explicit Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		// 분몯가 0 으로 입력될 것을 대비해서 assert() 를 사용하면 추후 디버깅에 아주 용이해 질 것임. 
		// https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter7/Chapter7_14/Chapter7_14.cpp 참고
		assert(den != 0);
	};

	/*
		복사 생성자

		생성자 함수의 매개변수로 자기 자신과 동일한 인스턴스가 들어오면,
		그 인스턴스를 복사하는 생성자를 '복사 생성자' 라고 함.
	*/
	Fraction(const Fraction& fraction)
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator) // 멤버 초기화 리스트에서 매개변수로 들어온 인스턴스의 멤버들을 복사해주고 있지?
	{
		cout << "Copy constructor called" << endl;
	}

	/* 친구 함수로 등록하여 출력 스트림 연산자 << 오버로딩 */
	// https://github.com/jooo0922/cpp-study/blob/main/Chapter9/Chapter9_02/Chapter9_02.cpp 참고
	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		cout << f.m_numerator << " / " << f.m_denominator << endl;

		return out;
	}
};

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac(7);

	// 이렇게 하면 doSomething() 에 선언된 매개변수로 copy initialization 이 발생하여 복사 생성자가 호출됨.
	doSomething(frac);

	// 이렇게 하는 것도 안될 것 같지만 가능함. 
	// 이때, 컴파일러가 doSomething() 의 매개변수는 Fraction 타입밖에 없는데, 7이 전달되었다고 하면,
	// 그냥 알아서 7을 매개변수로 선언된 Fraction frac 의 생성자 함수의 매개변수로 전달해버림.
	// -> 이렇게 자동으로 변환해주는 것을 'Converting Cosntructor' 라고 함
	//doSomething(7); // 생성자 함수에 explicit 키워드를 붙일 시, 컴파일 에러가 발생함

	// explicit 키워드가 붙은 생성자 함수일 경우, 아래와 같이 명시적으로 생성자 함수를 호출하거나,
	// 이미 생성된 인스턴스를 전달하는 방법을 사용해야겠지!
	doSomething(frac);
	doSomething(Fraction(7));

	/* delete 키워드 테스트 */
	// delete 키워드에 의해 지워진 생성자 함수라서 사용할 수 없다는 컴파일 에러가 뜸.
	Fraction frac2('c');

	return 0;
}