#include <iostream>

using namespace std;

class Something
{
public:
	int m_value = 0;

	void setValue(int value) { m_value = value; }
	int getValue() { return m_value; }
};

int main()
{
    return 0;
}