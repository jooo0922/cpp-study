#include <iostream>

using namespace std;

/*
	만약, 에러를 던질 때,
	-1 같은 기본 자료형 타입의 에러가 아닌,
	클래스와 같은 user-defined 자료형의 에러를 던질 수는 없을까?

	그렇게 할 수 있다면,
	catch 문에서 처리할 작업을

	하나의 예외 클래스로 추상화해서
	해당 예외 클래스 타입의 에러를 throw...catch 하는 과정에서
	주고받을 수 있다면, 코드가 훨씬 더 간결해지지 않을까?

	이를 위해 아래와 같은
	Exception 클래스를 만들어 봄.
*/
class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class MyArray
{
private:
	int m_data[5]; // 5개의 int 타입의 정적 배열을 멤버로 관리하는 클래스

public:
	// [] 연산자 오버로딩
	int& operator [] (const int& index)
	{
		// 멤버함수 내에서도 error throw 를 할 수 있다는 걸 보여줌.
		if (index < 0 || index >= 5)
		{
			// 멤버변수에서 관리하는 정적 배열의 크기를 넘어서는 범위의 index 값이 들어오면,
			// int 타입 에러를 던지도록 함 
			//throw - 1;

			// 이번에는, user-defined 자료형인 Exception 클래스를 에러로 던짐.
			throw Exception();
		}

		return m_data[index];
	}
};

void doSomething()
{
    MyArray my_array;

	try
	{
		// MyArray 클래스에서 관리하는 정적 배열의 크기 5 를 넘어서는 index(100)을 전달 
		// -> [] 연산자 오버로딩 멤버함수에서 에러를 throw 하겠군
		my_array[100];
	}
	catch (const int& x)
	{
		// MyArray 클래스의 멤버함수에서 throw 된 int 타입 에러를 여기서 catch 하여 처리할 것임. 
		cerr << "Exception " << x << endl;
	}
	catch (Exception& e)
	{
		// Exception 클래스 타입의 에러를 catch 한 뒤, 
		// 해당 클래스에 추상화된 작업(report() 멤버함수)을 수행함
		e.report();
	}
}

int main()
{
	doSomething();

    return 0;
}