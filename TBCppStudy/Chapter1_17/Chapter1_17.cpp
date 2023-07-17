#include <iostream>
//#include <cstdint>

/*
    고정 너비 정수

    c++ 11 버전 이후부터는
    어떤 컴파일러와 운영체제를 사용하더라도

    각 정수형 타입의 실제 메모리 크기를
    모두 동일하게 사용할 수 있는

    고정 너비 정수 (Fixed-width Integers)를 지원한다.

    #include <cstdint> 라이브러리를 포함하면 사용 가능!
    단, 이는 #include <iostream> 내부에서도 include 하고 있기 때문에,
    iostream 라이브러리를 사용하고 있다면 별도의 include 를 하지 않아도 됨!
*/

int main()
{
    using namespace std;

    std::int16_t i(5); // 현재 플랫폼의 16 bits (= 2 Bytes) 의 정수형 타입으로 바꿔주는 것! > 마우스 오버 하면 short 라고 뜸.
    std::int8_t myint = 65; // 현재 플랫폼의 8 bits (= 1 Byte) 의 정수형 타입으로 바꿔줌. > char 타입으로 변환해 줌.
    // > 문제는, 컴파일러는 이 변수를 진짜로 char 타입으로 읽어서, 65 라는 정수를 입력하면 숫자를 출력하는 게 아니라, 65의 아스키코드인 A 를 출력함.
    // > 가급적 정수형을 사용할 때에는 std::int8_t 를 안쓰는 게 좋다고 함.

    cout << myint << endl;

    std::int_fast8_t fi(5); // 8 bits 중 가장 빠른 것 > 마우스 오버 시 signed char 로 변환함을 알 수 있음.
    std::int_least64_t fl(5); // 적어도 64 bits (= 8 Bytes)를 받는 데이터 타입 > long long 으로 변환됨.

    return 0;
}
