#include <iostream>

using namespace std;

// 부모클래스
class Base
{
public:
    // 부모클래스의 소멸자
    //~Base()

    // 부모클래스의 소멸자를 가상소멸자로 만듦 
    // -> 부모클래스 소멸자 호출에 의해 자식클래스 소멸자까지 한방에 자동으로 호출!
    // -> 자식클래스 소멸자에서 메모리 반납하는 작업들도 모두 정상적으로 수행할 수 있게 됨!
    virtual ~Base()
    {
        cout << "~Base()" << endl;
    }
};

// 자식클래스
class Derived : public Base
{
private:
    int* m_array; // 동적 할당 배열 멤버 선언

public:
    // 자식클래스 생성자
    Derived(int length)
    {
        // 멤버에 힙 메모리 동적 할당
        m_array = new int[length];
    }

    // 자식클래스 소멸자
    ~Derived()
    {
        cout << "~Derived" << endl;
        
        // 소멸자에서는 항상 동적 할당했던 메모리 반납!
        delete[] m_array;
    }
};

int main()
{
    /*
        이때, 소멸자 호출 순서에 따라

        ~Derived
        ~Base

        순으로 출력됨.

        소멸자는 항상 자식 -> 부모 역순으로 호출된다고 했었지?
        https://github.com/jooo0922/cpp-study/blob/main/Chapter11/Chapter11_04/Chapter11_04.cpp 참고!
    */
    //Derived derived(5);

    /*
        이번에는, 상속 구조 상에서
        자식클래스가 동적 할당되었을 때,

        소멸자가 어떻게 호출되는지 확인해보자!
    */
    // 메모리 동적 할당으로 자식클래스 인스턴스 생성
    Derived* derived = new Derived(5);

    // 상속 구조를 이용해서 부모클래스 포인터 변수에 자식클래스가 생성된 주소값을 할당
    Base* base = derived; 

    // 실전에서는 상속구조가 복잡한 경우가 많아, 직접적으로 상속된 부모를 알기가 어려우므로,
    // 동적할당된 자식클래스 인스턴스 메모리 반납 시, 
    // 최상위 부모클래스 포인터 변수를 통해 메모리를 반납하는 기법을 많이 사용함!
    // 문제는, 이때 '부모클래스의 소멸자만' 호출된다는 게 문제임! 
    // -> why? 자식클래스 소멸자를 호출하지 못하면, 자식클래스에서 동적 할당된 메모리 m_array 를 반납 불가...
    // 즉, memory leak 발생!
    // -> 이러한 문제를 해결하기 위해 부모클래스의 소멸자를 virtual (가상소멸자)로 만드는 게 중요함!
    // -> 부모클래스 소멸자 호출에 의해 자식클래스 소멸자까지 한방에 자동으로 호출!
    // -> 자식클래스 소멸자에서 메모리 반납하는 작업들도 모두 정상적으로 수행할 수 있게 됨!
    delete base;

    return 0;
}