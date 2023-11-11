#include <iostream>
#include <cassert> // assert() 함수 사용을 위해 포함

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
};

int main()
{
    return 0;
}