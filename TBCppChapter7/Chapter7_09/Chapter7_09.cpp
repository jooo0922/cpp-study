#include <iostream>
#include <array>
#include <functional> // c++ 11 부터 추가된 기능!

using namespace std;

int func()
{
    return 5;
}

int goo()
{
    return 10;
}

// 짝수 여부 검사 함수
bool isEven(const int& number)
{
    if (number % 2 == 0) return true;
    else return false;
}

// 홀수 여부 검사 함수
bool isOdd(const int& number)
{
    if (number % 2 != 0) return true;
    else return false;
}

// 어떤 함수 포인터 타입이 자주 사용된다면, 매번 선언해서 쓰기 귀찮을테니, 
// 하나의 사용자 정의 타입으로 선언해서 사용하는 것도 가능!
//typedef bool(*check_fcn_t)(const int&);

// 타입 별칭(type alias)으로도 선언 가능 -> typedef 와 완전히 동일한 기능임
// https://github.com/jooo0922/cpp-study/blob/main/TBCppStudy/Chapter4_9/Chapter4_9.cpp 참고!
using check_fcn_t = bool(*)(const int&);

// 배열을 const 참조변수(=입력 매개변수) 로 받아서 짝수 또는 홀수 출력 함수
// 이때, 짝수 또는 홀수 여부 검사 함수를 함수 포인터 변수 매개변수를 선언하여 받음!
// -> 함수 포인터를 다른 함수의 매개변수로 선언하여 사용할 수 있구나!
// 또한, 함수 포인터 매개변수에는 기본값(default)도 할당 가능!
void printNumbers(const array<int, 10>& my_array, check_fcn_t check_fcn = isEven)
{
    for (auto element : my_array)
    {
        if (check_fcn(element) == true) cout << element; // 짝수 출력
    }
    cout << endl;
}

// c++ 11 에 추가된 functional 을 사용해서 매개변수를 함수 포인터 타입으로 정의하기
void printNumbers2(const array<int, 10>& my_array, std::function<bool(const int&)> check_fcn)
{
    for (auto element : my_array)
    {
        if (check_fcn(element) == true) cout << element; // 짝수 출력
    }
    cout << endl;
}

int main()
{
    // 함수를 괄호() 를 붙여 실행하는 게 아니라, 그냥 함수 이름 자체를 출력 > 주소값이 출력됨
    // 아, 함수도 결국에는 포인터 변수구나! 함수도 메모리에 들어오는 거구나!
    cout << func << endl;

    // 이렇게 함수가 호출되면, 이 함수에 저장된 주소값으로 함수가 저장된 메모리 공간을 찾아감.
    // 그리고 그 메모리 공간에 저장된 프로그램을 가져다가 실행시킴.
    // 또, 함수가 종료되고 나서 나중에 어디로 돌아와야 할 지도 가지고 있게 됨. > 스택과 힙에서 더 자세히 설명
    func();

    // 함수 포인터 변수 선언 및 다른 함수의 주소값을 할당하여 초기화
    // 참고로, fcnptr 은 해당 함수 포인터 변수에 대한 임의의 이름이며, 원하는 대로 지을 수 있음.
    int (*fcnptr)() = func;

    cout << fcnptr() << endl; // 5 > func 함수의 주소값이 할당되어 해당 함수 실행

    // 함수 포인터 변수의 주소값을 다른 함수의 주소값으로 바꿔치기할 수 도 있음.
    fcnptr = goo;

    cout << fcnptr() << endl; // 10 > goo 함수의 주소값이 할당되어 해당 함수 실행


    std::array<int, 10> my_array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };


    // 함수 포인터를 매개변수로 선언했기 때문에, 함수를 직접 인자로 전달 가능
    printNumbers(my_array); // 아무런 인자를 전달하지 않으면, 기본값 함수 포인터인 isEven 이 실행될 것임.
    printNumbers(my_array, isOdd);

    // functional 기능 사용해보기
    std::function<bool(const int&)> fcnptr2 = isEven;

    // c++ 11 functional 을 사용해서 함수 포인터와 동일하게 사용할 수 있음!
    printNumbers2(my_array, fcnptr2);

    fcnptr2 = isOdd;

    printNumbers2(my_array, fcnptr2);

    return 0;
}