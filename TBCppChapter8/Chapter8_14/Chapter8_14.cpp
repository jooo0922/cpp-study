#include <iostream>

enum FruitType
{
    APPLE, BANANA, CHERRY,
};

class Fruit
{
private:
	FruitType m_type;

public:
	Fruit(FruitType type) : m_type(type)
	{};

	FruitType getType() { return m_type; }
};

int main()
{
	Fruit apple(APPLE);

	if (apple.getType() == APPLE)
	{
		std::cout << "Apple" << std::endl;
	}
    return 0;
}