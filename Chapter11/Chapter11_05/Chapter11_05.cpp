#include <iostream>

using namespace std;

class Base
{
public:
	int m_public;

protected:
	int m_protected;

private:
	int m_private;
};

int main()
{
	Base base;

	base.m_public = 123;

    return 0;
}