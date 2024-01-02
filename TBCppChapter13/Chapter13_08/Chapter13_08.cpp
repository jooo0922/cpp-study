#include <iostream>

using namespace std;

// 클래스 템플릿 구현
template<class T>
class A
{
private:
    T m_value;

public:
    // 생성자 함수
    A(const T& input)
        : m_value(input)
    {

    }

    // 이미 템플릿화된 클래스 내의
    // 특정 멤버함수를 '한 번 더 템플릿화' 하기
    template <typename TT>
    void doSomething(const TT& input)
    {
        // 클래스의 템플릿 파라미터와 멤버함수의 템플릿 파라미터를 출력함
        cout << typeid(T).name() << " " << typeid(TT).name() << endl;
    }

    // 멤버변수 출력 함수
    void print()
    {
        cout << m_value << endl;
    }
};

int main()
{
    A<int> a_int(123);
    a_int.print();

    // 한 번 더 템플릿화 된 멤버함수를 호출할 경우,
    // 템플릿 파라미터(TT)를 추가로 지정해서 전달해줘야 함.
    //a_int.doSomething<float>();

    // 멤버함수에 전달하는 파라미터 자체로 템플릿 파라미터를 '암묵적으로' 지정할 수 있음!
    a_int.doSomething(123.4); // 멤버함수의 템플릿 파라미터 TT 가 '암묵적으로' double 로 지정됨! 

    return 0;
}