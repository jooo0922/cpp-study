#include <iostream>

// 부모 클래스
class Base
{
public:
    // FunctionPointer *_vptr; 
    // -> 가상함수 선언 시, "동적 바인딩"으로 가상함수를 관리하므로, 
    // 가상테이블을 가리키는 주소값이 생성됨!
    // (함수 동적 바인딩 관련 https://github.com/jooo0922/cpp-study/blob/main/Chapter12/Chapter12_05/Chapter12_05.cpp 참고)
    void fun1() {};
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
    return 0;
}