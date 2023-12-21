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

    // 만약, 자식클래스 인스턴스를 부모클래스 포인터 변수에 할당한 후,
    // 해당 포인터 변수의 타입을 다시 자식클래스 타입으로 형변환해야 할 상황이 생긴다면?
    // (ex> 부모클래스 타입의 매개변수로 자식클래스 인스턴스를 전달받았을 경우, 
    // 함수 내부에서는 부모클래스 타입의 매개변수를 통해서만 접근할 수밖에 없는 상황!
    // -> 이럴 때, 다시 해당 매개변수의 타입을 자식클래스 타입으로 형변환할 수 있으면 좋을텐데!)
    // 이럴 때 사용하기 좋은 것이 dynamic_cast (동적 형변환)
    auto* base_to_d1 = dynamic_cast<Derived1*>(base);

    // 자식클래스 타입인 Derived1 타입으로 다시 형변환 되었으니, 자식클래스의 멤버변수에도 접근 가능!
    cout << base_to_d1->m_j << endl;

    return 0;
}