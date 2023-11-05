#include <iostream>
#include <cassert> // assert 를 사용하기 위해 포함

using namespace std;

class IntList
{
private:
	int m_list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

public:
	/*void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}*/

	/* 첨자 연산자(Subscript operator. []) 오버로딩 */
	// 반환 타입은 정수형 정적배열 m_list 의 요소 그 자체이므로, int 형 참조변수로 선언!
	// 참조변수를 반환함으로써, 값을 읽어들일 수도 있고, = 연산자로 값을 직접 변경할 수도 있게 하려고 한 것!
	// 매개변수는 const int 타입의 입력 매개변수로 선언했는데, 나중에 Map 같은 자료구조 구현할 때에는 string 타입도 사용 가능!
	int& operator [] (const int index)
	{
		// 항상 배열의 범위를 넘어서는 index 가 입력될 경우를 대비해서,
		// index 범위를 체크하여, 범위를 벗어날 경우 명시적으로 에러를 출력하는 assert() 를 사용하면
		// 추후 디버깅에 아주 용이해 질 것임. 
		// -> if 문으로 체크할 수도 있긴 한데, 이런 연산자 오버로딩은 매우 자주 사용되도록 구현된 것이기 때문에
		// if 문이 그렇게 자주 사용되면 성능 상의 문제가 있어 assert() 를 사용하는 게 더 적합함!
		// https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter7/Chapter7_14/Chapter7_14.cpp 참고
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

	// IntList 클래스 인스턴스를 const 변수에 생성할 경우,
	// int& 참조변수 타입의 반환값을 변경하려고 하면 컴파일 에러가 발생함.
	// 이를 위해, 첨자 연산자 오버로딩 멤버 함수를 멤버의 불변성을 보장하는 '상수 함수' 로 다시 오버로딩 함으로써,
	// int& 타입의 참조변수를 '읽기'만 할 수 있고, '쓰기'는 못하도록 막을 수 있음!
	// 이때, 상수 함수의 반환 타입 또한 값을 변경하지 못하도록 const 로 지정해줘야 할 것임!
	const int& operator [] (const int index) const
	{
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}
};

int main()
{
	// 기존에 배운 지식으로는 아래와 같이 [] 연산자를 대체할 수도 있을 것임.
	/*IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;*/

	/* 첨자 연산자 오버로딩 멤버함	수 테스트 */
	IntList my_list;
	//my_list[3] = 10;
	cout << my_list[3] << endl;

	/* 포인터 변수에 동적으로 IntList 클래스 인스턴스를 생성해서, 첨자 연산자 오버로딩을 사용할 시 주의사항! */
	IntList* list = new IntList;

	// 이것은 IntList 에서 구현한 첨자 연산자 오버로딩에 접근하는 것이 아니라, 
	// 포인터에 담긴 주소값에 대해 [] 첨자 연산자를 사용하는 것! -> 잘못된 사용은 아닌데, 우리가 의도한 동작을 안할 것임!
	//list[3] = 10; 

	// 제대로 사용하려면, 포인터 변수에 동적으로 할당된 IntList 클래스 인스턴스를 de-referencing 한 후,
	// 오버로딩된 첨자 연산자를 사용해야 정상 작동함!
	(*list)[3] = 10;

    return 0;
}