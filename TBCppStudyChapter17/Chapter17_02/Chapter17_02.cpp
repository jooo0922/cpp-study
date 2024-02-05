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
    //string my_string("my string");
    const char* my_string = "my string"; // c-style string 도 매개변수로 전달 가능

    // STL 컨테이너의 한 종류인 std::vector<> 자체를 문자열 매개변수로 전달하는 것도 가능함!
    vector<char> vec;
    for (auto e : "Today is a good day.")
    {
        vec.push_back(e);
    }
    string second_string(vec.begin(), vec.end()); // char 타입 문자가 추가된 컨테이너의 반복자를 매개변수로 전달

    //string second_string(my_string); // copy constructor (복사 생성자)
    //string second_string(my_string, 3, 5); // 출력 결과 : strin -> 맨 앞의 문자 3개를 자르고, 거기서부터 5개 까지의 글자만 가져옴.
    //string second_string(10, 'A'); // 출력 결과 : AAAAAAAAAA -> 두 번째 매개변수로 전달된 문자열을 10번 출력함.

    cout << second_string << endl;

    // 숫자 -> 문자로 변환한 후, std::string 생성자 매개변수에 전달하는 트릭도 알아둘 것!
    string my_str(std::to_string(1004));

    // 변환된 문자를 뒤에 이어붙이는 것도 가능!
    my_str += std::to_string(128);

    cout << my_str << endl;

    return 0;
}