#include <iostream>

using namespace std;

class Mother
{
private:
	int m_i; // 4 bytes

public:
	Mother(const int& i_in = 0)
		: m_i(i_in)
	{
		cout << "Mother construction " << endl;
	}
};

// derived class (= 유도된 클래스. 자식 클래스)
class Child : public Mother
{
public:
	//float m_d; // 4 bytes
	double m_d; // 8 bytes

public:
	Child()
		: Mother(1024), m_d(1.0f)
	{
		cout << "Child construction " << endl;
	}
};

int main()
{
	Child c1;

	// 부모 클래스와 이를 상속받은 자식 클래스의 메모리 사이즈 비교
	cout << sizeof(Mother) << endl; // 4 bytes

	// 16 bytes (부모한테 물려받은 int m_i (4 bytes) + padding (4 bytes) + double m_d (8 bytes))
	// 참고로, padding 은 구조체 공부할 때 배운 개념인데, 각 멤버들을 메모리에 저장할 때
	// 각 멤버들의 메모리 영역 사이에 추가되는 빈 공간을 padding 이라고 했었지!
	// https://github.com/jooo0922/cpp-study/blob/main/TBCppStudy/Chapter4_10/Chapter4_10.cpp padding 관련 설명 참고!
	cout << sizeof(Child) << endl; 

	/*
		이 메모리 사이즈 비교에서 
		중요한 것은 padding 이 아니고,

		어쨋든 자식 클래스의 메모리 사이즈는
		자식 클래스 자신의 멤버에 대한 메모리 뿐만 아니라,
		부모 클래스의 멤버도 포함할 수 있는 수준의
		더 큰 메모리 사이즈를 할당받아서 사용하게 된다는 것!
	*/

	return 0;
}