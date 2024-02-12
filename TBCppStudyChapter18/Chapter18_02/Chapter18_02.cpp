#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /* ostream 출력 관련 설정 정리 */


    /* 출력 시 플래그 옵션 설정 */

    /* cout.setf() 로 양수(+) 출력 */
    cout.setf(std::ios::showpos);
    cout << 108 << endl;

    /* cout.unset() 으로 이전에 설정한 플래그 옵션 초기화 */
    cout.unsetf(std::ios::showpos);
    cout << 109 << endl;

    return 0;
}