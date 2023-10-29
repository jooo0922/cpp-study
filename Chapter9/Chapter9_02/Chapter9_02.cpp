#include <iostream>
#include <fstream> // 파일 입출력 관련 기능 포함

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

	/*
		입출력 연산자 오버로딩

		얘내들은 이전의 산술 연산자와 달리 약간의 규칙이 있음!

		첫째, 반환타입은 std::ostream& (참조변수) 으로 선언해야 한다.
		둘째, 첫 번째 매개변수는 std::ostream& 타입의 참조변수로 선언해야 하며,
		셋째, 두 번째 매개변수는 const 참조변수 타입의 입력 매개변수로 해당 클래스 객체를 받도록 선언해야 한다!

		또, 입출력 연산자 오버로딩은 멤버함수로 만들 수 없음!

		why? 첫 번째 매개변수로 std::ostream 타입의 참조변수를 받기 때문이라고 함.
		이전에 산술 연산자를 멤버함수로 오버로딩 시, 매개변수를 1개로만 받도록 제한된다고 했었지?

		그런데, 지금 여기서는 첫 번째 매개변수로 std::ostream 타입부터 받아버려야 하니
		두 매개변수 중 하나를 this 포인터로 대체하는 것도 불가능하고, 두 매개변수를 모두 받아야 하므로,
		매개변수 개수가 1개로 제한되는 멤버함수 오버로딩은 적절치 못함!
	*/
	friend std::ostream& operator << (std::ostream& out, const Point& point)
	{
		// 첫 번째 std::ostream 타입의 참조변수 out 에다가 cout 사용하듯이 출력할 데이터를 추가함
		out << "( " << point.m_x << " " << point.m_y << " " << point.m_z << " )";

		// 그리고 나서, std::ostream 타입의 참조변수를 반환함.
		// out 변수를 반환하는 이유는, 출력 스트림을 체이닝하기 위함.
		// std::ostream 을 연달아 반환함으로써, 
		// cout << ~~ << ~~ << ~~ << ..... << endl; 이런 식으로 기존 방식대로 체이닝이 가능하도록 유지하려는 것!
		return out;
	}
};

int main()
{
	// 출력할 파일 스트림 (ofstream == output file stream)을 변수에 정의함.
	// 이제 Point 클래스에서 오버로딩한 출력 연산자 << 를 사용하여
	// Point 의 좌표값을 .txt 파일에 출력시킬(= 기록할) 수 있음!
	// 출력 연산자에 오버로딩한 기능이 파일 스트림 출력 시에도 그대로 적용 가능하여 아주 편리함!
	// 그래서 출력할 파일을 생성할 때에도 유용하겠지!
	ofstream of("out.txt");

	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

	// Point 를 출력할 때, 매번 클래스 안에 print~() 멤버함수 구현하기 귀찮은데
	// 아예 입출력 연산자 <<, >> 등을 오버로딩해서 클래스에 대한 입출력을 직접 정의해서 편리하게 쓸 수는 없을까?
	cout << p1 << " " << p2 << endl;

	// 파일스트림에 각 Point 좌표값을 기록
	of << p1 << " " << p2 << endl;

	of.close(); // 프로그램 종료 전 파일 스트림 종료

    return 0;
}