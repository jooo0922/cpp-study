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