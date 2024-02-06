#include <iostream>
#include <string>

using namespace std;

int main()
{
    string my_str("012345678");

    /*
        c-style 문자열인 char* 은
        문자열의 종료 부분을 표시하기 위해,
        null character 인 '\0' 을 항상 갖고 있음.

        그러나, std::string 는 클래스이므로,
        종료문자를 통해 문자열의 종료 부분을 굳이 표시할 필요가 없고,
        
        문자열의 길이값을 내부적으로 갖고 있어서,
        이를 std::string.size() 함수를 통해 가져올 수 있음.
    */
    cout << my_str.size() << endl; // 9

    /*
        std::string 에 문자열이 비어있는지 여부를 출력
    */
    cout << std::boolalpha; // 'true' 또는 'false' 로 출력되도록 설정
    cout << my_str.empty() << endl; // false

    return 0;
}