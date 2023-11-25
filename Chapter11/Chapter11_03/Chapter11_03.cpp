#include <iostream>

class Mother
{
public:
	int m_i;
};

// derived class (= 유도된 클래스. 자식 클래스)
class Child : public Mother 
{
public:
	Child()
	{

	}
};

int main()
{
    return 0;
}