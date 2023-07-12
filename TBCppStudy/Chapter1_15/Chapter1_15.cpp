#include <iostream>

int main()
{
    using namespace std;

    bool bValue = false; // boolean
    //cout << (bValue ? 1 : 0) << endl; // 삼항연산자 복습
    cout << bValue << endl; // boolean 역시 타입 출력 시, 내부적으로 0 또는 1로 관리하고 있음을 알 수 있음.

    //char chValue = 'A';
    char chValue = 65;
    cout << chValue << endl; // char 를 문자열로 출력할 경우
    //cout << (int)chValue << endl; // char 를 정수형으로 형변환하여 출력할 경우

    float fValue = 3.141592f; // float 타입 실수형은 숫자 뒤에 반드시 f 를 붙여야 함.
    double dValue = 3.141592; // double 타입 실수형은 뒤에 f 를 붙이지 않음.
    cout << fValue << endl;
    cout << dValue << endl;

    // auto 타입은 할당 또는 초기화되는 값에 따라 
    // 변수의 타입이 컴파일 시점에 결정되도록 함. > 변수에 마우스 커서를 갖다대면 자동으로 결정된 타입 확인 가능!
    // Modern C++ 에 추가된 문법!
    auto aValue = 3.141592; 
    auto aValue2 = 3.141592f; 
    cout << aValue << endl;
    cout << aValue2 << endl;

    // sizeof() 변수 타입에 할당된 메모리 사이즈를 반환 (바이트 단위)
    cout << sizeof(aValue) << endl; // 8바이트 (double 로 타입이 결정되었으니까!)
    cout << sizeof(aValue2) << endl; // 4바이트 (float 으로 타입이 결정되었으니까!)

    // sizeof() 는 타입 또는 변수명이 메모리에서 차지하는 공간의 사이즈를 모두 확인할 수 있음.
    cout << sizeof(bool) << endl; // 1바이트
    cout << sizeof(bValue) << endl; // 1바이트

    // c++ 에서 변수를 초기화하는 3가지 방법
    // direct initialization, uniform initialization 은
    // 객체지향 프로그래밍에서 직접 정의한 데이터 타입을 초기화할 때 많이 사용함!
    int a = 123; // 변수 선언과 동시에 초기화 (copy initialization)
    int b(123); // 괄호 안에 값을 넣어 초기화 (direct initialization)
    int c{ 123 }; // 중괄호 안에 값을 넣어 초기화 (uniform initialization) > 객체지향 프로그래밍에서 아주 중요
    
    //int a2 = 3.1415; // 경고 발생 > 컴파일러가 자동으로 double 실수값을 int 정수형으로 변환하면서 소수점을 잘라버림 > 데이터 손실 경고 발생!
    int a2 = (int)3.1415; // 형변환 적용 시 경고가 사라짐. > 이러한 형 변환을 casting(캐스팅) 이라고 함!
    //int b2(3.14); // 경고 발생
    int b2((int)3.14); // 형변환 적용
    //int c2{ 4.5 }; // 에러 발생 > 다른 초기화 방법은 경고만 발생하고 컴파일러가 알아서 형변환 시키지만, uniform initialization 은 컴파일을 안해주고 엄격하게 에러 처리함!
    int c2{ 4 };

    int k, l, m; // 여러 변수를 동시에 한 번에 선언 > 단, 같은 데이터 타입에 대해서만 가능!

    /*
        변수는 어디에 선언하는 게 좋은가?

        사용할 변수는 
        사용하기 직전 위치에 선언하는 것이 최근 트렌드!

        그 이유는, 실제 그 변수를 사용하는 코드와
        변수를 선언하는 부분이 가까워야 디버깅하기 좋음.

        또한, 변수와 기능이 묶여있어야
        나중에 리팩터링하기 편함.
    */

    return 0;
}