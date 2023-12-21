#include <iostream>
#include <string>

using namespace std;

// 부모 클래스
class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

// 자식 클래스 1
class Derived1 : public Base
{
public:
    int m_j = 1024;

    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

// 자식 클래스 2
class Derived2 : public Base
{
public:
    string m_name = "Dr. Two";

    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

int main()
{
    Derived1 d1;

    // Base(부모클래스) 타입의 포인터 변수에 Derived1(자식클래스) 타입 인스턴스의 주소값 할당
    Base* base = &d1; 

    return 0;
}