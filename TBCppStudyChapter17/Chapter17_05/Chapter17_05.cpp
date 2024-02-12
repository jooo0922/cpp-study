#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1("one");

    string str2;
    str2 = str1;
    str2 = "two";

    /*
        std::string.assign(const char*)

        c-style 문자열을 할당하는 기능!

        마우스를 갖다 대보면,
        반환값이 std::string 자기 자신에 대한 참조변수인
        std::string& 로 나옴.

        즉, method chaining 을 사용할 수 있다는 뜻!

        .append() 같은 std::string 메서드를 연달아 사용 가능!

        참고로,
        std::string.append(const char*)는
        뒤에 문자열을 추가로 덧붙이는 기능!
    */
    str2.assign("two").append(" ").append("three");

    cout << str2 << endl;

    return 0;
}