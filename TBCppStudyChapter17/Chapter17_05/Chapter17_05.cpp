#include <iostream>
#include <string>

using namespace std;

int main()
{
    /* 문자열 대입 및 덧붙이기 */

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

    // std::string 문자열이 하나의 '동적 배열'임을 전제로 하여,
    // 마치 vector 처럼 하나의 문자 요소 씩 push_back 하여 덧붙이는 것도 가능
    str2.push_back('A');

    // additive assignment 연산자(+=) 오버로딩을 활용하여 std::string.append() 와 동일하게 사용 가능!
    str2 += " four";

    // add 연산자 (+) 오버로딩을 활용하여 std::string.append() 와 동일하게 사용 가능!
    str2 = str2 + " five";

    cout << str2 << endl;


    /* 문자열 교환하기 */

    string string1("one");
    string string2("two");

    // std::swap() 으로 문자열 교환 전 출력
    cout << string1 << " " << string2 << endl;

    std::swap(string1, string2);

    // std::swap() 으로 문자열 교환 후 출력
    cout << string1 << " " << string2 << endl;

    // std::string 내에 존재하는 swap() 메서드를 사용하여 문자열 교환
    string1.swap(string2);

    // std::string.swap() 으로 문자열 교환 후 출력
    cout << string1 << " " << string2 << endl;


    /* 문자열 삽입하기 */

    string str("aaaa");

    /*
        std::string.insert(size_t offset, const char*)

        현재 문자열 상에서 offset 지점의 위치를 시작으로
        뒤에 전달되는 문자열을 삽입하는 기능!
    */
    str.insert(2, "bbb");

    cout << str << endl;

    return 0;
}