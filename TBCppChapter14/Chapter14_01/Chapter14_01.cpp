#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 예외처리의 기본 문법
    // try, catch, throw
    // try : 어떤 작업을 시도한다
    // throw : 뭔가 이상한 예외적인 일이 발생했을 때, 예외를 '던진다'
    // catch : throw 로 던져진 에러를 '받아서 처리한다'

    // double 타입 변수 x 에 스트림 입력을 받음
    double x;
    cin >> x;

    try
    {
        if (x < 0.0)
        {
            // 입력값이 음수일 경우, 제곱근 (sqrt())를 계산할 수 없어 예외처리를 '던진다'
            // 현재 std::string 타입 문자열로 에러메시지를 '던지고' 있음.
            throw std::string("Negative input");
        }

        // 입력값이 양수일 경우, 제곱근을 계산해서 출력한다
        cout << std::sqrt(x) << endl;
    }
    catch (std::string error_message) // catch 문에서 throw 로 던져진 에러메시지를 '잡는다(가로챈다).'
    {
        // 던져진 예외처리를 '잡아서' 적절한 대응을 수행한다
        // 여기서는 throw 로 던진 에러메시지를 출력함
        cout << error_message << endl;
    }

    return 0;
}