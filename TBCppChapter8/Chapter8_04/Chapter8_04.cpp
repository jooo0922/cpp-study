#include <iostream>

using namespace std;

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in) : m_b(m_b_in) {}
};

class Something
{
private:
	// 멤버변수 자체를 초기화하는 것 vs 멤버 초기화 리스트 중 어느 게 더 먼저 우선될까?
	// 정답은 '멤버 초기화 리스트'에서 초기화한 값이 더 우선적으로 적용됨!
	int m_i = 100;
	double m_d = 100.0;
	char m_c = 'F';
	int m_arr[5] = { 100, 200, 300, 400, 500 }; // c++ 11 부터는 정적 배열도 멤버 초기화 리스트로 초기화 가능
	B m_b{ 1024 }; // 클래스인 멤버변수도 멤버 초기화 리스트로 초기화 가능

public:
	// 멤버 초기화 리스트 (member initializer list) 로 생성자 호출 시점에 멤버변수들을 미리 초기화할 수 있음.
	// 이떄, m_i() 이렇게 초기화하기 보다는, m_i{} 로 uniform initialization 해주는 게 형변환을 막아 엄격한 타입 체크를 가능하게 해줌.
	// https://github.com/jooo0922/raytracing-study/blob/main/InOneWeekend/InOneWeekend/ray.h 에서 멤버 초기화 리스트를 한 번 사용했었음.
	Something() : m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1, 2, 3, 4, 5 }, m_b(m_i - 1)
	{
		// 멤버 초기화 리스트 vs 생성자에서 대입한 값 중에서 어떤 게 최종 적용될까?
		// 정답은 당연히 생성자에서 대입한 값이 최종 적용됨.
		// 이는 정확히 말하면, 멤버 초기화 리스트에서 초기화된 값이 생성자에서 다시 덮어쓰여지 것이지!
		m_i = 2;
		m_d = 6.28;
		m_c = 'b';
	};

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& e : m_arr)
		{
			cout << e << " ";
		}
		cout << endl;
	}
};

int main()
{
	Something som;
	som.print();

    return 0;
}