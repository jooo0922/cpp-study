#include <iostream>

using namespace std;

class IntList
{
private:
	int m_list[10];

public:
	/*void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}*/

	/* 첨자 연산자(Subscript operator. []) 오버로딩 */
	// 반환 타입은 정수형 정적배열 m_list 의 요소 그 자체이므로, int 형 참조변수로 선언!
	// 참조변수를 반환함으로써, 값을 읽어들일 수도 있고, = 연산자로 값을 직접 변경할 수도 있게 하려고 한 것!
	// 매개변수는 const int 타입의 입력 매개변수로 선언했는데, 나중에 Map 같은 자료구조 구현할 때에는 string 타입도 사용 가능!
	int& operator [] (const int index)
	{
		return m_list[index];
	}
};

int main()
{
	// 기존에 배운 지식으로는 아래와 같이 [] 연산자를 대체할 수도 있을 것임.
	/*IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;*/

	/* 첨자 연산자 오버로딩 멤버함	수 테스트 */
	IntList my_list;
	my_list[3] = 10;
	cout << my_list[3] << endl;

    return 0;
}