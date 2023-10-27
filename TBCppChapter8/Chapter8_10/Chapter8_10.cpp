#include <iostream>

using namespace std;

// 일반적인 함수 안에서 사용되는 정적 변수
int generateID()
{
    static int s_id = 0;
    return ++s_id;
}

class Something
{
public:
    static int s_value; // = 1; // static 멤버변수는 클래스 내에서 초기화를 할 수 없다!
    static const int sc_value = 1; // const static 멤버변수는 클래스 내에서 초기화가 가능하다! -> 왜냐? const 니까! 상수 멤버변수는 항상 선언과 동시에 초기화되어야 함!

    // constexpr (const expression)
    // 일반적인 const 와 달리, 항상 '리터럴 값'으로만 초기화되어야 함!
    // 왜냐하면, const 중에서는 변수나 템플릿을 넣는 경우 런타임에 초기화될 수 있는 경우가 있음.
    // 그러나, constexpr 은 컴파일 타임에 미리 초기화해버리는 것을 강제하기 위해
    // 초기화 값으로 리터럴 값만 받음!
    static constexpr int sce_value = 1;
};

// 정적 멤버변수를 초기화하려면 클래스 블록 외부에서 
// 아래와 같이 별도로 초기화 코드를 작성해야 함.
// 또 주의해야 할 점이, 정적 멤버변수는 "define in cpp" 즉,
// cpp 안에서 정의되는 것이 권장됨. 헤더파일에서 정의하려고 하면 컴파일 에러를 발생시킴!
int Something::s_value = 1;

// 반대로, const static 멤버변수는 클래스 외부에서 초기화 불가능!
//int Something::sc_value = 1;

int main()
{
    // 클래스 인스턴스를 생성하기 이전에 찍어 본 정적 멤버변수의 주소와 값
    // -> 'static(정적)' 변수이기 때문에, 인스턴스가 존재하지 않는 상태에서도 접근 가능!
    cout << &Something::s_value << " " << Something::s_value << endl;

    Something st1;
    Something st2;

    st1.s_value = 2; // 중간에 특정 인스턴스를 통해 정적 멤버변수의 값을 변경함

    // 놀랍게도 두 인스턴스의 정적 멤버변수 s_value 는 주소와 값이 모두 동일하게 찍힘... 
    cout << &st1.s_value << " " << st1.s_value << endl;
    cout << &st2.s_value << " " << st2.s_value << endl;

    Something::s_value = 1024; // 중간에 정적 멤버변수의 값을 변경함

    // 마찬가지로 정적 멤버변수의 주소값은 이전에 출력한 것들과 동일하며,
    // 값만 변경되어 있는 상태...
    cout << &Something::s_value << " " << Something::s_value << endl;

    return 0;
}