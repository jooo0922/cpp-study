#include <iostream>

int main()
{
	using namespace std;

	//enum Color
	//{
	//	RED,
	//	BLUE,
	//};

	//enum Fruit
	//{
	//	BANANA,
	//	APPLE,
	//};

	//Color color = RED;
	//Fruit fruit = BANANA;

	//// 두 열거형 모두 정수 리터럴로 표현되면 0이기 때문에,
	//// 정수값이 동일하여 if 조건문이 충족되고 있음...
	//if (color == fruit)
	//	cout << "Color is fruit ? " << endl;

	// 위의 열거형 특성상의 한계를 보완해주는 게 '열거형 클래스' 또는 '영역 제한 열거형'이라고도 함.
	enum class Color
	{
		RED,
		BLUE,
	};

	enum class Fruit
	{
		BANANA,
		APPLE,
	};

	// 이런 식으로, 각 열거형을 할당할 때,
	// 어느 클래스 영역에서 정의된 열거형이다 라는 식으로 '영역을 제한' 해서
	// 정수 리터럴이 같더라도 서로 다른 열거형으로 구별할 수 있게끔 해줌!
	// struct(구조체 열거형)으로도 구현할 수는 있는데, 보통은 클래스 열거형을 많이 쓴다고 함!
	Color color1 = Color::RED;
	Color color2 = Color::BLUE;
	Fruit fruit = Fruit::BANANA;

	// 열거형 클래스를 사용하자마자 
	// 컴파일러가 두 열거형 변수를 비교하지 못하게 막아버림 (에러를 발생시킴)
	//if (color1 == fruit)
	//	cout << "Color is fruit ? " << endl;

	// 대신 같은 클래스 영역 안에 정의된 열거형끼리는 비교 가능!
	// 이런 식으로, 어떻게 보면 열거형을 namespace 로 묶어주는 것과 비슷한 개념!
	if (color1 == color2)
		cout << "Same Color ? " << endl;

	return 0;
}
