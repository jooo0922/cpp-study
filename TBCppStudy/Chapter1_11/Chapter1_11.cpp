#include <iostream>
#include "add.h"

using namespace std;

// 전방선언으로 함수를 복붙하는 것도 번거로울 수 있다! 
// -> 헤더파일에 선언해놓으면, 다른 파일에서도 중복해서 전방선언을 할 필요가 없다!
//int add(int a, int b);

int main()
{
    cout << add(1, 2) << endl;

    return 0;
}
