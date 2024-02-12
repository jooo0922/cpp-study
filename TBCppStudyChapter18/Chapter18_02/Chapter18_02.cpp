#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /* ostream 출력 관련 설정 정리 */


    /* 출력 시 플래그 옵션 설정 */

    /* cout.setf(std::ios::showpos) 로 양수(+) 출력 */
    cout.setf(std::ios::showpos);
    cout << 108 << endl;

    /* cout.unset() 으로 이전에 설정한 플래그 옵션 초기화 */
    cout.unsetf(std::ios::showpos);
    cout << 109 << endl;

    /* std::ios::uppercase 로 대문자 출력 설정 */
    cout.setf(std::ios::uppercase);

    /* cout.setf(std::ios::hex) 로 16진수 출력 */
    // 10진수 모드를 먼저 초기화해야 됨.
    /*cout.unsetf(std::ios::dec); 
    cout.setf(std::ios::hex);*/
    // 또는 아래와 같이 std::ios::basefield 로 모든 설정을 한꺼번에 초기화한 상태에서 16진수 출력 설정함.
    //cout.setf(std::ios::hex, std::ios::basefield);
    // 또는 아래와 같이 cout.setf() 를 사용하지 않고서, std::hex 만으로도 16진수 출력 설정 가능함. 
    cout << std::hex; 
    cout << 108 << endl;


    return 0;
}