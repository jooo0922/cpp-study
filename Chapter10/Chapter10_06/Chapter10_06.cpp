#include <iostream>
#include <initializer_list>
#include <algorithm>

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

	/* initializer list 를 사용하여 배열을 생성하기 위해 생성자 오버로딩 */
	IntArray(const initializer_list<int>& list)
		: IntArray(list.size())
	{
		// 동적 할당된 메모리에 initializer list 에 담긴 데이터들을 복사
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}
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

	void reset()
	{
		m_length = 0;
		if (m_data != nullptr)
		{
			delete[] m_data;
			m_data = nullptr;
		}
	}

	void resize(const unsigned int newLength, const int defaultValue = 0)
	{
		// resize 된 배열을 저장할 메모리 공간 동적 할당
		int* newData = new int[newLength];

		// 원본 배열로부터 복사할 길이 계산
		int copyLength = min(m_length, newLength);

		// 새로운 배열에 원본 배열 복사
		copy(m_data, m_data + copyLength, newData);

		for (unsigned int i = copyLength; i < newLength; i++)
		{
			// 만약, resize 한 길이가 원본 배열 길이보다 더 길다면,
			// 늘어난 메모리 공간을 기본값 0으로 초기화
			newData[i] = defaultValue;
		}

		// 원본 배열 제거
		delete[] m_data;

		// 새로운 배열 주소값 할당
		m_data = newData;

		// 새로운 배열 길이 할당
		m_length = newLength;
	}

	// 출력 스트림 연산자 오버로딩을 친구 함수로 등록
	friend std::ostream& operator << (std::ostream& out, const IntArray& my_arr)
	{
		out << "--------------------" << endl;

		// 배열 길이 출력
		out << "Length : " << my_arr.m_length << endl;

		// 배열 요소 출력
		out << "Data : ";
		for (unsigned int i = 0; i < my_arr.m_length; i++)
		{
			out << my_arr.m_data[i] << " ";
		}
		out << endl;

		out << "--------------------" << endl;

		return out;
	}
};

int main()
{
	IntArray my_arr{ 1, 3, 5, 7, 9 };

	cout << my_arr << endl;

    return 0;
}