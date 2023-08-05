#include <iostream>
#include "MyConstants.h"

/*
	이 변수 a 를 외부 .cpp 파일에서 사용하려고 할 때,
	값을 초기화해주지 않으면 linking 에러가 뜸!

	즉, 컴파일러까지는 문법적으로 문제 없으니 OK!
	그런데, 컴파일된 .obj 파일을 아무리 뒤져도
	a 라는 이름의 변수를 찾을 수 없다는 에러가 발생함.

	그 이유는, 변수 a 를 선언하는 곳에서 값을 초기화해주지 않았기 때문!
*/
extern int a = 123;

void doSomething()
{
	using namespace std;

	cout << "In test.cpp " << Constants::pi << " " << &Constants::pi << endl;
}