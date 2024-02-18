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

    {
        /*
            람다 함수의 
            lambda-introducer [] 의 역할

            lambda-introducer 를 사용하는 예시 중 하나로써,
            [&] 앰퍼샌드 기호를 넣는 방식을 들 수 있는데,

            이는 람다 함수가 선언된 특정 block 내의
            local variable 의 레퍼런스를
            람다 함수의 구현부 내부에서 가져와서 사용할 수 있도록 함!

            만약, [=] 와 같이 사용하면,
            local variable 을
            람다 함수의 구현부 내부에 '복사'해줄 수 있음!
        */
        string name = "JackJack";
        [&]() { cout << name << endl; } ();
    }
    
    return 0;
}