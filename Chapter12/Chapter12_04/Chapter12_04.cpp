#include <iostream>

using namespace std;

// 부모클래스
class Base
{
public:
    // 부모클래스의 소멸자
    ~Base()
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
    Derived derived(5);

    return 0;
}