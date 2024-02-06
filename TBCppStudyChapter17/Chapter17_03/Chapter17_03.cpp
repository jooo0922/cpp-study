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
    cout << my_str.length() << endl; // 9


    /*
        std::string.empty() 를 통해 문자열이 비어있는지 여부를 출력
    */
    cout << std::boolalpha; // 'true' 또는 'false' 로 출력되도록 설정
    cout << my_str.empty() << endl; // false


    /*
        std::string.capacity() 를 통해 문자열의 '용량' 출력

        왜 .size() 또는 .length() 와 
        .capacity() 값이 차이가 날까?

        std::string 에서는 내부적으로 
        new, delete 등의 키워드에 의한 메모리 재할당을 최소화하고자 함.

        왜냐하면, memory reallocation(재할당)는
        속도가 느려지고 성능이 저하되는 주된 원인이므로,
        
        처음부터 메모리를 여유롭게 잡아놓고,
        추후 문자열이 추가되거나 변경되면,

        미리 여유롭게 잡아놓은 메모리 덕분에
        new, delete 등의 키워드로 불필요한 메모리 재할당 과정을 거치지 않아도 됨!

        그러다 보니,
        실제 문자열 길이보다
        메모리 용량을 여유롭게 잡아놓기 때문에

        .capacity() 로 반환받는 값이
        .size(), .length() 로 반환받는 값보다 더 크게 출력되는 것임.
    */
    cout << my_str.capacity() << endl; // 15

    return 0;
}