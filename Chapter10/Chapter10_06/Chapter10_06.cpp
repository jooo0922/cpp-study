#include <iostream>

using namespace std;

class IntArray
{
private:
	unsigned int m_length = 0; // 정수형 배열의 길이 멤버
	int* m_data = nullptr; // 정수형 배열을 가리키는 포인터 멤버 -> 전달받은 배열 길이만큼 힙 메모리 동적 할당할 것임.

public:
	/* 생성자 */
	IntArray(const unsigned int length)
	{
		initialize(length);
	}

	/* 소멸자 */
	~IntArray()
	{
		// 힙 메모리 반납
		if (m_data != nullptr) delete[] m_data;
	}

	/* 멤버변수 초기화 */
	void initialize(unsigned int length)
	{
		m_length = length; // 배열 길이 멤버 초기화
		m_data = new int[length]; // 힙 메모리에 배열 크기 만큼을 동적 할당하여 주소값 저장
	}
};
int main()
{
    return 0;
}