#include <iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; };
	int getCents() const { return m_cents; }
};


int main()
{
	Cents cents1(6);
	Cents cents1(8);

	return 0;
}