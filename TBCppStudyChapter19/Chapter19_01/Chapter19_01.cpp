#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    /*
        lambda function (람다 함수)

        anonymous function (익명 함수) 라고도 함.
        일반적으로 자바스크립트에서 사용하는
        '화살표 함수' 라고 보면 됨.
    */

    /*
        람다 함수는 아래와 같은 구조로 구성되어 있음.

        - lambda-introducer : 매개변수 왼쪽에 표시된 []
        - lambda-parameter-declaration : 람다함수의 매개변수 선언
        - lambda-return-type-clause : 람다함수의 반환값 타입 선언
        - compound-statement : 람다함수의 구현부
    */
    auto func = [](const int& i) -> void { cout << "Hello, World!" << endl; };
    
    func(123);

    /*
        람다함수의 진가는 아래와 같이
        익명함수를 선언하는 즉시 호출하는 상황에서 드러남.

        이처럼 익명함수를 선언과 동시에 실행할 때
        람다함수 문법을 많이 사용한다고 함.
    */
    [](const int& i) -> void { cout << "Hello, World!" << endl; } (1234);
    
    return 0;
}