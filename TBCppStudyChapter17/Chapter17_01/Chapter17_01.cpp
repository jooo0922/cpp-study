#include <iostream>
#include <string> // std::string 클래스를 사용하기 위해 포함
#include <cstddef>
#include <locale>

using namespace std;

int main()
{
    // c-style string example -> 모든 문자열을 이렇게 다루기에는 너무 번거로움.
    {
        char* strHello = new char[7];
        strcpy_s(strHello, sizeof(char) * 7, "hello!");
        std::cout << strHello << std::endl;
    }

    return 0;
}