#include <iostream>

using namespace std;

// 부모 클래스
class Base
{
public:
    // 생성자 함수
    Base() {}

    // 출력 스트림 연산자 오버로딩 (친구함수로 등록해서 오버로딩)
    // -> 친구함수는 '클래스의 멤버가 아니기' 때문에 자식 클래스에서 '직접적으로' override 할 수는 없음!
    friend ostream& operator << (ostream& out, const Base& b)
    {
        // 자식 클래스에서 오버로딩할 출력 멤버함수 호출
        // -> 친구함수를 직접 오버로딩할 수는 없기 때문에, '간접적으로' override 하기 위해,
        // 임의의 가상 멤버함수를 만들고 난 뒤, 얘한테 override 하고 싶은 작업들을 다 떠넘긴 것!
        return b.print(out);
    }

    // 출력 스트림을 반환하는 가상함수 구현 (상수함수로 구현 > 클래스 멤버의 불변성 보장)
    // 출력 연산자 오버로딩을 override 하고 싶으면, 아래의 가상함수를 '대신' override 함!
    virtual ostream& print(ostream& out) const
    {
        out << "Base";

        // 등록된 친구함수에서 호출하기 때문에, 출력 스트림을 반환해줘야 함.
        return out;
    }
};

// 자식 클래스
class Derived : public Base
{
public:
    // 생성자 함수
    Derived() {}

    /*
        참고로, 실제 출력 스트림 오버로딩 함수는
        부모 클래스에서 이미 친구함수로 등록되어 있기 때문에,

        자식 클래스에서 이를 상속받을 때,
        친구함수로 등록된 함수들도 같이 상속받음.

        따라서, 출력 스트림 오버로딩을
        자식클래스에 추가로 구현할 필요가 없음!
    */

    // virtual 과 override 키워드로 출력 스트림 오버로딩 함수를 '간접적으로' override 함
    // 즉, 실제 출력 스트림 오버로딩 함수를 override 한 것이 아니라, print() 함수를 대신 override 한 것 뿐!
    virtual ostream& print(ostream& out) const override
    {
        out << "Derived";
        return out;
    }
};

int main()
{
    Base b;
    cout << b << '\n';

    Derived d;
    cout << d << '\n';

    // Base 타입 참조변수에 자식클래스 인스턴스 d 할당
    // 부모클래스 타입의 참조변수에 저장하면 원래는 부모 클래스의 멤버함수 print() 가 실행되어야 하지만,
    // 해당 멤버함수가 virtual 로 선언되어 있고, 자식클래스에서 해당 가상함수를 override 하고 있으므로,
    // 자식 클래스인 Derived 의 print() 멤버함수가 실행되는 것을 볼 수 있다!
    // https://github.com/jooo0922/cpp-study/blob/main/Chapter12/Chapter12_02/Chapter12_02.cpp 참고!
    Base& bref = d;
    cout << bref << '\n';

    return 0;
}