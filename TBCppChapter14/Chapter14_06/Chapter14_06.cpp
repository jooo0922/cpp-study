#include <iostream>
#include <memory> // 스마트 포인터 사용을 위해 포함

using namespace std;

class A
{
public:
	// 소멸자 함수
	~A()
	{
		/*
			소멸자 함수에서 char* 타입 에러를 throw 하는 상황

			
			이처럼, 클래스의 소멸자 함수 내에서
			타입 에러를 throw 하는 것은 금기시 되는 문법임.

			실제로 빌드하면,

			"'A::~A' function assumed not to throw an exception but does"
			라는 경고가 출력됨.

			즉, destructor 내에서는 에러를 못던지게 되어 있다는 뜻.

			왜냐하면, 상식적으로 destructor 는
			인스턴스에 할당된 메모리들을 싹 다 지우고 반납하는 과정이므로,

			이 시점에 정상적으로 에러를 던질 수 없는 상황이라고 
			보는 게 타당하겠지!

			-> warning 이기 때문에 빌드는 정상적으로 되겠지만,
			실제 실행파일을 돌리면 runtime error 가 발생함!
		*/
		//throw "error";
	}
};

int main()
{
	try
	{
		A a;

		// 배열 메모리 동적 할당
		int* i = new int[1000000];

		/*
			예외처리로 인한 메모리 누수 해결법 - 스마트 포인터!


			unique_ptr<> 타입의 스마트 포인터를 사용해서
			동적 할당된 포인터 변수를 매개변수로 전달하면,

			현재 영역을 벗어날 시,
			unique_ptr 이 알아서 동적 할당된 메모리를 반납해 줌.

			더 좋은 것은,
			throw 키워드로 인해
			catch 문으로 날라갈 때에도

			unique_ptr 이 알아서 메모리를 반납해 줌.
		*/
		unique_ptr<int> up_i(i);

		// do something with i

		// char* 타입 에러를 던짐
		throw "error";

		/*
			예외처리의 첫 번째 위험성.


			throw 키워드를 통해 예외를 던질 경우,
			throw 키워드 이후 코드에서 어떤 동적 메모리를 반납하는 코드가 있다면,
			이 코드는 실행되지 않을 것임.

			즉, '예외처리로 인해 메모리 누수가 발생'할 수도 있음!

			왜냐하면, throw 이후 실행될 catch 문에서
			포인터 변수 i 에 접근할 방법이 없기 때문...
		*/
		//delete[] i;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}
    return 0;
}