#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    /* 
        std::string 내부에 구현된(== 오버로딩된) 
        여러가지 생성자들을 자주 사용되는 것 위주로 정리해보자.
    */

    //string my_string; // default constructor (기본 생성자)
    string my_string("my string");
    string second_string(my_string); // copy constructor (복사 생성자)

    cout << my_string << endl;
    cout << second_string << endl;

    return 0;
}