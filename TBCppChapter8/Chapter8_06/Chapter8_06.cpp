// Chapter8_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	// 생성자
	Simple(const int& id_in) 
		: m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	};

	// 소멸자 (참고로 소멸자는 파라미터가 없음!)
	~Simple()
	{
		cout << "Destructor " << m_id << endl;
	};
};

int main()
{
    return 0;
}