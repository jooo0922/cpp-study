#include <iostream>
#include <iomanip>
#include <limits> // 컴파일러에게 물어보는 함수가 담긴 라이브러리가 <limits>

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

    return 0;
}