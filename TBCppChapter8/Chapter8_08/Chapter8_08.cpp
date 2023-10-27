#include "Calc.h"

int main()
{
	/* 인스턴스 자신(*this)를 반환하는 메서드를 활용한 멤버함수 연쇄 호출(member function chaining) */
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print();

	// 아래와 같이 인스턴스를 생성 직후에 바로 메서드 체이닝을 사용하는 것도 가능함!
	Calc(10).add(10).sub(1).mult(2).print();

    return 0;
}