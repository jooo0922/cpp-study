#include <iostream>

using namespace std;

// 전방선언으로 두 int 타입 매개변수 x, y 를 받아 int 타입을 반환하는 함수 foo 선언
int foo(int x, int y);

// 전방선언된 함수 foo 의 몸체(body) 실제 구현
int foo(int x, int y)
{
    return x + y;
} // 이 함수블록이 종료되면 선언된 매개변수 x, y 의 메모리는 자동으로 반납됨! -> 함수 블록 내에 선언된 지역변수와 동일한 취급

int main()
{
    int x = 1, y = 2;

    foo(6, 7); // 6, 7 : argument(인자) 라고 함. > 함수를 호출하는 부분에서 직접 전달하는 '값'. 또는 actual parameters(실 매개변수)라고도 함.

    foo(x, y + 1); // 위에 선언된 변수 x, y에 들어있는 '값'만 foo 함수의 매개변수로 복사되어 전달됨

    return 0;
}