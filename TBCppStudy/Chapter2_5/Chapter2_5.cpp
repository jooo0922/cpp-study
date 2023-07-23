#include <iostream>
#include <iomanip> // io manipulator 즉, 입출력 조작 관련 라이브러리 > 숫자를 몇째자리 수까지 출력할 것인지 옵션 조정 가능
#include <limits> // 컴파일러에게 물어보는 함수가 담긴 라이브러리가 <limits>
#include <cmath> // std::isnan() 함수를 사용하기 위해 포함한 라이브러리 (현재 숫자가 nan 인지 boolean 값으로 반환)

int main()
{
    using namespace std;

    // float 타입 숫자형 할당 시, 숫자 뒤에 f 를 붙여줘야 함. 
    // 안붙이면 double 타입 실수를 float 변수에 할당하는 꼴이 되어서, 
    // 컴파일러가 실수를 float 타입으로 자동 형변환(캐스팅) 해줌.
    float f(3.141592f); // 4 bytes
    double d(3.141592); // 8 bytes
    long double ld(3.141592); // 8, 12, 16 bytes (컴파일러 or 운영체제마다 다름)

    cout << sizeof(f) << endl; // 4 bytes
    cout << sizeof(d) << endl; // 8 bytes
    cout << sizeof(ld) << endl; // 8 bytes -> long double 이랑 double 이랑 같네? 차이가 없나? 최대 사이즈를 limits 안의 함수로 찍어보자! (시스템마다 다르니 확인해봐야 함!)

    // 각 타입이 표현할 수 있는 가장 최대, 최소, 가장 작은 수(max(), min(), lowest())를 
    // 컴파일러에게 물어보자 (std namespace 선언되어 있으니 생략)
    cout << numeric_limits<float>::lowest() << endl;
    cout << numeric_limits<double>::lowest() << endl;
    cout << numeric_limits<long double>::lowest() << endl;

    // 3.14 를 표현하는 여러 가지 방법
    // 참고로, e 는 scientific notation 이라고도 하는데, 
    // 과학분야에서 큰 수를 다룰 때 표기하기 편하도록 만든 기호라는 의미
    cout << 3.14 << endl;
    cout << 31.4e-1 << endl; // 여기서 e 는 10진수를 의미. 즉, e-1 은 10의 -1제곱을 의미. 따라서, '31.4 * 10^-1' 이라는 뜻이지!
    cout << 31.4e-2 << endl; // 31.4 * 10^-2
    cout << 31.4e1 << endl; // 31.4 * 10^1
    cout << 31.4e2 << endl; // 31.4 * 10*2

    cout << std::setprecision(16); // setprecision(몇째자리) 로 앞으로의 출력에 대해 몇째자리 수까지 출력할 지 옵션 설정 가능
    cout << 1.0 / 3.0 << endl; // 그냥 출력하면 0.333333 까지만 출력됨. 이거보다 더 길게 0.3333333333333333.... 쯕 나오게 하려면 iomanip 라이브러리를 사용해야 함!

    float ff(123456789.0f); // 10 significant digits (유효숫자 10개)

    cout << std::setprecision(9); // 9번째 자릿수까지 출력하도록 설정
    cout << ff << endl; // 123456792 이런 식으로 나옴. > 부동소수점이 이진수로 저장되어 있어 우리가 생각하는 것과 다르게 나옴

    double dd(0.1);
    cout << dd << endl; // 0.1
    cout << std::setprecision(17); // 17번째 자릿수까지 출력하도록 설정
    cout << dd << endl; // 0.10000...1 (마지막에 1이 하나 더 붙음 > 이진수로 부동소수점 표현할 수 있는 0.1에 가장 가까운 수가 이거라고 생각하면 됨.)

    // 상식적으로 d1 과 d2 는 출력 시 동일하게 1이 나와야 할 것 같음.
    double d1(1.0);
    double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
    cout << setprecision(17); // 17번째 자릿수까지 출력하도록 설정
    cout << d1 << endl; // 1
    cout << d2 << endl; // 0.9999...89 (위에 dd 를 17번째 자릿수까지 출력했을 때 0.1000...1 이 나왔던 것처럼, d2 에서 0.1 들의 오차가 누적되어 17번째 자릿수까지 출력하면 실제 1과 다른 값으로 출력됨.)

    double zero = 0.0;
    double posinf = 5.0 / zero; // 5.0 을 0.0 으로 나누면? positive infinity (양의 무한대)
    double neginf = -5.0 / zero; // 5.0 을 0.0 으로 나누면? negative infinity (양의 무한대)
    double nan = zero / zero; // Not a Number

    cout << posinf << " " << std::isinf(posinf) << endl; // inf
    cout << neginf << " " << std::isinf(neginf) << endl; // -inf
    cout << nan << " " << std::isnan(nan) << endl; // -nan(ind) > 여기서 ind 는 indeterminate, 즉, '결정할 수 없다' 정도의 뜻을 가짐.
    cout << 1.0 << " " << std::isnan(1.0) << endl; // 1.0 은 nan 이 아니므로 0(false) 가 출력

    return 0;
}