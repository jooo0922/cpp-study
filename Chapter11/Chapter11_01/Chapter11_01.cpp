#include <iostream>

using namespace std;

class Mother
{
private:
	int m_i;

public:
	/*Mother(const int& i_in)
		: m_i(i_in)
	{
		cout << "Mother constructor" << std::endl;
	}*/

	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}
};

int main()
{
	Mother mother;
	mother.setValue(1024);
	cout << mother.getValue() << endl;

    return 0;
}