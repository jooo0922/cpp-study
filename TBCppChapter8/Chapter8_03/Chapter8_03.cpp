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
    Fraction(const int& num_in = 1, const int& den_in = 1) 
    {
        m_numerator = num_in;
        m_denominator = den_in;

        cout << "Fraction() constructor" << endl;
    }

    // 아래와 같이 매개변수가 없는 또다른 생성자를 오버로딩하고자 한다면,
    // 위에서 먼저 선언한 매개변수 기본값이 할당된 생성자와 중복된다고 컴파일러가 에러를 발생시킴.
    // 즉, 정확히는 중복된 default constructor 를 갖고 있다는 에러를 출력하는데,
    // 이게 왜 그러냐면, 위의 생성자도 매개변수들이 기본값을 갖고 있어서, 
    // 외부에서 클래스를 생성할 때, 파라미터를 넘겨주지 않아도 위의 생성자를 호출할 수 있음.
    // 이렇게 되면, 컴파일러 입장에서는 위의 매개변수를 선언한 생성자를 호출하라는 건지,
    // 아래의 매개변수 없는 생성자를 호출하라는 건지 알 수가 없으니 에러를 발생시킨 것!
    //Fraction()
    //{
    //    m_numerator = 2;
    //    m_denominator = 1;
    //}

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

        c++ 에서는 클래스의 생성자에 파라미터를 넘겨주지 않게 된다면,
        (그 이유가, 생성자에 멤버변수를 선언하지 않았든, 아니면 default value 를 사용하려고 하는 것이든 간에...)
        클래스 인스턴스 선언 시, 괄호를 붙이지 않는 것을 원칙으로 함.

        이거는 외워야 함!!
    */
    //Fraction frac;
    //frac.print();

    // 참고로, 생성자 매개변수를 선언해놓으면, 멤버를 캡슐화해놔도 uniform initialization 으로 멤버의 값 초기화 가능!
    // 그렇다면, uniform initialization {} 와 생성자 호출 () 의 차이가 뭔가?
    //Fraction one_thirds{ 1.0, 3 }; // 얘는 파라미터의 형변환을 자동으로 해주지 못해서 빌드 에러를 발생시킴

    // 얘는 warning 은 뜨지만 작동은 함. 
    // > 그러나, 최근에는 uniform initialization 이 좀 더 엄격하게 타입 에러를 체크해줘서 
    // 이게 더 좋다고 하는 의견이 있음.
    Fraction one_thirds(1.0, 3); 
    one_thirds.print();

    return 0;
}