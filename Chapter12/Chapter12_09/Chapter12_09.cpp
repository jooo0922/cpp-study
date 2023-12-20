#include <iostream>

using namespace std;

/* 
    객체 잘림 현상

    
    자식 클래스는 부모클래스로부터 상속을 받으므로,
    자식 클래스는 부모 클래스를 기본 토대로 삼아,
    멤버변수, 함수, override 등의 데이터들을 덧대어서 구현하겠지?

    즉, 자식클래스는 기본적으로 메모리 크기가
    부모클래스보다 커질 수밖에 없는 구조임.

    이처럼, 데이터가 더 큰 자식클래스를
    부모클래스 타입의 변수(특히, 부모클래스 타입의 일반 변수)에다가
    억지로 할당하려고 하면,

    부모클래스를 담을 수 있는 메모리만큼만 할당된 변수에서는
    자식클래스에'만' 존재하는 데이터들이 잘려나갈 수밖에 없게 됨.

    이러한 현상을 '객체 잘림 현상' 이라고 함.
*/

// 부모 클래스
class Base
{
public:
    int m_i = 0;

    // 가상함수 선언
    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

// 자식 클래스
class Derived : public Base
{
public:
    int m_j = 1;

    // 부모 클래스의 가상함수를 override
    virtual void print() override
    {
        cout << "I'm Derived" << endl;
    }
};

void doSomething(Base& b)
{
    b.print();
}

int main()
{
    /*
        아래와 같이,
        
        부모클래스 타입의 일반 변수에
        자식클래스 타입의 인스턴스를 
        억지로 할당하려고 하면,

        '객체 잘림 현상' 발생!
    */
    Derived d;
    Base b = d;

    b.print();

    return 0;
}