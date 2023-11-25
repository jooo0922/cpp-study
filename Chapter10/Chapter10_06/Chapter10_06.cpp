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

	/* 배열 초기화 */
	void reset()
	{
		m_length = 0;
		if (m_data != nullptr)
		{
			delete[] m_data;
			m_data = nullptr;
		}
	}

	/* 배열 크기 조절 */
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

	/* 요소 삽입 */
	void insertBefore(const int& value, const unsigned int& index)
	{
		if (index > m_length - 1)
		{
			// 배열 길이를 초과하는 인덱스를 전달받을 경우 예외 처리
			cout << "index " << index << " exceeded last index " << m_length - 1 << endl;
			return;
		}

		// 요소가 추가된 새로운 배열 길이 계산
		int newLength = m_length + 1;

		// 삽입할 요소의 개수가 추가된 새로운 메모리 동적 할당
		int* newData = new int[newLength];

		for (unsigned int i = 0; i < newLength; i++)
		{
			if (i < index)
			{
				// 삽입될 위치 이전까지의 원본 요소 복사
				newData[i] = m_data[i];
			}
			else if (i == index)
			{
				// 삽입될 위치에 새로운 요소 복사
				newData[i] = value;
			}
			else
			{
				// 삽입될 위치 이후의 원본 요소 복사
				newData[i] = m_data[i - 1];
			}
		}

		// 원본 배열 제거
		delete[] m_data;

		// 새로운 배열 주소값 할당
		m_data = newData;

		// 새로운 배열 길이 할당
		m_length = newLength;
	}

	/* 요소 제거 */
	void remove(const unsigned int& index)
	{
		if (index > m_length - 1)
		{
			// 배열 길이를 초과하는 인덱스를 전달받을 경우 예외 처리
			cout << "index " << index << " exceeded last index " << m_length - 1 << endl;
			return;
		}

		for (unsigned int i = 0; i < m_length; i++)
		{
			// index 이후의 요소들을 1칸 씩 앞으로 당겨서 복사함
			if (i > index)
			{
				int value = m_data[i];
				m_data[i - 1] = value;
			}
		}

		// 요소가 제거된 새로운 배열 길이 계산
		int newLength = m_length - 1;

		// 제거된 요소만큼 새로운 메모리 동적 할당
		int* newData = new int[newLength];

		// 새로운 배열에 원본 배열 복사
		copy(m_data, m_data + newLength, newData);

		// 원본 배열 제거
		delete[] m_data;

		// 새로운 배열 주소값 할당
		m_data = newData;

		// 새로운 배열 길이 할당
		m_length = newLength;
	}

	/* 요소 추가 */
	void push_back(const int& value)
	{
		// 요소가 추가된 새로운 배열 길이 계산
		int newLength = m_length + 1;

		// 추가된 요소만큼 새로운 메모리 동적 할당
		int* newData = new int[newLength];

		// 새로운 배열에 원본 배열 전체 복사
		copy(m_data, m_data + m_length, newData);

		// 새로운 배열의 마지막 요소에 추가할 요소를 복사
		newData[newLength - 1] = value;

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
		// 배열 길이 출력
		out << "Length : " << my_arr.m_length << endl;

		// 배열 요소 출력
		out << "Data : ";
		
		// 배열에 요소가 없을 시 해당 문구 출력
		if (my_arr.m_length == 0) {
			out << "Empty IntArray" << endl;
			return out;
		}

		for (unsigned int i = 0; i < my_arr.m_length; i++)
		{
			out << my_arr.m_data[i] << " ";
		}
		out << endl;

		return out;
	}
};

int main()
{
	IntArray my_arr{ 1, 3, 5, 7, 9 };
	cout << my_arr << endl;

	my_arr.insertBefore(10, 1);
	cout << my_arr << endl;

	my_arr.remove(3);
	cout << my_arr << endl;

	my_arr.push_back(13);
	cout << my_arr << endl;

	my_arr.resize(10);
	cout << my_arr << endl;

	my_arr.resize(3);
	cout << my_arr << endl;

	my_arr.reset();
	cout << my_arr << endl;

    return 0;
}