#include <iostream>

/*
	여러 클래스에서 공통적으로 사용되는 타입은 
	별도로 추출해서 헤더파일에 정리해두는 게 좋겠지만,

	특정 클래스 내에서만 사용되는 타입이라면
	nested type 으로 선언하는 게 더 권장되는 방법!
*/

class Fruit
{
public:
	// Fruit 클래스 안에서만 사용되는 전용 타입으로 선언할 수 있음 -> 이런 타입을 'nested type' 이라고 함.
	enum FruitType
	{
		APPLE, BANANA, CHERRY,
	};

	// 클래스 안의 클래스 또한 nested type 의 한 종류
	class InnerClass
	{

	};

	// 클래스 안의 구조체 또한 nested type 의 한 종류
	struct InnerStruct
	{

	};

private:
	FruitType m_type;

public:
	Fruit(FruitType type) : m_type(type)
	{};

	FruitType getType() { return m_type; }
};

int main()
{
	Fruit apple(Fruit::APPLE);

	if (apple.getType() == Fruit::APPLE)
	{
		std::cout << "Apple" << std::endl;
	}
    return 0;
}