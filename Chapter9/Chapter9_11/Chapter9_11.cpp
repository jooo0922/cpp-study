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


	/* 아래 main() 함수의 안쪽 scope 에서 발생한 문제 해결방법 */

	/* 복사 생성자 (copy constructor) 내에서 '깊은 복사(deep copy)' 구현을 통한 해결 */
	MyString(const MyString& source)
	{
		cout << "Copy constructor" << endl;

		// 일단 문자열 길이 멤버의 값은 원본에서 그대로 복사해 와도 됨.
		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			// 원본의 m_data 문자열 배열 멤버의 주소값이 존재할 경우,
			// 즉, 원본의 해당 멤버에 힙 메모리를 동적 할당 했다는 증거이므로,
			// 복사본 인스턴스의 멤버에는 '주소값'이 아닌 '새로운 메모리 동적 할당'을 해줘야 함!
			// 이래야 main() 함수 안쪽 scope 에서 소멸자에 의해 메모리가 제거될 때, 원본 멤버의 메모리 공간은 건들지 않게 됨!

			/* 
				이처럼, 
				클래스 인스턴스를 복사할 때,
				
				원본 멤버가 포인터로 선언되어 있을 시,
				원본 멤버에 들어있는 '주소값만' 
				복사본 멤버에 복사하는 것을 '얕은 복사(shallow copy)' 라 하고,

				복사본 멤버에 '새로운 힙 메모리를 동적 할당' 하는 것을
				'깊은 복사(deep copy)' 라고 함!
			*/

			m_data = new char[m_length]; // char 타입 문자열 배열을 힙 메모리에 동적 할당함.

			for (int i = 0; i < m_length; i++)
			{
				// 매개변수로 전달받은 문자열 배열의 각 값들을 m_data 문자열 배열 멤버에 차례대로 복사 할당
				m_data[i] = source.m_data[i];
			}
		}
		else
		{
			// 만약 원본 멤버에 주소값이 없었다면,
			// 복사본 멤버도 nullptr 로 초기화함.
			m_data = nullptr;
		}
	}


	/* 소멸자 */
	~MyString()
	{
		// 인스턴스가 사라질 때,
		// m_data 에 동적 할당한 문자열 배열 메모리를 반납함. 
		// -> 항상 클래스 멤버에다가 new 로 동적 할당을 해줬다면, memory leak 방지를 위해 반드시 해야하는 조치!
		delete[] m_data;
	}

	// 각 멤버의 getter 구현
	char* getString() { return m_data; }
	int getLength() { return m_length; }
};

int main()
{
	MyString hello("Hello");

	// 원본의 문자열 멤버 m_data 의 주소값 출력
	// 이때, m_data 는 char* 타입, 즉, '문자열'로 cout 이 인식하므로,
	// 이 문자열이 저장된 메모리의 '주소값'을 출력하기 위해 강제로 (int*) 타입으로 형변환해서 출력한 것!
	cout << (int*)hello.m_data << endl;

	// getter 함수로 원본의 실제 문자열 m_data 출력해보기
	cout << hello.getString() << endl;

	{
		// 별도의 scope 를 하나 정의

		// 그 안에 local 변수를 하나 더 만들고, 거기에 copy initialization 을 수행 -> '복사 생성자'가 호출되겠지?
		// 이때, 클래스 안에 별도로 복사 생성자를 구현하지 않았다면, 컴파일러가 default 로 자동 생성해주는 복사 생성자가 호출됨!
		// 이렇게 생성된 복사 생성자는 말 그대로 멤버 데이터들을 '얕은 복사(shallow copy)'해 줌.
		// 예를 들어, m_data 는 char* 타입의 주소값이 들어있잖아? 
		// 그렇기 때문에 m_data 에 들어있는 주소값도 고대로 복사해 줌!
		MyString copy = hello;

		// copy 의 문자열 멤버 m_data 의 주소값 재출력
		cout << (int*)copy.m_data << endl;

		// getter 함수로 copy 의 실제 문자열 m_data 재출력해보기
		cout << copy.getString() << endl;
		
		// 이 scope 를 벗어나면, MyString copy 의 소멸자 함수가 호출되면서,
		// copy 에 있던 m_data 에 할당했던 문자열 배열 힙 메모리가 OS 에 반납될 것임!
		// -> 근데, 같은 주소값이 복사되어 있다면, 원본 인스턴스인 MyString hello 의 m_data 가 가리키는 메모리도 제거되는 것과 마찬가지겠지!?

		// 이로 인해, 복사본이 scope 를 벗어남으로 인해 소멸자 함수가 호출되면,
		// 복사본의 m_data 주소값이 가리키는 메모리를 delete 시키지만,
		// 복사본(copy)의 m_data 와 원본(hello)의 m_data 가 가리키는 메모리가 동일하기 때문에
		// 결과적으로 원본의 m_data 메모리를 제거해버리는 예상치 못한 문제상황이 발생해버리는 것임...
		// 원본의 멤버변수에 할당된 동적 메모리가 복사본에 의해 영향을 받는 아주 안좋은 상황인 것이지!  
	}

	// getter 함수로 원본의 실제 문자열 m_data 재출력해보기
	cout << hello.getString() << endl;

    return 0;
}