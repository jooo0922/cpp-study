#include <iostream>
#include "Cents.h"

using namespace std;

/*
    템플릿


    어떤 함수나 클래스들이
    매개변수나 반환값의 타입만 다를 뿐,
    내부 구현이 동일하다면, 일일이 오버로딩할 게 아니라,

    컴파일러가 해당 타입들을 자동으로
    구현하도록 일을 시키는 방법은 없을까?

    이럴 때 필요한 것이 템플릿!

    템플릿을 typename 으로 지정하면,
    우리가 일일이 손으로 int, float, double, ... 등등의
    타입들에 대해서 오버로딩 함수를 쳐줘야 할 것을

    컴파일러가 알아서 내부적으로
    다 만들어줄 수 있게 됨!
*/
template<typename T>

/*
    그렇다면,
    위와 같이 built-in 데이터 타입만 템플릿으로 넣을 수 있는걸까?

    물론 class, struct 등의
    user-defined 데이터 타입도 넣을 수 있음!
*/

// 이제 아래 함수 getMax() 의 반환값과 매개변수 타입은 어떤 것이든 올 수 있음!
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << getMax(1, 2) << endl; // int
    cout << getMax(3.14, 1.592) << endl; // double
    cout << getMax(1.0f, 3.4f) << endl; // float
    cout << getMax('a', 'c') << endl; // float

    // 클래스같은 user-defined 자료형을 템플릿으로 사용하려면,
    // 템플릿으로써 작동하기 위해 필요한 기능들(ex> 연산자 오버로딩 등)이 미리 구현되어 있어야 함!
    cout << getMax(Cents(5), Cents(9)) << endl;

    return 0;
}