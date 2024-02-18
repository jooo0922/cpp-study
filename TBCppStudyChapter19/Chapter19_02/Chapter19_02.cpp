#include <iostream>
#include <tuple> // 수학에서의 tuple 개념은 '여러 개의 데이터 쌍' 을 의미함.

using namespace std;

/*
    C++ 17 이후 tuple 의 문법이 아주 편리해졌기 때문에,
    
    C++ 함수에서 tuple 을 이용하여
    여러 개의 반환값을 리턴하는 문법을 편리하게 사용할 수 있게 됨!

    일단, tuple 로 여러 개의 리턴값을 반환하려는 함수의
    반환 타입을 auto 로 지정하여 자동 형변환 하도록 해주고,

    값을 return 하는 지점에서
    원하는 반환값만큼 tuple(...) 안에 넣어주면 됨.  
*/
auto my_func()
{
    return tuple(123, 456, 789, 10);
}

int main()
{
    /*
        tuple 로 여러 개의 반환값을 받을 때에는,
        
        해당 함수가 반환해주는 리턴값의 갯수에 맞춰서
        auto [...] 안에 각 반환값을 복사할 변수들을 선언해주면 됨.
    */
    auto [a, b, c, d] = my_func();

    cout << a << " " << b << " " << c << " " << d << " " << endl;

    return 0;
}