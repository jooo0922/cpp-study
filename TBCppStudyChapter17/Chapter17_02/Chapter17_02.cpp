#include <iostream>
#include <string>
#include <vector>
#include <sstream> // string stream 의 약자. 문자열 입출력 스트림을 사용하기 위해 포함

using namespace std;

/*
    어떤 타입의 값이던지 문자열로 변환해주는 함수 구현
*/
template <typename T>
std::string ToString(T x)
{
    // 문자열 출력 스트림을 하나 만든다.
    std::ostringstream osstream;

    // 매개변수로 들어온 x 의 타입이 뭐가 됐건 문자열 출력 스트림에 넣어버림.
    osstream << x;

    /*
        std::ostringstream.str() 은
        출력 스트림 연산자로 들어온 값의 타입이 뭐가 됐건,
        무조건 문자열로 변환해서 던져줌.
    */
    return osstream.str();
}

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
    //string my_str(std::to_string(1004));

    // 문자열 출력 스트림 std::ostringstream 을 사용해서 문자열 변환하기
    string my_str(ToString(3.141592));

    // 변환된 문자를 다시 int 또는 float 타입으로 되돌리기
    int i = std::stoi(my_str);
    int f = std::stof(my_str);
    cout << i << endl;
    cout << f << endl;

    // 변환된 문자를 뒤에 이어붙이는 것도 가능!
    //my_str += std::to_string(128);

    cout << my_str << endl;

    return 0;
}