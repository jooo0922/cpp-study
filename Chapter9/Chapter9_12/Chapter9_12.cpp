#include <cassert>
#include <iostream>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
	unsigned m_length = 0; // Int 배열의 길이
	int* m_data = nullptr; // 멤버에 메모리를 동적 할당받는 구조이군!

public:
	/* 생성자 */
	IntArray(unsigned length)
		: m_length(length)
	{
		// 생성자 함수에서 매개변수로 배열 길이를 받으면,
		// 자동으로 배열이 사용할 메모리를 길이만큼 동적으로 할당해 줌.
		m_data = new int[length];
	}

	/* 소멸자 */
	~IntArray()
	{
		// 인스턴스 소멸 시 동적 할당된 멤버의 메모리 반납
		delete[] this->m_data;
	}

	/* 배열 멤버 m_data 출력을 용이하게 하도록 출력 연산자 오버로딩 */
	friend ostream& operator << (ostream& out, IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; i++)
		{
			out << arr.m_data[i] << " ";
		}
		out << endl;
		return out;
	}
};

int main()
{
	// 정적 배열 생성 시, 아래와 같이 우변에 initialization list 를 사용해서 배열을 간편하게 초기화할 수 있었음
	int my_arr1[5] = { 1, 2, 3, 4, 5 };
	
	// 동적 할당 배열을 생성할 경우에도 마찬가지!
	int *my_arr2 = new int[5]{ 1, 2, 3, 4, 5 };

	// initializer_list 라이브러리를 include 할 경우,
	// 아래와 같이 auto 키워드로 자동 형변환을 시도했을 때, std::initializer_list<int> 타입으로 형변환 시켜줌!
	auto il = { 10, 20, 30 };

	return 0;
}