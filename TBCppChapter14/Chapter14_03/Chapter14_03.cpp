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

/*
	예외 클래스를 상속받는
	ArrayException 클래스 정의 및 구현
*/
class ArrayException : public Exception
{
public:
	// 부모 클래스의 멤버함수 report() 를 override
	void report()
	{
		cerr << "Array exception" << endl;
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
			//throw Exception();

			// 이번에는, Exception 클래스를 상속받는 ArrayException 타입을 에러를 던짐.
			throw ArrayException();
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
	catch (ArrayException& e)
	{
		/*
			부모 클래스 타입으로 에러가 정의된
			catch 문에서의 객체 잘림 현상을 방지하려면,

			자식 클래스 타입의 에러가 정의된
			catch 문을 별도로 구현해줘야 함.

			단, 이때,
			부모 클래스 타입의 catch 문이
			자식 클래스 타입의 catch 문보다 먼저 정의되어 있으면,

			상속관계에 의해
			부모 클래스 타입의 catch 문이
			자동으로 먼저 에러를 잡아버리게 되어 있음.

			따라서, 이를 방지하려면,6
			항상 '상속받은 자식 클래스 타입의 catch 문을 먼저' 선언해줘야
			자식 클래스 타입으로 던져진 에러를 적절하게 catch 하여
			예외처리할 수 있게 됨.
		*/
		cout << "doSomething()" << endl;
		e.report();

		// main() 함수에서 동일한 자식클래스 타입의 에러를 다시 catch 할 수 있도록,
		// ArrayException 타입 에러를 rethrow 함!
		throw e;
	}
	catch (Exception& e)
	{
		// Exception 클래스 타입의 에러를 catch 한 뒤, 
		// 해당 클래스에 추상화된 작업(report() 멤버함수)을 수행함

		/*
			ArrayException 타입의 에러가 던져졌을 때,
			
			만약, 상속받은 자식 클래스 타입에 대한 
			catch 문을 별도로 구현하지 않는다면,

			어쨋든 상속관계의 부모 클래스인 Exception 타입의 에러로 정의된
			catch 문이 에러를 잡아서 처리하겠지만,

			https://github.com/jooo0922/cpp-study/blob/main/Chapter12/Chapter12_09/Chapter12_09.cpp 에서 배웠던
			'객체 잘림 현상' 에 의해

			부모 클래스 타입으로 선언된 에러 변수 e 에는
			자식 클래스인 ArrayException 에'만' 존재하는 데이터들이 잘려나가 저장됨.

			따라서, report() 함수를 호출하더라도,
			부모 클래스인 Exception 의 report() 멤버함수가 실행될 것임!
		*/
		cout << "doSomething()" << endl;
		e.report();
	}
}

int main()
{
	try
	{
		doSomething();
	}
	catch (ArrayException& e)
	{
		/*
			이번에는

			doSomething() 함수 내에서
			ArrayException 타입의 에러가 한 번 catch 됨과 동시에,
			동일한 에러 객체를 rethrow 하게 되는데,

			main() 함수 내에서 rethrow 된 동일한 에러 객체를
			다시 잡도록 catch 문을 추가한 것!

			이 과정에서 Chapter14_02 에서 배웠던
			'예외처리 시 스택 되감기(unwinding)' 가 수행될 것임!
		*/
		cout << "main()" << endl;
		e.report();
	}

    return 0;
}