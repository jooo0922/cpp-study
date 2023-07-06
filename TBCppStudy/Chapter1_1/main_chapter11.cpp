#include <iostream> // iostream > "input output stream" > 입력과 출력을 구현한 코드를 현재 cpp 파일 안에 포함시킨다는 뜻!
// #include 처럼 앞에 #이 붙는 것들을 'Preprocessor directive(전처리기)' 라고 함!

// 운영체제가 프로그램을 시작할 때, "main" 이라는 이름의 함수를 가장 먼저 찾게 됨.
// 만약, main 이라는 이름의 함수가 없다면, 운영체제는 아무 것도 할 수 없어서 프로그램이 종료됨. > main 이라는 이름을 갖는 함수가 반드시 필요한 이유!
// 괄호 안에 void > 입력 타입(아무런 입력이 없으므로 void), 왼쪽 int 는 출력 타입
int main(void)
{
	// 정수형 변수를 선언
	// int 라는 정수형 데이터를 담을 수 있는 메모리 공간을 할당받는 것
	int x = 2; 
	x = 5; // x의 값은 바뀔수도 있다!
	int y = x + 3; // 2, 3, 5 이런 값들은 'literal(리터럴)' 이라고 함.

	// 아래 1 + 1 과 같이 문장의 구성요소가 되는 식을 Expression(표현식) 이라고 함.
	//(1 + 1) * (3 + 4);

	// std 란, cout 이라는 기능의 함수가 정의된 namespace 를 의미 > 비슷한 기능의 함수들을 묶어놓거나, 이름이 겹치는 함수들을 나눠놓기 위해서 사용하는 것!
	// :: 는 "namespace 안에 들어있는 함수"에 접근할 때 사용
	// << Output Operator 연산자의 일종!
	// 특히, std 라고 되어있는 namespace 는, standard library 의 일부 > Visual Studio 를 설치하면 자동으로 딸려서 설치되는 라이브러리들!
	std::cout << y << std::endl;

	int sight = 10;

	// ...

	// 마법의 물약을 먹어서 시야 거리가 0 > 코드만 봐서는 알 수 없는 내용들을 주석으로 메모해두는 게 좋다!
	sight = 0;

	// '프로그래밍'이란 운영체제에게 특정 작업을 해달라고 요청하는 행위!
	// main 함수의 반환값을 돌려주는 대상은 '운영체제'
	// 아래 return 문과 같이 기능을 수행하는 문장을 Statement(명령문) 라고 함.
	return 0;
}

// 컴파일러는 '빈칸'과 '빈줄' 을 무시한다. -> 프로그래머의 편의에 따라 얼마든지 넣을 수 있다!

// 주석이란 컴파일러가 컴파일 과정에서 무시하는 것!
/*
	여러 줄에 
	주석 처리를 할 때 사용

	이와 같이 c, c++ 주석은 
	한 줄 주석, 영역을 통째로 주석 
	두 가지 방법이 존재함.

	저작권 표시를 할 때에도 사용하기도 함.

	전체적으로 어떻게 설계할 것인지에 대한 주석

	특정 기능 구현 단계에서는 어떻게 구현한다는 것에 대한 주석 > 수학적으로 복잡한 공식이나 논문 인용 등
*/