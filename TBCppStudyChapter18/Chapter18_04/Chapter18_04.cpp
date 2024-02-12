#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

// 스트림 상태 출력 함수 
// (참고로, std::ios 는 대부분의 stream 클래스들이 상속받는 상위 부모 클래스)
void printState(const std::ios& stream)
{
    cout << boolalpha;
    cout << "good()=" << stream.good() << endl; // 스트림 상태가 좋은지 출력
    cout << "eof()=" << stream.eof() << endl; // 스트림의 파일을 다 읽었는지(end of file) 출력
    cout << "fail()=" << stream.fail() << endl; // 스트림 상태가 실패했는지 출력
    cout << "bad()=" << stream.bad() << endl; // 스트림 상태가 나쁜지 출력
}

int main()
{
    while (true)
    {
        int i;

        // 만약 입력 스트림에 int 타입이 아닌 문자열이 입력된다면 어떻게 유효성을 검증할 수 있을까?
        cin >> i;

        /* 입력 스트림에 입력된 값의 유효성 검증을 위해, 스트림 상태를 확인해보자 */

        // 입력 스트림 istream 상태를 출력함
        printState(cin);

        // cin.rdstate() 로 현재 입력 스트림 상태를 bit flag 로 읽어온 후, boolean 으로 출력!
        /*
            bit flag 로 스트림 상태의 유효성을 검증하기도 하지만,
            
            모던 C++ 로 갈수록 
            위의 printState() 함수에서 구현한 것처럼
            스트림 상태를 검증하는 방식을 더 권장한다고 함.
        */
        //cout << boolalpha;
        //cout << std::bitset<8>(cin.rdstate()) << endl;
        //cout << std::bitset<8>(std::istream::goodbit) << endl;
        //cout << std::bitset<8>(std::istream::failbit) << endl;

        //// failbit 으로 비트마스킹하여 현재 입력 스트림의 fail 상태를 추출함
        //cout << !bool((cin.rdstate() & std::istream::failbit) != 0) << endl;
    }

    return 0;
}