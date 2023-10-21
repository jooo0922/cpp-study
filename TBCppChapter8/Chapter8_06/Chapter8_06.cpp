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

/*
	클래스의 소멸자는 언제 써먹을까?
*/
class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length]; // 생성자에서 배열 멤버에 힙 메모리를 동적으로 할당

		//cout << "Constructor " << endl;
	};

	~IntArray()
	{
		// 생성자에서 동적으로 힙 메모리를 할당받은 멤버를
		// 소멸자에서 메모리 반납할 때 사용하기 좋음! 
		// > 특히 캡슐화된 멤버는 소멸자에서 메모리 해제를 해줘야 함
		if (m_arr != nullptr) delete[] m_arr;
	}

	int size() { return m_length; }
};

int main()
{
	//Simple s1(0);
	Simple* s1 = new Simple(0); // 힙 메모리에 동적으로 할당된 Simple 인스턴스
	Simple s2(1); // 스택 메모리에 할당된 Simple 인스턴스

	// 힙 메모리에 동적으로 할당된 메모리를 반납하는 시점에 s1 의 소멸자(Destructor)가 먼저 호출됨
	// delete 로 메모리를 직접 해제하지 않으면, s1 의 소멸자는 호출되지 않음!
	delete s1;

	// 이후, 현재 main() 함수 블록을 벗어나면,
	// 스택 메모리에 할당되어 있던 s2 의 소멸자(Destructor)가 자동 호출됨


	// 소멸자를 사용하기 좋은 예시
	while (true)
	{
		// 그냥 이렇게 무한반복 순회를 돌린다면,
		// IntArray 의 생성자가 호출될 때마다 힙 메모리에 40,000 bytes(4bytes * 10000) 가 동적으로 반복 할당됨.
		// 결국 memory leak 이 발생할 것임...
		IntArray my_int_arr(10000);

		// 원래는 아래와 같이 배열 멤버에 접근해서 delete 해주면 되는데,
		// 해당 멤버가 캡슐화되어 있으니 외부에서 접근할 수가 없겠군!
		// 이럴 때, '소멸자'에서 캡슐화된 멤버를 delete 해주면 딱 좋겠지!
		// delete[] my_int_arr.m_arr;
	}

    return 0;
}