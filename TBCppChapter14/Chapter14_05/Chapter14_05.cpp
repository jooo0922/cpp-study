#include <iostream>

using namespace std;

// 함수 try
/*
    별다른 건 없고,
    그냥 함수 block 전체가
    try...catch 문으로 구성된 것을 의미함.

    어떻게 보면,
    그냥 함수 block 에서
    indentation 이 하나 더 들어간 것과 다를 바 없어서

    아래와 같은 형태로 사용되는 경우는 거의 없다고 함.

    단, 클래스 생성자 내에서
    멤버변수 초기화 리스트 문법에서 발생하는 예외를 처리할 때,
    함수 try 문법이 유용하게 사용된다고 함.
*/
void doSomething()
try
{
    throw - 1;
}
catch (...)
{
    cout << "Catch in doSomething()" << endl;
}

int main()
{
    try
    {
        doSomething();
    }
    catch (...)
    {
        cout << "Catch in main()" << endl;
    }
    
    return 0;
}