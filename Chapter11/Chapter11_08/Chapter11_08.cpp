#include <iostream>

using namespace std;

class Base
{
protected:
    int m_i;

public:
    Base(int value)
        : m_i(value)
    {}

    void print()
    {
        cout << "I'm base " << endl;
    }
};

class Derived : public Base
{
private:
    double m_d;

public:
    // 항상 멤버 초기화 리스트 문법에는 
    // 부모클래스 생성자 함수 호출 코드가 내부적으로 숨어있는 거라고 했었지? -> 그래서 부모클래스 생성자가 먼저 호출될 수 있었던 것!
    // https://github.com/jooo0922/cpp-study/blob/main/Chapter11/Chapter11_03/Chapter11_03.cpp 참고!
    Derived(int value)
        : Base(value)
    {}

    // 만약, 자식클래스에서 부모클래스 멤버의 접근지정자를 바꾸고 싶다면 어떻게 할까?
    // 사실 사람 관점에서는 '부모에게 물려받은 것을 자식이 함부로 바꾸다니!' 할 수도 있긴 하지만...
    // 어쨋든 using 키워드를 사용하면, 부모클래스의 접근지정자를 원하는 대로 변경해줄 수 있음!
    using Base::m_i;

// 그렇다면, 동일한 원리로, 부모클래스로부터 상속받은 print() 같은 멤버함수를
// 자식클래스에서 private 접근지정자로 바꾸는 것도 당연한가? -> using 키워드를 사용하면 얼마든지 가능!
// 이러한 원리로 부모로부터 상속받은 함수를 '감추는' 기법을 사용할 수 있음!
private:
    using Base::print; // 참고로 '멤버함수'의 접근지정자를 using 키워드로 변경할 때에는 괄호() 를 붙이지 말아야 함!
    
    // 혹은 아래와 같이 delete 키워드로 부모클래스로부터 상속받은 멤버함수를 메모리에서 삭제해버리는 방식도 있음!
    // 이렇게 하면 using 키워드를 사용한 것과 같이 자식클래스에서만 해당 멤버함수를 감출 수 있게 됨!
    void print() = delete;
};

int main()
{
    Derived derived(7);

    // using 키워드를 사용해서 부모클래스의 protected 멤버를 자식클래스에서 public 멤버로 변경! -> 외부에서 접근 가능!
    derived.m_i = 1024;

    // using 키워드로 부모클래스로부터 상속받은 멤버함수를 자식클래스에서 using 키워드로 감춤!
    derived.print();

    return 0;
}