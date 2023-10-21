#include <iostream>

using namespace std;

class Something
{
private:
	int m_i;
	double m_d;
	char m_c;
	int m_arr[5]; // c++ 11 부터는 정적 배열도 멤버 초기화 리스트로 초기화 가능

public:
	// 멤버 초기화 리스트 (member initializer list) 로 생성자 호출 시점에 멤버변수들을 미리 초기화할 수 있음.
	// 이떄, m_i() 이렇게 초기화하기 보다는, m_i{} 로 uniform initialization 해주는 게 형변환을 막아 엄격한 타입 체크를 가능하게 해줌.
	// https://github.com/jooo0922/raytracing-study/blob/main/InOneWeekend/InOneWeekend/ray.h 에서 멤버 초기화 리스트를 한 번 사용했었음.
	Something()
		: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1, 2, 3, 4, 5 }
	{
		/*m_i = 1;
		m_d = 3.14;
		m_c = 'a';*/
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