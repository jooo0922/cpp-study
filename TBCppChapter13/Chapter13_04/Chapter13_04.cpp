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
    // 함수 템플릿을 사용할 때에는, 아래와 같이 '꺽쇠 안에 템플릿 파라미터 전달' 라는 부분이 '생략'된 것으로 보면 됨! 
    //cout << getMax<int>(1, 2) << endl; // int

    // 따라서, 함수에 전달되는 실제 리터럴 값을 템플릿 파라미터에 전달하는 타입으로 강제 형변환하는 것도 가능함!
    cout << getMax<double>(1, 2) << endl; // double

    return 0;
}