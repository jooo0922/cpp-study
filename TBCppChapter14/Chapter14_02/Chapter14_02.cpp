#include <iostream>

using namespace std;

/*
	에러 catch 시, 스택 되감기

	
	아래와 같이
	던져진 에러를 catch 하는 문법들이 포함된 함수들을
	try 문 안에서 차례대로 호출함으로써

	해당 함수들을 콜 스택에
	호출된 함수들을 쌓아둔 상태라면,

	콜 스택 상에서 가장 마지막에 push 된 함수이자
	가장 안쪽에서 먼저 실행 후 pop 될 함수인 last() 함수에서

	throw 문법으로 int 타입 에러를 던지면 어떻게 될까?

	-> 이럴 경우,
	콜 스택에 쌓인 순서의 역순으로 함수들을 되집어가며 (이를 스택 되감기(unwinding) 이라고 함)
	int 타입 에러를 catch 하는 코드가 포함된 함수가 있는지 찾아나감.

	그러다가 int 타입 에러를 catch 하여 적절히 예외처리하는
	first() 함수를 만나면, first 함수의 catch 문 및 이후의 코드들을 모두 실행하여
	first() 함수 실행을 완료하면서 콜 스택으로부터 pop 해버리고,

	가장 먼저 콜 스택에 push 되어있던 main() 함수로 돌아와서
	나머지 코드를 수행한 뒤, 콜 스택으로부터 pop 하면서 프로그램이 종료됨.

	물론, 그 사이에 존재하던 함수들은
	던져진 해당 타입의 에러를 catch 하는 문법이 존재하지 않기 때문에,
	이후의 코드들을 마저 실행하기도 전에 콜 스택으로부터 pop 되어버리겠지!

	이러한 과정을
	'예외처리 시 스택 되감기'
	라고 함!
*/

void last()
{
	cout << "Last" << endl;
	cout << "Throw exception" << endl;

	// -1 (int 타입)에러를 던짐
	//throw -1;

	// 어느 곳에서도 catch 하지 못하는 타입의 에러를 던질 경우,
	// ellipsis(...) 로 에러 타입을 정의한 catch 문이 다 받아서 처리하게 됨.
	throw 'a';

	cout << "End last " << endl;
}

void third()
{
	// 이 함수에서는 던져진 에러를 catch 하는 문법이 없음

	cout << "Third" << endl;

	last();

	cout << "End third" << endl;
}

void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		// 던져진 double 타입 에러를 '잡아서' 적절한 예외처리를 수행한다
		cerr << "second caught int exception" << endl;
	}

	cout << "End second" << endl;
}

void first()
{
	cout << "First" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		// 던져진 int 타입 에러를 '잡아서' 적절한 예외처리를 수행한다
		cerr << "first caught int exception" << endl;
	}

	cout << "End first" << endl;
}

int main()
{
    cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		// 던져진 int 타입 에러를 '잡아서' 적절한 예외처리를 수행한다
		/*
			참고로, std::cerr, std::clog, std::cout
			모두 콘솔에 무언가를 출력하는 함수이며,

			기능은 거의 유사하나,
			콘솔에 무언가를 출력하는 채널이 다르다고 보면 됨.

			cerr 는 긴급한 에러 출력에 특화되어 있어
			cout 처럼 버퍼를 거치지 않고 곧바로 출력한다는 내부 작동구조 상의 차이가 있지만,
			큰 차이는 아니고, 어쨋든 3개 함수들은 수행하는 기능들이 유사함.
		*/
		cerr << "main caught int exception" << endl;
	}
	catch (...) // catch-all handlers
	{
		/*
			throw(던져진) 에러를 적절히 catch 하여 처리하지 못하면
			프로그램이 중간에 runtime 에러를 발생시키면서
			중단되는 문제가 있기는 하지만,

			모든 타입의 에러에 대응되는 catch 문을
			일일이 작성하는 것은 현실적으로 어려움.

			따라서, 어떤 타입의 에러가 던져지던지 간에
			무조건 catch 하여 handling 할 수 있는 catch 문을 작성하려면
			catch 할 에러 타입을 ellipsis(...) 기호로 선언해주면 됨.

			ellipsis 관련 설명은
			https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter7/Chapter7_16/Chapter7_16.cpp 참고
		*/
		cerr << "main caught ellipsis exception" << endl;
	}

	cout << "End main" << endl;

    return 0;
}