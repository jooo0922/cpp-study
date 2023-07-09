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
//#define MY_NUMBER "Hello, World" // 매크로에는 문자열도 사용 가능

// 매크로에는 삼항연산자도 사용 가능
// 1 + 3, a > b 같은 표현식이 들어올 수 있을 경우, 
// 매크로 정의 시 괄호로 표현식 부분을 괄호로 한 번 감싸줘야 함. 
//#define MAX(a, b) (((a)>(b)) ? (a) : (b))

#define LIKE_APPLE // 매크로를 "정의만" 해놓음.

void doSomething()
{
    // #ifdef, #ifndef 도 전처리기. 즉, 런타임이 아니라, 이미 빌드 시점에 아래 조건을 따져서 결정해버림!
    // 주로 빌드 시작 전, 윈도우인지, 리눅스인지 이런 거 알고 시작할 때!
    // 또는 그래픽카드 사양에 따라 OpenGL 을 쓸 지 Metal 을 쓸 지 등...
    // 주로 멀티 플랫폼 상에서 개발할 때 많이 사용한다고 함! > 이런 걸 Conditional Compilation (조건에 따른 컴파일 방식)
    // 또, #define 은 "교체"하는 매크로이지만, 다른 전처리기 (#ifdef) 안에서는 교체되지 않음.
    #ifdef LIKE_APPLE // LIKE_APPLE 매크로가 정의가 되어있다면~
        cout << "Apple" << endl;
    #endif // LIKE_APPLE // if 문 종료

    #ifndef LIKE_APPLE // LIKE_APPLE 매크로가 정의가 안되어있다면~ > #else 로 사용해서 축약도 가능
        cout << "Orange" << endl;
    #endif // !LIKE_APPLE // if not 문 종료
}

int main()
{
    //cout << MAX(1 + 3, 2) << endl;
    //cout << std::max(1 + 3, 2) << endl; // 요즘에는 algorithm 라이브러리에 max 함수가 구현되어 있어서 매크로로 직접 만들 필요도 없음

    doSomething();

    return 0;
}
