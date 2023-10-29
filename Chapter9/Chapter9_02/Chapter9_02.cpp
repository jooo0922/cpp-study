#include <iostream>

using namespace std;

// Point (좌표값) 을 정의하는 클래스
class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{};

	// getter 정의
	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }
};

int main()
{
    return 0;
}