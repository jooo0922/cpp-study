#include <iostream>

using namespace std;

// 부모 클래스
class Base
{
public:
    // FunctionPointer *_vptr; 
    // -> 가상함수 선언 시, "동적 바인딩"으로 가상함수를 관리하므로, 
    // 가상테이블을 가리키는 주소값이 생성됨!
    // (함수 동적 바인딩 관련 https://github.com/jooo0922/cpp-study/blob/main/Chapter12/Chapter12_05/Chapter12_05.cpp 참고)
    virtual void fun1() {};
    void fun2() {};
};

class Der : public Base
{
public:
    // FunctionPointer *_vptr; 
    // -> 부모 클래스에서 가상함수가 선언되었다면, 
    // 자식 클래스에도 자동으로 가상테이블을 가리키는 주소값이 생성되어,
    // override 되지 않은 멤버함수의 포인터는 부모 클래스의 가상함수를 가리키는 주소를 가상테이블에서 찾아 실행함!
    void fun1() {};
};

int main()
{
    // 부모클래스에서 가상함수(virtual)이 하나라도 선언되었다면,
    // 가상테이블을 가리키는 주소값이 내부적으로 생성됨에 따라, 
    // 클래스의 크기가 1 byte -> 4 bytes(x86 기준) or 8 bytes(x64 기준) 로 변경됨.
    // 참고로, x86 에서 메모리 주소값은 4 bytes, x64 에서는 8 bytes 로 표현된다고 했었지?
    cout << sizeof(Base) << endl;
    cout << sizeof(Der) << endl;

    return 0;
}