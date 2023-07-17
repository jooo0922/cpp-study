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

    std::int16_t i(5);
    std::int8_t myint = 65;

    cout << myint << endl;

    std::int_fast8_t fi(5);
    std::int_least64_t fl(5);

    return 0;
}
