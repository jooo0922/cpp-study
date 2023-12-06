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

    // 친구함수로 출력 스트림 연산자 오버로딩 등록하기
    friend std::ostream& operator << (std::ostream& out, const Base& b)
    {
        out << "This is base output" << endl;
        return out;
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

    // 부모클래스에서 친구함수로 등록한 오버로딩을 자식클래스에도 구현
    friend std::ostream& operator << (std::ostream& out, const Derived& b)
    {
        // 여기서도 print() 와 마찬가지로, 
        // 부모클래스에서 friend 로 등록한 오버로딩 함수를 실행하고 나서,
        // 자식클래스에서 추가로 다른 작업을 수행하도록 하고 싶다면???
        
        // 정답은 아주 간단함! Derived 타입의 참조변수(인스턴스 자신)을 부모클래스 타입 Base 로 캐스팅하고,
        // 이를 cout 으로 출력하면 됨! 
        // -> 이렇게 하면 부모클래스 Base 에 오버로딩된 출력스트림 연산자 친구함수가 먼저 실행될 것임!
        // 이런 식으로 자식클래스가 부모클래스로 casting 이 가능한 이유는,
        // 자식클래스가 저장된 메모리는 부모클래스 데이터가 저장된 메모리에 추가로 데이터를 저장한 것에 불과하기 때문에,
        // 두 부모-자식 클래스 간 형변환이 가능하다!
        cout << static_cast<Base>(b);
        out << "This is derived output" << endl;
        return out;
    }
};

int main()
{
    Base base(5);
    //base.print();
    cout << base;

    Derived derived(7);
    //derived.print();
    cout << derived;

    return 0;
}