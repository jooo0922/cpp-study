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
    return 0;
}