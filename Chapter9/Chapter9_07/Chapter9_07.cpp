#include <iostream>

using namespace std;

class Accumulator
{
private:
	int m_counter = 0;

public:
	/* 괄호 연산자 오버로딩 */
	// 기본적으로 괄호 연산자 오버로딩 방법은, 앞서 배운 '첨자 연산자 오버로딩'과 거의 동일함!
	// 그래서 괄호 연산자 오버로딩 방법 자체는 어려운 게 아니고,
	// 여기서는 괄호 연산자 오버로딩을 통해 얻을 수 있는 '함수 객체'에 대해 더 자세히 다룰 것임!
	int operator()(int i) { return (m_counter += i); }

};

int main()
{
	/*
		아래 예시를 보면, 
		그냥 Accumulator 클래스에 accumulate() 같은 멤버함수를 구현해서 
		동일한 작업을 수행할 수도 있겠지만,

		우리는 Accumulator 클래스에 괄호 연산자를 오버로딩해서
		클래스 인스턴스 acc 에 괄호 연산자 () 를 붙였을 때 실행할 작업들을 정의해 줬으므로,
		
		acc(...) 이런 식으로
		인스턴스 옆에 괄호 연산자를 붙여서 마치 함수를 사용하는 것처럼 작동시킴!

		이러한 형태로 사용하는 것을 '함수 객체(Functor)' 라고 함!
	*/
	Accumulator acc;
	cout << acc(10) << endl;
	cout << acc(20) << endl;

    return 0;
}