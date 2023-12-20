#include <iostream>
#include <vector>
#include <functional> // reference_wrapper 사용을 위해 포함

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

/*
    이 함수에서도 마찬가지로,
    매개변수가 부모클래스 타입의 일반변수로 선언되면,

    매개변수에 자식클래스 타입의 변수를 전달할 경우,
    '인스턴스 복사'가 발생해서,

    매개변수에 자식클래스 인스턴스가 '복사'되는 과정에서
    메모리 부족으로 인해 '객체 잘림 현상' 발생!
*/
void doSomething(Base b)
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

        자식클래스 인스턴스 '복사'가 발생해버려서,

        복사된 인스턴스가
        부모클래스 타입 변수에 복사되는 과정에서
        '객체 잘림 현상' 발생!
    */
    Derived d;
    Base b = d;

    /*
        객체 잘림 현상의 더 무서운 점은,

        자식클래스의 함수를 실행하기 위해 
        필요한 데이터들도 다 잘려버려서

        자식클래스의 함수 자체가 실행이 안되는,
        즉, '다형성이 사라져버리는' 문제가 발생함!
    */
    b.print();

    doSomething(d);

    /*
        초보 프로그래머의 경우,
        std::vector 를 잘못 사용할 때
        의도치 않은 객체 잘림 현상을 경험하게 됨.
    */
    Base b1;
    Derived d1;

    //std::vector<Base> my_vec;
    //my_vec.push_back(b1);

    //// 이것도 마찬가지로 Base 타입 변수에 Derived 타입 인스턴스를 강제로 복사해버리는 꼴이 됨 
    //// -> 객체 잘림현상 발생!
    //my_vec.push_back(d1); 

    //for (auto& ele : my_vec)
    //{
    //    // for-each 문으로 추가된 인스턴스들의 print() 함수 실행 시,
    //    // 객체 잘림 현상에 의해 전부 부모클래스인 Base 의 print() 만 실행됨!
    //    ele.print();
    //}

    // 위의 std::vector 에서의 객체 잘림 현상을 해결하는 방법 중 하나는
    // 포인터 변수로 std::vector 를 선언하는 것!
    //std::vector<Base*> my_vec;
    //my_vec.push_back(&b1);
    //my_vec.push_back(&d1); 

    //for (auto& ele : my_vec)
    //{
    //    ele->print();
    //}

    // 또는, 참조변수로 std::vector 를 선언해서 객체 잘림을 해결해야 할 상황이 생긴다면,
    // std::reference_wrapper<> 를 사용할 것! (std::vector 는 원래 참조변수 타입을 선언할 수 없음!)
    std::vector<std::reference_wrapper<Base>> my_vec; // 이제 이 vector 는 Base 의 참조변수를 저장하는 vector 가 됨!
    my_vec.push_back(b1);
    my_vec.push_back(d1);

    for (auto& ele : my_vec)
    {
        // 여기서 ele 은 std::reference_wrapper<Base> 타입의 변수에 해당되고,
        // ele.get() 은 std::reference_wrapper.get() 즉, Base 의 참조변수를 반환해주는 getter 함수에 해당함!
        ele.get().print();
    }

    return 0;
}