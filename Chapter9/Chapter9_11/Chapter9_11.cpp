#include <iostream>
#include <cassert>

using namespace std;

class MyString
{
public:
	char* m_data = nullptr; // 문자열을 저장할 메모리에 대한 포인터를 할당할 멤버
	int m_length = 0; // 문자열 길이를 저장할 멤버

public:
	/* 생성자 */
	// 문자열을 매개변수로 받음
	MyString(const char* source = "")
	{
		// 문자열이 비어있지 않은지 assert() 로 에러를 명시적으로 출력하도록 함.
		assert(source);

		// 멤버값 초기화
		m_length = std::strlen(source) + 1; // 문자열 마지막에 종료문자 '\0'을 추가하기 위해 문자열 길이를 1만큼 더 늘림
		m_data = new char[m_length]; // char 타입 문자열 배열을 힙 메모리에 동적 할당함.

		for (int i = 0; i < m_length; i++)
		{
			// 매개변수로 전달받은 문자열 배열의 각 값들을 m_data 문자열 배열 멤버에 차례대로 복사 할당
			m_data[i] = source[i]; 
		}

		// 문자열 배열 멤버 마지막에는 종료문자를 할당함.
		m_data[m_length - 1] = '\0';
	}
};

int main()
{
    return 0;
}