#include <iostream>

using namespace std;

// 클래스 템플릿 선언
template<typename T>

class A
{
public:
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
template<>
class A<char>
{
public:
	void doSomething()
	{
		// char 타입에 대한 특별한 작업 수행
		cout << "Char type specialization" << endl;
	}
};

int main()
{
	// Template Instantiation
	A<int> a_int;
	A<double> a_double;
	A<char> a_char;

	// Instantiation 된 각 타입 이름 출력
	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	return 0;
}