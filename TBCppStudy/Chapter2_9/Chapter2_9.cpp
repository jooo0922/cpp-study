#include <iostream>
#include"MY_CONSTANTS.h" // 상수들을 모아둔 헤더파일

/*
    매크로 전처리기는 C 에서 상수를 정의할 때
    많이 사용하는 문법이였으나,
    이는 디버깅할 때 코드의 가독성이 떨어지고,
    코드의 글로벌 스코프 전체에 영향을 주기 때문에
    C++ 에서는 사용되지 않음.

    대신, C++ 에서는 const 를 사용해서 특정 블록 내에서만 유효한
    상수를 선언할 수 있음.
*/
//#define PRICE_PER_ITEMS 30

using namespace std;

/*
    함수 매개변수에 const 를 사용하기

    함수의 매개변수를 선언한다는 것은,
    해당 함수 블록의 맨 첫째줄에 중괄호 안에 작성된 매개변수를
    선언한다는 의미를 가짐.

    또한, 선언과 동시에
    함수를 실행할 때 전달한 인자값을
    선언된 매개변수에 초기화한다는 의미도 가짐.

    따라서, 매개변수는 함수 블록의 첫번째 줄에서
    선언과 동시에 초기화되는 변수이고,
    이러한 매개변수의 값을 변경하는 경우는 거의 없고,
    변경하는 행위 자체가 권장되는 방식이 아니기 때문에,
    이를 아예 방지하기 위해 매개변수에 const 를 붙이는 경우가 많음.
*/
void printNumber(const int my_number)
{
    cout << my_number << endl;
}

int main()
{
    // Symbolic Constants (기호적 상수)
    // 리터럴 상수를 매직 넘버로 그대로 사용하는 것이 아니라,
    // 값을 변경할 수 없는 변수인 const(기호적 상수)에 담아놓고 쓰는 것.
    // 상수는 갚을 바꿀 수 없기 때문에, 선언과 동시에 초기화를 반드시 해줘야 함.
    //double const gravity{ 9.8 }; // 이렇게 const 를 변수 타입 뒤에 작성하는 것도 가능하지만, 일반적으로는 앞에 붙임.
    const double gravity{ 9.8 };

    printNumber(123);

    // my_const 는 이미 코드상에서 값을 초기화해놨기 때문에,
    // 컴파일 시점에 값이 결정이 됨.
    // 이렇게 컴파일 타임에 값이 결정되는 상수를 컴파일 상수라고 함.
    const int my_const(123);

    /*
        반면, 이렇게 변수로 상수를 초기화하는 경우,
        number 에 입력되는 값이 결정이 되는 시점이 되어야
        상수 special_number 의 값이 결정됨.

        이렇게 런타임에 값이 결정되는 상수를 런타임 상수라고 함.
    */
    int number;
    cin >> number;
    const int special_number(number);

    /*
        그래서 c++ 11 에서는
        런타임 상수와 컴파일 상수를 명확히 구분하기 위해,
        컴파일 상수를 constexpr 로 선언함으로써,
        컴파일러가 컴파일 타임에 값이 완전히 결정되는 상수를 체크하도록 함.

        그래서, special_number 상수를 constexpr 로 선언하면,
        빨간줄이 처지면서 에러가 남.
    */
    constexpr int my_const2(123);

    // 이렇게 const 로 상수를 정의하면 특정 블록 내에서만 유효한 상수를 만들 수 있음.
    const int price_per_items = 30;
    int num_item = 123;
    int price = num_item * price_per_items;

    double radius;
    cin >> radius;
    double circumference = 2.0 * radius * constants::pi; // 헤더파일의 특정 네임스페이스에 모아둔 상수를 가져다 쓰고 있음. > 다른 cpp 파일에서도 가져다 쓸 수 있는 재사용성!

    return 0;
}
