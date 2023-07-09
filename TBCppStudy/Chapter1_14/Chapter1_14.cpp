#include <iostream>
#include <algorithm>

using namespace std;

/*
    전처리기에 대하여...
*/

// #define > "매크로" 라고도 함.
// 매크로는 보통 대문자로 선언하며,
// 매크로의 역할은, 코드에서 MY_NUMBER 를 만나면, 333로 교체하라는 의미임.
// 매크로는 코드 안에 있는 것이므로, 코드가 변경되면 빌드를 항상 다시해야 함.
// 하지만, 매크로 자체가 하드코딩을 의미하기 때문에 요즘에는 많이 안쓴다고 함.
//#define MY_NUMBER 333
#define MY_NUMBER "Hello, World" // 매크로에는 문자열도 사용 가능

// 매크로에는 삼항연산자도 사용 가능
// 1 + 3, a > b 같은 표현식이 들어올 수 있을 경우, 
// 매크로 정의 시 괄호로 표현식 부분을 괄호로 한 번 감싸줘야 함. 
#define MAX(a, b) (((a)>(b)) ? (a) : (b)) 

int main()
{
    cout << MAX(1 + 3, 2) << endl;
    //cout << std::max(1 + 3, 2) << endl; // 요즘에는 algorithm 라이브러리에 max 함수가 구현되어 있어서 매크로로 직접 만들 필요도 없음

    return 0;
}
