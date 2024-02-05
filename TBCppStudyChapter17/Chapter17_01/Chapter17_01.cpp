#include <iostream>
#include <string> // std::string 클래스를 사용하기 위해 포함
#include <cstddef>
#include <locale>

using namespace std;

int main()
{
    // c-style string example -> 모든 문자열을 이렇게 다루기에는 너무 번거로움.
    //{
    //    char* strHello = new char[7];
    //    strcpy_s(strHello, sizeof(char) * 7, "hello!");
    //    std::cout << strHello << std::endl;
    //}

    // basic_string<>, std::string, std::wstring
    {
        /*
            std::string, std::wstring 을 살펴보면,
            결국 basic_string<> 이라는 클래스 템플릿으로부터 만들어진
            템플릿 인스턴스들이라고 보면 됨.

            std::wstring 은
            basic_string<wchar_t, ...> 와 같이 만든
            템플릿 인스턴스임.
        */
        std::string string;
        std::wstring wstring;

        /*
            wchar_t 는 내부적으로
            typedef unsigned short 로
            정의되어 있음.

            이러한 타입 별칭을 왜 만들어뒀냐?

            char 타입이 메모리 사이즈가 작기 때문에
            표현할 수 있는 글자 수의 한계가 있음.

            그래서, 메모리를 많이 잡아먹는 문자나 기호를
            저장할 때 주로 사용함.

            주로 wide character / unicode 등...
        */
        wchar_t wc;
    }

    return 0;
}