#include <iostream> // 얘는 좀 특별한 템플릿이라 꺽쇠로 가져옴
#include "MyHeaders/add.h" // 현재 빌드 위치에서 하위 폴더로 옮겼을 경우, "폴더이름/헤더파일명" 이런 식으로 작성해줘야 함.
// 또, 우측의 Solution Exploer > Chapter1_11 > Header Files 에서 해당하는 헤더파일을 Remove 하고, 
// 파일 탐색기로부터 옮긴 헤더파일 위치를 찾은 다음, Header Files 에 드래그앤드랍 해줘야 함.

using namespace std;

// 전방선언으로 함수를 복붙하는 것도 번거로울 수 있다! 
// -> 헤더파일에 선언해놓으면, 다른 파일에서도 중복해서 전방선언을 할 필요가 없다!
//int add(int a, int b);

int main()
{
    cout << add(1, 2) << endl;

    return 0;
}
