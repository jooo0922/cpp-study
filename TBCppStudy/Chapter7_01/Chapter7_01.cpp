#include <iostream>

using namespace std;

// 전방선언으로 두 int 타입 매개변수 x, y 를 받아 int 타입을 반환하는 함수 foo 선언
int foo(int x, int y);

// 전방선언된 함수 foo 의 몸체(body) 실제 구현
int foo(int x, int y)
{
    return x + y;
} // 이 함수블록이 종료되면 선언된 매개변수 x, y 의 메모리는 자동으로 반납됨!

int main()
{
    return 0;
}