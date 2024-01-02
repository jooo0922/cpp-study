#include <iostream>
#include <array>
#include "Storage8.h"

using namespace std;

// 클래스 템플릿 선언
template<typename T>

class A
{
public:
	// 생성자 함수의 매개변수를 통해 템플릿의 타입을 구분하는 것도 가능! (c++ 17 이후부터 가능!)
	A(const T& input)
	{}

	void doSomething()
	{
		// 타입의 이름 출력
		cout << typeid(T).name() << endl;
	}

	void test()
	{

	}
};

// 이때, char 타입의 Instantiation 에 대해서만 특별한 작업을 수행하도록,
// 클래스 템플릿 특수화 (Template Specialization) 선언
/*
	클래스 템플릿 특수화란,
	'상속'이라는 개념과는 다름.

	특정 타입에 대해서 
	완전히 새로운 클래스를 만드는 것으로 봐야 함.

	그래서, char 타입에 대해 특수화한 클래스 A 에 
	test() 멤버함수를 구현해놓지 않았기 때문에,

	다른 Template Instance 에서는 test() 멤버함수 호출이 가능하지만,
	char 타입 Instance 에서는 test() 멤버함수 호출이 불가능함.
*/
template<>
class A<char>
{
public:
	A(const char& input)
	{}

	void doSomething()
	{
		// char 타입에 대한 특별한 작업 수행
		cout << "Char type specialization" << endl;
	}
};

int main()
{
	// Template Instantiation
	A<int> a_int(1);
	A<double> a_double(3.14);
	A<char> a_char('a');

	// Instantiation 된 각 타입 이름 출력
	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();


	/* Storage8 클래스 템플릿을 활용한 실용적인 예제 테스트 */

	// int 타입으로 Storage8 클래스 Template Instantication
	Storage8<int> intStorage;

	// Storage 8개 요소를 반복문에서 할당
	for (int count = 0; count < 8; count++)
	{
		intStorage.set(count, count);
	}

	// 할당된 8개 요소를 반복문에서 출력
	for (int count = 0; count < 8; count++)
	{
		cout << intStorage.get(count) << '\n';
	}

	// int 타입으로 Instantiation 된 클래스 템플릿의 메모리 사이즈 출력
	cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << endl; // 32 bytes (== 4 bytes * 8)

	// bool 타입으로 Storage8 클래스 Template Instantication -> bool 타입으로 특수화된 템플릿 적용!
	Storage8<bool> boolStorage;

	// Storage 8개 요소를 반복문에서 할당
	for (int count = 0; count < 8; count++)
	{
		/*
			count(0부터 7까지의 정수) 값과 3 의 bitwise and 연산 수행 결과, 
			0000 이 나오면 false 를 전달하고, 그렇지 않으면 true 를 전달함.
			
			ex> 0(== 0000) 과 3(== 0011) 을 bitwise and 연산하면 0000 이 되어 false 를 전달하고,
			1(== 0001) 과 3(== 0011) 을 bitwise and 연산하면 0001 이 되어 true 를 전달함!
		*/
		boolStorage.set(count, count & 3);
	}

	// 할당된 8개 요소를 반복문에서 출력
	for (int count = 0; count < 8; count++)
	{
		cout << (boolStorage.get(count) ? "true" : "false") << '\n';
	}

	// bool 타입으로 Instantiation 된 클래스 템플릿의 메모리 사이즈 출력
	cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << endl; // 1 byte (== 8 bits)

	return 0;
}