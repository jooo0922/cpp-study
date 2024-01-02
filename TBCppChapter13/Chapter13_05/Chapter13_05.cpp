#include <iostream>

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

	return 0;
}