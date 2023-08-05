#include <iostream>
#include <iomanip> // io manipulator 즉, 입출력 조작 관련 라이브러리 > 숫자를 몇째자리 수까지 출력할 것인지 옵션 조정 가능 (setprecision() 사용할 때 포함해줘야 함!)
#include <typeinfo> // 어떠한 리터럴의 타입(자료형)을 출력할 수 있게 도와주는 기능들을 갖고 있는 라이브러리

int main()
{
    using namespace std;

    // 암시적 형변환
    // 프로그래머가 요구하지도 않았는데, 컴파일러가 알아서 형변환을 해주는 경우!
    // double 타입의 리터럴 123.0 을 int 타입 변수에 넣어주면, 
    // 컴파일러가 강제로 암시적 형변환을 해서 변수에 대입함.
    //int a = 123.0;

    // 암시적 형변환에는 2가지 케이스가 있음.
    // 작은 타입 > 큰 타입 변환
    // 아래와 같이, 메모리 용량이 더 작은 float 타입을
    // 메모리 용량이 더 큰 double 타입으로 암시적 형변환
    // 메모리가 더 큰 곳으로 가는 것이니, a 입장에서는 리터럴 값의 정밀도가 떨어질 걱정이 없으니
    // 딱히 손해볼 것이 없음! > 이런 것을 numeric promotion 이라고 함. 일종의 '승진' 개념. 
    // 더 좋은 곳으로 갔구나, 더 넓은 곳으로 갔구나 하는 느낌!
    float a = 1.0f;
    double d = a;

    // numeric conversion
    // 암시적 형변환에서 위와 반대로, 큰 타입 > 작은 타입으로 변환되거나,
    // 정수형이 실수형으로 바뀌는 등 아예 타입의 '종류'가 바뀌는 경우!
    double e = 3;
    short s = 2;

    // numeric conversion 예시
    // int 는 char 보다 메모리 용량이 큰 타입이고,
    // 30000 이라는 정수값은 1 byte 짜리 char 타입에는 담을 수 없는 리터럴임.
    // 물론 2 정도의 작은 값을 넣으면 큰 문제는 없음.
    int i = 30000;
    char c = i;
    cout << static_cast<int>(c) << endl; // 48 ... 30000 과는 전혀 동떨어진 숫자가 출력됨.

    double dd = 0.123456789;
    float ff = dd;
    cout << std::setprecision(12) << ff << endl; // 0.123456791043 같은 부정확한 숫자가 나옴. > float 은 double 에 비해 정밀도가 부족하기 때문에 형변환 시, 부정확한 값이 저장됨

    float fff = 3.14;
    int ii = fff;
    cout << std::setprecision(12) << ii << endl; // float > int 로 암시적 형변환 시, 소수부분은 버림

    // unsigned 관련 이슈
    // 아래에서 5u 에 u 는 'unsigned' 를 의미. 즉, 양수 5라고 보면 됨.
    // 형변환 시, int 보다 unsigned int 가 우선순위가 높기 때문에,
    // 10 을 형변환하지 않아서 부정확한 계산 결과가 나왔던 것!
    // 형변환 우선순위를 참고로 적자면, 아래와 같음. -> 대체로 unsigned 타입이 우선순위가 더 높다는 것 정도만 알아둘 것!
    // int < unsigned int < long < unsigned long < long long < unsigned long long < float < double < long double
    cout << 5u - 10; // 근데 결과값이 4294967291 로 나옴??? 5 - 10 이???

    // 명시적 형변환
    // 아래와 같이, 프로그래머가 직접적으로 형변환을 명시해주는 것!
    int i = int(4.0); // c++ 스타일 캐스팅. int 타입의 인스턴스를 하나 만들어서 변수에 대입한다는 의미에 가까움.
    int ii = (int)4.0; // c 스타일 캐스팅
    int iii = static_cast<int>(4.0); // 최신 스타일 > 이게 좀 더 좋다고 함. 그러나 앞의 것들과 기능상의 차이는 없음.


    // typeid(리터럴).name() 으로 하면, 인자로 넣은 리터럴의 타입을 콘솔로 출력해 줌.
    // 이런 도구가 굳이 왜 필요하나? > 복잡한 형변환 과정을 거칠 때, 타입을 알아내려면 필요한 도구 중 하나!!
    //cout << typeid(a).name() << endl;

    return 0;
}
