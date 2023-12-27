#include <iostream>

/*
    템플릿


    어떤 함수나 클래스들이
    매개변수나 반환값의 타입만 다를 뿐,
    내부 구현이 동일하다면, 일일이 오버로딩할 게 아니라,

    컴파일러가 해당 타입들을 자동으로
    구현하도록 일을 시키는 방법은 없을까?

    이럴 때 필요한 것이 템플릿!
*/
template<typename T>

// 이제 아래 함수 getMax() 의 반환값과 매개변수 타입은 어떤 것이든 올 수 있음!
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    return 0;
}