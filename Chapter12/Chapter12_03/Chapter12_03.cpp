#include <iostream>

using namespace std;

class A
{
public:
    virtual void print(int x) { cout << "A" << endl; }
};

class B : public A
{
public:
    //virtual void print() { cout << "B" << endl; }
    // print() 멤버함수를 overriding 할 때, 실수로 매개변수 타입을 다르게 지정하면 어떻게 될까?
    void print(short x) { cout << "B" << endl; }
};

//class C : public B
//{
//public:
//    virtual void print() { cout << "C" << endl; }
//};

int main()
{
    A a;
    B b;
    //C c;

    A& ref = b;
    ref.print(1);

    return 0;
}