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

    return 0;
}