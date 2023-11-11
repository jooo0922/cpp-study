#include <iostream>
#include <cassert> // assert() 함수 사용을 위해 포함

using namespace std;

class Fraction
{
private:
	int m_numerator; // 분자 멤버
	int m_denominator; // 분모 멤버

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

int main()
{
	Fraction frac(3, 5);

	return 0;
}