#include <iostream>

using namespace std;

int main()
{
    // x 는 variable(변수)
    // 2 는 리터럴(literal)
    // = 는 대입연산자(Assignment)
    int x = -2;

    // == "같다" 라는 표현은 이 부호로 표현

    // 1, 2, "My Home" 모두 리터럴
    // 1 + 2 는 표현식(Expression)
    // + 는 Operator(연산자)
    // 연산자는 +, -, *, / 등이 있음
    // 연산자 양쪽의 1, 2와 같은 연산의 대상은 피연산자(Operand)
    // 피연산자가 2개인 + 와 같은 연산자는 이항연산자 라고 함.
    cout << 1 + 2 << endl;
    cout << "My Home" << endl;

    // 2 앞에 붙는 - 는 단항연산자 > 항이 1개니까!
    cout << -2 << endl;

    // 삼항연산자는 다 알지?
    int y = (x > 0) ? 1 : 2;

    cout << y << endl;

    return 0;
} 