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
};

int main()
{
    return 0;
}