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

            // 아래와 같이 c-style 문자열로 throw 한다고 해서,
            // catch 문에서 std::string 타입으로 자동 형변환해주지 않음! -> 엄격한 타입 검사!
            //throw "Negative input";
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

    /*
        throw...catch 문에서 주의할 점


        throw 문에서 던진 값의 타입은
        catch 문에서 절대 '자동으로 casting 해주지 않음!'

        즉, 두 문법은 엄격한 타입 체크를 하기 때문에,
        throw 에서 그냥 char* 타입의 c-style 문자열로 던지더라도,
        catch 문에서 std::string 타입으로 자동 형변환 하지 않고,
        런타임 에러를 발생시키게 됨!
    */

    return 0;
}