#include <iostream>

using namespace std;

template<typename T>

// 이제 아래 함수 getMax() 의 반환값과 매개변수 타입은 어떤 것이든 올 수 있음!
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << getMax(1, 2) << endl; // int

    return 0;
}