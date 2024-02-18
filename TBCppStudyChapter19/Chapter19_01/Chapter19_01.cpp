#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for_each 를 사용하기 위해 포함
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


    /* 람다 함수를 STL 과 같이 사용하기 */

    // std::vector 동적 배열 생성
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    // for_each 문으로 std::vector 를 순회하면서 
    // STL 의 반복자를 곧바로 정의된 람다 함수의 매개변수로 전달하여 실행할 수 있음!
    for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

    return 0;
}