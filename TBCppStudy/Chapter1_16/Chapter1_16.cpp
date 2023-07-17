#include <iostream>
#include <cmath>
#include <limits>

int main()
{
    using namespace std;

    // 동일한 정수값 1을 사이즈가 각기 다른 정수형 타입 변수로 초기화
    short s = 1; // 2 bytes = 2 * 8 bits = 16 bits > short 타입으로 표현할 수 있는 가장 큰 수는 2^16
    int i = 1;
    long l = 1;
    long long ll = 1;

    // 각 정수형 타입의 메모리 사이즈 확인
    cout << sizeof(short) << endl; // 2바이트
    cout << sizeof(int) << endl; // 4바이트
    cout << sizeof(long) << endl; // 4바이트
    cout << sizeof(long long) << endl; // 8바이트

    // 각 타입이 표현할 수 있는 가장 큰 수
    /*
        std::pow 는 cmath 안에 들어있는 제곱 계산 함수
    */
    cout << std::pow(2, sizeof(short) * 8) << endl; // 2^16 (65536)
    // 부호가 있는(signed) short 타입으로 표현할 수 있는 가장 큰 수는 32767 
    // 16 bits 중에서 부호를 표시할 bit 를 1개 빼서 15 bits > 2^15 이고,
    // 0을 제외해서 2^15 - 1 로 계산한 것
    cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl;

    // 각 타입이 사용할 수 있는 가장 큰 수를 컴파일러에게 물어보자
    // 컴파일러에게 물어보는 함수가 담긴 라이브러리가 <limits>
    cout << std::numeric_limits<short>::max() << endl; // 32767 (위와 동일)
    cout << std::numeric_limits<short>::min() << endl; // 표현할 수 있는 가장 작은 값 > -32768 (아까 0을 표현하느라 1을 뺐으니까 -32768까지 표현 가능)
    cout << std::numeric_limits<short>::lowest() << endl; // 마찬가지로 -32768

    /*
        이번 강의의 포인트는,
        각 타입이 표현할 수 있는 숫자 범위에는 제한이 있고,
        그 범위를 넘어서는 숫자를 표현하려는 순간 문제가 발생한다!
        를 보여주려는 것!
    */
    s = 32767;
    s = s + 1; // 32768 이 나와야겠지? > 실제로는 -32768 이 나옴.
    cout << "32768? " << s << endl;
    // 위 현상을 overflow 라고 함.
    // 32768 은 표현할 수 있는 가장 큰 숫자인 32767 을 넘어섰지? 거기에 1을 더한 값이지?
    // 그래서 이진수 상에 표현할 때 1을 더해버리면 오히려 뒤로 돌아가버림 > 그래서 가장 작은 수인 -32768 이 나온 것!

    // 이번에는 가장 작은 수 -32768 할당 및 출력
    s = std::numeric_limits<short>::min(); 
    cout << "min() " << s << endl;
    
    // 표현할 수 있는 가장 작은 수에서 1을 뺀 값 출력
    // 마찬가지로 -32769 가 나오지 않고, 32767 이 됨.
    // 이진수로 표현할 때 1을 빼버리니 똑같이 오히려 앞으로 돌아가버린 것. 
    // > 서로 끝이 맞물려서 범위를 초과할 시 반대쪽으로 돌아가는 상태
    s = s - 1;
    cout << " " << s << endl;

    return 0;
}