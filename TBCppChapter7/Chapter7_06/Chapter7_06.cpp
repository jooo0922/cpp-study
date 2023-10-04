#include <iostream>

using namespace std;

/*
    인라인 함수

    인라인 함수는 main 함수에서 해당 함수의 호출부를 발견하면
    해당 함수의 선언부로 가고, 매개변수를 새롭게 선언해서 메모리를 할당하고,
    그 선언부에서 함수의 구현부를 찾아서 구현부의 계산을 모두 수행하고, 
    그 수행한 결과를 반환하는 일련의 과정들을
    생략할 수 있도록 해주는 키워드!

    왜냐하면, 아래 min 함수와 같이
    내부 계산이 너무나도 간단한 함수의 경우,
    저런 복잡한 함수 호출 및 수행 과정에 드는 비용이 더 많아서

    아예 컴파일 단계에서 함수 호출부에다가
    min 함수의 코드를 그대로 embed 해버림으로써,
    min 함수는 함수가 아닌 것처럼 작동하게 만들어버림!

    이렇게 하면 함수를 찾고, 호출하고, 실행하는 과정을 생략할 수 있으니까!

    레이트레이싱에서 vec3 클래스 구현할 때,
    연산자 오버로딩에서 inline 함수를 마구마구 사용해줬었지?

    https://github.com/jooo0922/raytracing-study/blob/main/InOneWeekend/InOneWeekend/vec3.h

    그러나, 최근에는 컴파일러가 inline 함수로 컴파일 해달라는 제안(키워드)이 없더라도,
    코드 맥락을 보고 인라인으로 하는 게 낫겠다 싶으면 자기가 알아서 판단해서 인라인으로 컴파일 해줌.

    그래서, 최근에는 inline 키워드를 붙인다고 해서
    무조건 속도가 빨라지거나 하지도 않음.

    -> inline 무용론...
*/
inline int min(int x, int y)
{
    return x > y ? y : x;
}

int main()
{
    cout << min(5, 6) << endl;
    cout << min(3, 2) << endl;

    // min() 함수를 inline 함수로 만들 시, 
    // 컴파일 단계에서 아래 코드가 main 함수에 삽입되는 것과 동일함!
    cout << (5 > 6 ? 6 : 5) << endl;
    cout << (3 > 2 ? 2 : 3) << endl;


    return 0;
}