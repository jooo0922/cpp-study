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

    /*
        어떤 경우에는, 부모 클래스의 기능을 그대로 수행하되,
        자식 클래스에서 추가적인 기능을 더 수행하고 싶은 경우가 있음.

        또한, 함수의 이름마저 동일하게 유지하고 싶을 수 있겠지?

        이럴 경우, 클래스의 다형성을 활용할 수도 있겠지만, 
        그건 다음 챕터에 배울 것이고,

        여기서 소개할 방법은 '상속받은 함수 오버라이딩'으로,
        상속받은 부모 클래스의 동일한 이름을 갖는 멤버 함수를 먼저 호출해주면 됨!

        <부모클래스::멤버함수()>
        형태로 영역표시 연산자(::) 를 사용해서
        부모클래스의 원본 멤버함수에 접근하여 실행하면 됨!
    */
    void print()
    {
        Base::print();
        cout << "I'm derived " << endl;
    }
};

int main()
{
    Base base(5);
    base.print();

    Derived derived(7);
    derived.print();

    return 0;
}