// Chapter8_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Something
{
private:
	static int s_value;

public:
	int getValue()
	{
		return s_value;
	}

};

int main()
{
	// 인스턴스를 생성하지 않고도 정적 멤버변수에 접근 가능! 
	// -> 이미 정적 메모리 레이아웃에 올라와있는 변수이기 때문!
	// 이게 아주 유용한 기능인데, 해당 멤버변수가 private 으로 캡슐화되어 있다면 무용지물..
	// 너무 아까운 기능인데, private 정적 멤버변수도 인스턴스 없이 바로 접근할 수는 없을까?
	cout << Something::s_value << endl;

	Something s1;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl;

	return 0;
}