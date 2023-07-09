#include <iostream>

/*
    아래와 같이,
    이름은 동일한데, 하는 일이 다른
    두 함수를 만들었다고 치자.

    동일한 이름을 가진 두 함수가 존재하면
    당연히 빌드에러가 발생할 것임.

    그러나, 경우에 따라서는,
    두 함수의 이름을 동일하게 유지하고 싶은
    경우가 있을 수도 있음.

    이럴 경우 사용하는 것이 네임스페이스!
*/

namespace MySpace1
{
    // 네임스페이스 안에 네임스페이스를 또 넣을 수 있음!
    namespace InnerSpace
    {
        int my_function()
        {
            return 0;
        }
    }

    int doSomething(int a, int b)
    {
        return a + b;
    }
}

namespace MySpace2
{
    int doSomething(int a, int b)
    {
        return a * b;
    }
}

/*
    std 네임스페이스

    iostream 을 통해 include 한 cout, cin, endl 등의 코드들은
    std 네임스페이스 안에 정의가 되어있음.

    즉, iostream 문서를 열면, 
    그 안에 std 네임스페이스로 묶여서 위 코드들이 정리되어 있다는 뜻!
*/
using namespace std;

int main()
{
    //MySpace1::doSomething(3, 4); 이렇게 매번 번거롭게 네임스페이스를 붙여주는 걸 생략하기 위해, using 문을 추가해줘야 함.
    //using namespace MySpace1;
    //doSomething(3, 4);

    // 아래와 같이 네임스페이스 안의 네임스페이스도 using문으로 가져와서 사용 가능
    using namespace MySpace1::InnerSpace;

    my_function();

    //cout << MySpace1::doSomething(3, 4) << endl; // 네임스페이스 MySpace1 에 정의된 doSomething 함수 실행
    //cout << MySpace2::doSomething(3, 4) << endl; // 전역 스코프에 정의된 doSomething 함수 실행

    return 0;
}