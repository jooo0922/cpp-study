#include <iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		setID(id);
	}

	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};


int main()
{
    return 0;
}
