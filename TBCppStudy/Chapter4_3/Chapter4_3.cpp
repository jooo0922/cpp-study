#include <iostream>

namespace a
{
    int my_var(10);
    int my_a(123);
    int count(12341234);
}

namespace b
{
    int my_var(20);
    int my_b(345);
}

int main()
{
    using namespace std;

    // using 문으로 이렇게 std 네임스페이스 안의 특정 함수만 가져다가 쓸수도 있음. 
    // 이렇게 특정 함수를 바로 가져올 때에는, namespace 키워드를 사용하면 안됨.
    // 그러나 대부분, std 안의 많은 함수들을 이것저것 가져다가 사용하는 경우가 많아서,
    // 이렇게 함수 하나하나를 일일이 using 으로 가져다가 쓰지는 않음.
    /*using std::cout; 
    using std::endl;*/

    //using namespace a;
    //using namespace b;

    cout << "Hello " << endl;

    /*
        서로 다른 네임스페이스를 동시에 using 한 뒤,
        각 네임스페이스에 초기화된 동일한 변수를 사용하려고 하면,
        "'my_var' is ambiguous." 라는 에러가 뜸.

        즉, namespace a 와 b 모두에 my_var 변수가 정의되어 있어,
        a 에 있는 놈을 말하는 건지, b에 있는 놈을 말하는 건지 모르겠다는 의미지!
    */
    //cout << a::my_var << endl; // 모호성을 해결하려면 이렇게 영역지정 연산자(::)를 사용하는 방법도 있음.

    // 또는, 이렇게 using 문을 block 으로 각각 감싸줘서 스코프를 쪼개는 방법도 있음!
    /*
        이처럼, using 문 자체가 약간의 위험성을 갖고 있기 때문에
        특히, 헤더파일에서 using 문을 여러 개 선언해놓은 다음에
        다른 .cpp 파일에서 해당 헤더파일을 include 해서 사용하는 경우,
        예상치 못한 문제들이 여럿 발생할 수 있다.

        따라서, using 문은 사용하고자 하는 .cpp 파일 내에서만
        사용하는 것이 안전하다!

        즉, 가급적 전역 스코프에서 사용하는 것 만큼은 자제하는 게 좋다!
        
        -> 이처럼, 변수들은 지역변수처럼 가급적 
        적은 범위(스코프) 내에서만 영향을 주는 것이
        좋은 프로그래밍 습관이다! (특히 객체지향 프로그래밍)
    */
    {
        using namespace a;
        cout << my_var << endl;
        //cout << count << endl; // 이 경우에도 ambiguous 에러가 발생하는데, std 네임스페이스 안에도 count 가 선언되어 있기 때문!
        cout << a::count << endl; // 이럴 경우는 정말 어쩔 수 없이 영역지정 연산자를 사용해서 네임스페이스를 명시해줘야 함.
    }

    {
        using namespace a;
        cout << my_var << endl;
    }

    // 이렇게 각 네임스페이스에 정의된 변수의 이름이 서로 다르면 상관이 없음!
    //cout << my_a << endl; 
    //cout << my_b << endl;

    return 0;
}
