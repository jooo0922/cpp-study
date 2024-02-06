#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string my_str("abcdefg");

    /*
        std::string 내에 정의된 
        [] 연산자 오버로딩을 사용하여
        문자열의 각 문자에 접근하기
    */
    cout << my_str[0] << endl;
    cout << my_str[3] << endl;

    // 특정 인덱스의 문자를 바꿔치기 하는 것도 가능!
    my_str[3] = 'Z';
    cout << my_str << endl;


    /*
        만약, 초기화된 문자열 길이를 넘어서는
        인덱스에 접근하려고 할 경우,

        std::string 은 어떻게 예외처리를 해줄까?
    */
    try
    {
        /*
            std::string 의 [] 오버로딩 연산자 내에는
            error throw 가 구현되어 있지 않음.

            따라서, 아래 코드와 같이
            [] 연산자를 통해 초기화된 문자열 길이를 넘어서는
            인덱스에 접근하려고 해도, runtime error 만 발생할 뿐,
            예외처리가 정상적으로 작동되지 않음.

            why? [] 연산자를 사용할 때,
            예외처리를 구현하면 성능이 느려질 수 있기 때문이라고 함!

            그래서,
            성능이 더 중요한 케이스에서는 std::string[] 을 사용하여 접근하고,
            예외처리 및 안정성이 중요한 케이스에서는 std::string.at() 을 사용하는 것을 권장!
        */
        // my_str[100] = 'X';

        // 대신, std::string.at() 에는 내부적으로 예외처리가 구현되어 있음!
        my_str.at(100) = 'X';
    }
    catch (std::exception& e)
    {
        /*
            예외 클래스를 std::exception 으로 정의하는 게 좋은 이유는
            https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter14/Chapter14_04/Chapter14_04.cpp 참고!
        */
        cout << e.what() << endl; // invalid string position
    }

    return 0;
}