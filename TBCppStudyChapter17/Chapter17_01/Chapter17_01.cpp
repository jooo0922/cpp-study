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

    // wstring example
    {
        /*
            std::wstring 은 주로 아래와 같이
            메모리를 많이 잡아먹는 국제어 문자를 저장할 때
            사용하기 좋은 문자열 클래스라고 보면 됨!

            wchar_t 가 주로
            이러한 국제어를 저장하기 위한 변수 타입으로 사용됨!
        */
        const std::wstring texts[] =
        {
            L"안녕하세요?", // Korean
            L"Ñá", //Spanish
            L"forêt intérêt", //French
            L"Gesäß", //German
            L"取消波蘇日奇諾", //Chinese
            L"日本人のビット", //Japanese
            L"немного русский", //Russian
            L"ένα κομμάτι της ελληνικής", // Greek
            L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
            L"کمی از ایران ", // Persian (I know it, from 300 movie)
            L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
            L"Но какво, по дяволите, е това?" //Bulgarian
        };

        // 사용자 시스템의 지역 설정을 기본 지역 설정으로 설정
        std::locale::global(std::locale(""));

        // wide character 출력 스트림인 std::wcout 의 지역 설정을 사용자 시스템의 지역 설정으로 설정
        std::wcout.imbue(std::locale());

        // std::wstring 출력
        for (size_t i = 0; i < 12; i++)
        {
            // 아래처럼 std::wstring 및 wchar_t 는 출력 스트림도 별도로 존재함.
            std::wcout << texts[i] << std::endl;
        }
    }

    return 0;
}