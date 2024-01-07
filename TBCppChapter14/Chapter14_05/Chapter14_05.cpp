#include <iostream>

using namespace std;

// 부모 클래스
class A
{
private:
    int m_x;

public:
    // 생성자 함수
    A(int x) : m_x(x) // 멤버 초기화 리스트
    {
        // 생성자 함수 내에서 에러를 던질 때
        if (x <= 0)
        {
            // 생성자 함수로 전달된 파라미터의 값이 0 이하이면 int 타입 에러를 던짐
            throw 1;
        }
    }
};

// 자식 클래스
class B : public A
{
public:
    // 생성자 함수
    /*B(int x)
        : A(x)
    {}*/

    /*
        그런데, A 클래스에서와 달리,
        생성자 함수 block 내부로 들어가지 않고,

        멤버 초기화 리스트가 실행되는 시점,

        즉, member initialization 시점에
        즉시 예외처리를 수행하고 싶을 수도 있잖아?

        이럴 때 함수 try 문법을 아래와 같이 사용한다고 함!
    */
    B(int x) try : A(x)
    {
        // do initialization
        // 함수 try 내부의 try 문에서 member initialization 을 수행함!
    }
    catch (...)
    {
        cout << "Catch in B constructor " << endl;

        /*
            이때, 
            클래스의 생성자에서 함수 try 문법을 사용 시 나타나는
            특이한 현상이 있음.

            분명 rethrow 를 명시하지 않았음에도,
            생성자에 정의된 catch 문에서 에러 객체를 잡은 뒤,
            main() 함수에 정의된 catch 문에서 다시 에러 객체를 잡게 됨!

            이처럼,
            일반적인 함수 try 문법은
            에러 객체를 2번 catch 하지 않지만,

            클래스 생성자 함수의
            member initialization 에 사용된 함수 try 는
            예외적으로 마치 rethrow 를 명시한 것처럼

            에러가 다시 던져지고,
            다시 catch 되도록 작동함.
        */
        //throw;
    }
};

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
//void doSomething()
//try
//{
//    throw - 1;
//}
//catch (...)
//{
//    cout << "Catch in doSomething()" << endl;
//}

int main()
{
    try
    {
        //doSomething();
        B b(0);
    }
    catch (...)
    {
        cout << "Catch in main()" << endl;
    }
    
    return 0;
}