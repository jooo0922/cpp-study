#include <iostream>

using namespace std;

/*
    함수 매개변수의
    값에 의한 전달(Call by Value)의 장점은

    말 그대로, 외부 변수의 값을
    함수 내부에서 변경하지 못하게 막아두는,
    데이터 불변을 유지할 수 있게 해주는 장점이 존재함.
*/
void doSomething(int y)
{
    // 매개변수로 들어온 int 타입 매개변수 y 의 값과 주소값을 출력
    cout << "In func " << y << " " << &y << endl;
}

int main()
{
    // 실인자로 전달한 리터럴 값 5가 doSomething() 함수의 매개변수 y 에 값으로 복사되어 전달
    doSomething(5);

    int x = 6;

    // 여기서 출력한 변수 x 의 주소값과 
    // doSomething() 함수 내부에서 출력한 매개변수 y의 주소값이 다른 걸 보면,
    // doSomething() 의 매개변수에는 x 에 들어있는 '값만' 복사되어 전달된 것임을 알 수 있다!
    cout << "In main " << x << " " << &x << endl;

    // 실제로 변수 x 자체가 전달되는 게 아니라, x에 들어있는 '값만' 'argument 로써' 복사되어 함수의 매개변수로 전달
    doSomething(x);
    doSomething(x + 1); // x + 1 자체는 어떤 변수가 아니라 표현식이므로, 이 경우에도, 그 표현식의 '결과값' 이 전달되겠지! 

    return 0;
}