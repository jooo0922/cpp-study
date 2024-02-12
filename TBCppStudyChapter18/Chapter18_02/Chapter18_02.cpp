#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /* ostream 출력 관련 설정 정리 */

    /* 
        ostream 출력 시 플래그 옵션을 설정하려면,
        std::cout.setf() 또는
        std::cout.unsetf() 를 사용한다!
    */

    /* cout.setf(std::ios::showpos) 로 양수(+) 출력 */
    cout.setf(std::ios::showpos);
    cout << 108 << endl;

    /* cout.unset() 으로 이전에 설정한 플래그 옵션 초기화 */
    cout.unsetf(std::ios::showpos);
    cout << 109 << endl;

    /* std::ios::uppercase 로 대문자 출력 설정 */
    //cout.setf(std::ios::uppercase);

    /* cout.setf(std::ios::hex) 로 16진수 출력 */
    // 10진수 모드를 먼저 초기화해야 됨.
    /*cout.unsetf(std::ios::dec); 
    cout.setf(std::ios::hex);*/
    // 또는 아래와 같이 std::ios::basefield 로 모든 설정을 한꺼번에 초기화한 상태에서 16진수 출력 설정함.
    //cout.setf(std::ios::hex, std::ios::basefield);
    // 또는 아래와 같이 cout.setf() 를 사용하지 않고서, std::hex 만으로도 16진수 출력 설정 가능함.
    /*
        참고로, 아래와 같이 
        cout.setf() 를 거치지 않고,
        
        std::hex, std::uppercase 등을 사용하여
        출력 설정을 직접 건든다는 것은,
        <iomanip> 라이브러리를 사용한다는 의미임!
    */
    cout << std::hex << std::uppercase; 
    cout << 108 << endl;

    // 10진수로 설정을 되돌림
    cout << std::dec;

    /* std::boolalpha 로 boolean 값 출력 설정 (이전 예제에서 몇번 다뤄봤음) */
    cout << std::boolalpha;
    cout << true << " " << false << endl;

    /* std::setprecision() 으로 출력 정밀도 설정 */
    /*
        1. cout << std::defaultfloat;

        출력할 숫자의 맨 왼쪽의 자릿수부터 시작해서
        std::setprecision() 으로 설정한 자릿수까지만 제대로 출력하고 
        나머지는 버림.

        ex> 12.3456 출력 시, 
        std::setprecision(3) 으로 설정했다면,
        12.3 까지만 출력함


        2. cout << std::fixed;

        출력할 숫자의 소수점 이후의 자릿수를
        std::setprecision() 으로 설정한 자릿수까지만 출력하고,
        나머지는 버림.

        ex> 12.3456 출력 시,
        std::setprecision(3) 으로 설정했다면,
        12.346 까지만 출력함.


        3. cout << std::scientific

        출력할 숫자를 scientific notation 으로 표기함.

        ex> 12.3456 출력 시,
        std::setprecision(3) 으로 설정했다면,
        1.23e+01 로 출력함.


        4. cout << std::showpoint

        출력할 숫자의 소수점 이후를 미출력하게 되더라도,
        정수 부분 옆에 항상 . 을 붙여서 출력함.
    */
    //cout << std::defaultfloat;
    //cout << std::fixed;
    //cout << std::scientific;
    cout << std::showpoint;
    cout << std::setprecision(3) << 123.456 << endl;
    cout << std::setprecision(4) << 123.456 << endl;
    cout << std::setprecision(5) << 123.456 << endl;
    cout << std::setprecision(6) << 123.456 << endl;
    cout << std::setprecision(7) << 123.456 << endl;


    /* 자릿수 맞추기 및 shift 설정 */
    /*
        std::setw() 는
        콘솔 출력 시, 특정 길이까지 공백으로 채워서 출력하도록 함.

        std::left, std::right
        은 공백으로 채워진 출력 내에서
        실제 출력값을 왼쪽 정렬 또는 오른쪽 정렬함.

        std::internal 은
        css 의 space between 처럼,
        출력되는 부호와 숫자 사이에 공백이 놓이도록 정렬함.
    */
    cout << -12345 << endl;
    cout.fill('*'); // 공백을 * 로 채워줌.
    cout << std::setw(10) << -12345 << endl;
    cout << std::setw(10) << std::left << -12345 << endl;
    cout << std::setw(10) << std::right << -12345 << endl;
    cout << std::setw(10) << std::internal << -12345 << endl;

    return 0;
}