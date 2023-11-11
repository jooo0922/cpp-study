#include <iostream>
#include <cassert> // assert() 함수 사용을 위해 포함

using namespace std;

class Fraction
{
private:
	int m_numerator; // 분자 멤버
	int m_denominator; // 분모 멤버

	/* 복사 생성자 호출을 못하게 막기 */

	// 아래와 같이 복사 생성자를 private 으로 캡슐화하면 외부에서 복사 생성자 호출을 못하도록 막을 수 있음!
	//Fraction(const Fraction& fraction)
	//	: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator) // 멤버 초기화 리스트에서 매개변수로 들어온 인스턴스의 멤버들을 복사해주고 있지?
	//{
	//	cout << "Copy constructor called" << endl;
	//}

public:
	Fraction(int num = 0, int den = 1) 
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

Fraction doSomething()
{
	Fraction temp(1, 2);

	cout << &temp << endl;

	return temp;
}

int main()
{
	// 여기서는 일반 생성자 함수가 호출되겠지?
	Fraction frac(3, 5);

	// 여기서 복사 생성자 함수가 호출되겠지?
	//Fraction fr_copy(frac);

	// 이번에는 copy initialization (복사 초기화)
	// 말이 어려워서 복사 초기화지 그냥 동일한 타입을 갖는 인스턴스를 다른 변수에 할당하는 개념
	// 그런데, 중요한 건, 이렇게 값을 복사 할당하는 경우에도 "Copy constructor called" 가 콘솔에 출력됨.
	// 아아!! 복사 초기화를 하더라도 복사 생성자 함수가 호출되는구나!
	//Fraction fr_copy = frac;

	// 주! 인스턴스를 생성하자 마자 생성자의 인자로 전달할 경우에는 복사 생성자가 호출되지 않음!
	// 이렇게 작성한 코드는 컴파일러가 "굳이? 그냥 Fraction fr_copy(3, 10); 으로 하면 되잖아?" 라고 자체적으로 판단해서
	// 그냥 저 코드를 없애버림
	Fraction fr_copy(Fraction(3, 10));

	// 여기서 친구함수로 오버로딩한 출력 스트림 연산자가 실행되겠지?
	cout << frac << " " << fr_copy << endl;


	/* 
		아래 코드를 Debug 모드로 빌드하면 
		doSomething() 함수의 반환값에 의해 
		copy initialization 이 발생하여 복사 생성자가 호출됨.

		반면, Release 모드로 빌드하면, 컴파일러가
		doSomething() 함수 안에서 Fraction temp(1, 2) 와 같이 생성하는 코드는
		해당 함수가 종료되면 굳이 유지할 필요가 없는 변수라고 판단하여,
		해당 인스턴스를 생성하는 코드를 곧바로 Fraction result 쪽으로 옮겨버림.

		그래서 실제로는 Fraction result(1, 2); 이렇게 인스턴스를 생성하는 것으로 컴파일함.
		-> 이로 인해 복사 생성자 함수 호출이 발생하지 않음! 
		애초에 copy initialization 이 성립하지 않으니까!

		-> 실제로 두 변수 temp 와 result 의 주소값을
		Debug 모드에서 찍어보면 서로 다른데,
		Release 모드에서 빌드 후 찍어보면 주소값이 같음! -> 복사가 일어나지 않았다는 뜻!

		이러한 기술을 '반환값 최적화(RVO, Return Value Optimization)' 이라고 함.
	*/
	Fraction result = doSomething();

	cout << &result << endl;

	cout << result << endl;

    return 0;
}