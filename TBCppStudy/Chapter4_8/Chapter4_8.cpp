#include <iostream>

int main()
{
	using namespace std;

	enum Color
	{
		RED,
		BLUE,
	};

	enum Fruit
	{
		BANANA,
		APPLE,
	};

	Color color = RED;
	Fruit fruit = BANANA;

	// 두 열거형 모두 정수 리터럴로 표현되면 0이기 때문에,
	// 정수값이 동일하여 if 조건문이 충족되고 있음...
	if (color == fruit)
		cout << "Color is fruit ? " << endl;

	return 0;
}
