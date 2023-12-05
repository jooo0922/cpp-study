#include <iostream>

using namespace std;

class Base
{
protected:
    int m_value;

public:
    Base(int value)
        : m_value(value)
    {

    }
};

class Derived : public Base
{
public:
    // 항상 멤버 초기화 리스트 문법에는 
    // 부모클래스 생성자 함수 호출 코드가 내부적으로 숨어있는 거라고 했었지? -> 그래서 부모클래스 생성자가 먼저 호출될 수 있었던 것!
    // https://github.com/jooo0922/cpp-study/blob/main/Chapter11/Chapter11_03/Chapter11_03.cpp 참고!
    Derived(int value)
        : Base(value) 
    {

    }

    // 가급적 부모클래스의 private 멤버는 부모클래스에서 관리하는 것이 좋지만,
    // 만약, 부득이하게 자식클래스에서 부모클래스의 멤버를 변경하는 기능을 추가해야 한다면?
    // -> 부모클래스의 private 멤버를 protected 멤버로 변경하면 해결됨!
    void setValue(int value)
    {
        Base::m_value = value;
    }
};

int main()
{
    return 0;
}