#include <iostream>

using namespace std;

// 분수를 나타내는 클래스
class Fraction
{
private:
    int m_numerator; // 분자
    int m_denominator; // 분모

public:
    // 생성자 (Constructor)
    // 반환타입이 없고, 클래스의 이름과 동일한 함수!
    // 이 함수는 코딩을 하면서 외부에서 의도적으로 호출하는 게 아닌, 클래스의 인스턴스 생성과 동시에 실행되는 함수!
    // 즉, 클래스 인스턴스가 메모리에 할당되는 즉시 실행되는 함수!
    // 생성자 매개변수는 다른 함수와 마찬가지로 default value 할당 가능
    Fraction(const int& num_in, const int& den_in = 1) 
    {
        m_numerator = num_in;
        m_denominator = den_in;

        cout << "Fraction() constructor" << endl;
    }

    // 참고로, 클래스 안에 생성자를 별도로 정의해놓지 않았다면,
    // 아래와 같이 default constructor 를 컴파일러가 알아서 만들어서 넣어줌. 
    // Fraction() {}

    void print()
    {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};

int main()
{
    // Fraction 클래스의 인스턴스들의 멤버변수를 초기화하고 싶다면 어떻게 할까?
    // 우선, 각 멤버변수들의 접근지정자를 public 으로 변경하여 캡슐화를 해제한다는 전제 하에,
    // Fraction frac{ 0, 1 }; 이렇게 uniform initialization 할 수도 있고,
    // frac.m_numerator = 0; 이렇게 직접 멤버에 접근해서 값을 초기화할 수도 있겠지.

    // 그렇지만, 캡슐화를 유지한 상태에서 초기화를 하고 싶다면? 이럴 때 필요한 것이 생성자(Constructor)!

    /*
        참고로, 생성자도 함수인데 왜 괄호가 없을까?

        Fraction frac() 이어야 하는 거 아닐까?

        c++ 에서는 클래스의 생성자에 매개변수를 선언하지 않았다면,
        클래스 인스턴스 선언 시, 괄호를 붙이지 않는 것을 원칙으로 함.
    */
    //Fraction frac;
    //frac.print();

    Fraction one_thirds(1, 3);
    one_thirds.print();

    return 0;
}