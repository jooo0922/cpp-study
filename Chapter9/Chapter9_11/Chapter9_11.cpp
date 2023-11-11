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

	// 가장 좋은 방법은 복사 생성자에 깊은 복사를 직접 구현하는 것이지만,
	// 만약, 복사 생성자를 직접 구현할 시간이 없다면, 
	// 미봉책으로라도, '컴파일러가 자동으로 추가해주는 복사 생성자는 쓰지 마!' 라는 의미로
	// 아래와 같이 복사 생성자에 delete 키워드를 붙여주는 방법도 있음
	// MyString(const MyString& source) = delete;

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

	/* 대입 연산자(=) 오버로딩 내에서 '깊은 복사(deep copy)' 구현을 통한 해결 */
	MyString& operator = (const MyString& source)
	{
		cout << "Assignment operator " << endl;

		/*
			복사 생성자에서는 불가능한 일이지만, 
			대입 연산자는 '자기 자신을 할당' 하는 일이 발생할 수 있음.
		
			예를 들어,
			MyString hello("Hello");
			hello = hello;

			이런 바보 짓을 할 수가 있는데,
			개발자 입장에서는 별 것 아닌 것처럼 보이지만,
			컴파일러 입장에서는 엄청난 문제를 일으킬 수 있으므로,
			아래와 같이 self-assignment (자기 할당)을 방지하는 로직을 우선 추가한 것.
		*/ 
		if (this == &source)
		{
			// 복사된 인스턴스 자신의 주소값과 원본의 주소값이 동일하면( = self-assignment 를 하려는 시도라면), 
			// 복사된 인스턴스를 de-referencing 하여 자기 자신을 반환하고 오버로딩 종료. 
			return *this;
		}

		/*
			복사 생성자는 처음 생성되는 것이므로,
			복사본 멤버에 값이 무조건 비어있는 상태이나,

			대입 연산자는
			이전에 한 번 대입을 해놓고,
			이후에도 여러 번 대입을 할 수 있음.

			그럴 경우, 
			이전에 대입했을 때 복사본 멤버에 복사된 값이 
			이미 존재할 수 있으므로,

			복사본 멤버에 이미 존재하는 복사된 값, 또는,
			그것이 포인터 주소값이라면 
			이미 동적 할당된 메모리를 먼저 깨끗하게 제거하는 작업을 해줌.
		*/
		delete[] m_data;
		
		// 일단 문자열 길이 멤버의 값은 원본에서 그대로 복사해 와도 됨.
		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			// 복사 생성자에서 구현했던 것과 마찬가지로,
			// 복사본 멤버에 새로운 메모리를 동적 할당시켜서 원본 멤버의 값을 직접 복사함.

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

		// 대입 연산자는 항상 복사본 인스턴스 자신을 de-referencing 하여 반환
		return *this;
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


	/* 대입 연산자 vs 복사 생성자 실행되는 상황별 차이점 */

	// 여기서는 assignment operator(=) 을 사용했지만,
	// 이것은 대입 연산자로써 사용된 것이 아니라, '복사 생성자 호출'로써 사용된 것임!
	// 왜냐하면, 변수의 선언과 초기화를 동시에 할 경우, 대입 연산자가 아닌 '복사 생성자'가 실행됨!
	//MyString str1 = hello;

	// 그래서 가급적 '복사 생성자가 실행'됨을 명시하기 위해, 
	// 아래와 같이 initialization 을 다른 문법으로 표기하는 게 더 가독성 있는 코딩!
	MyString str1(hello);

	// 변수의 선언과 대입이 분리될 경우, 대입 연산자가 실행됨!
	MyString str2;
	str2 = hello; // 여기서 비로소 대입 연산자 오버로딩이 실행되는 것!

    return 0;
}

/*
	사실, 이 모든 문제들은
	최신 C++ 컨테이너인
	std::string 을 사용하면 아무런 고민을 안해도 되는 문제임!

	다만, 이런 문제가 존재하기 때문에,
	이를 c++ 에서는 이러한 방식으로 해결할 수 있다는 사실 정도는

	인지하고 있어야 함!
*/