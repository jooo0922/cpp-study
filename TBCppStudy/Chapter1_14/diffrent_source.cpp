#include <iostream>

using namespace std;

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