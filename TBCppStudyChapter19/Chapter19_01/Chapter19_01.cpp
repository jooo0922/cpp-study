#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for_each 를 사용하기 위해 포함
#include <functional> // c++ 11 부터 도입된 std::function 을 사용하기 위해 포함

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
    // STL 의 반복자를 람다 함수의 매개변수로 전달하여 실행할 수 있음!
    auto func2 = [](int val) {cout << val << endl; };
    for_each(v.begin(), v.end(), func2);

    // 또는, 람다 함수 구현부를 인라인으로 직접 전달하는 것도 가능함! -> 모던 C++ 에서는 이 방식을 더 선호함!
    for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });


    /* 입출력 스트림 내에서 인라인으로 정의된 람다 함수를 곧바로 실행함 */
    cout << []() -> int {return 1; }() << endl;


    /*
        std::function

        함수 포인터를 좀 더 쉽게 사용하기 위해
        c++ 11 에서 도입된 함수 포인터를 체계화한 클래스

        아래 챕터에서 이미 한 번 다뤄봤음.
        https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter7/Chapter7_09/Chapter7_09.cpp 
    */

    // 위에서 정의한 람다 함수의 주소값을 std::function 으로 선언한 함수 포인터에 할당함.
    std::function<void(int)> func3 = func2;
    
    // 람다 함수의 주소값이 할당된 std::function 함수 포인터 실행
    func3(123);


    /* 
        std::bind() 
        
        만약, std::function<> 으로 정의된 함수 포인터를 호출할 때,
        특정 타입의 파라미터를 매번 넣어주기 귀찮을 수도 있겠지?

        그럴 때에는, std::bind() 를 사용함으로써,
        해당 함수 포인터를 실행할 때마다 자동으로 전달해 줄
        '파라미터 값을 binding 해줄' 수 있음!

        이렇게 하면,
        함수 포인터를 실행할 때, 파라미터 값을 명시하지 않더라도,
        바인딩된 파라미터가 자동으로 들어가서 실행됨!
    */
    std::function<void()>func4 = std::bind(func3, 456);
    
    // 함수 포인터 func4 를 호출할 때마다, 파라미터를 별도로 넣지 않아도, 
    // 바인딩된 값인 456 이 자동으로 매개변수에 전달되어 실행!
    func4();

    return 0;
}