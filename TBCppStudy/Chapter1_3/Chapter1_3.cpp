#include <iostream>

int main()
{
    // x 는 메모리 상의 준비된 어떤 공간의 이름
    // 그 메모리 공간의 크기는 123 이라는 정수형(int) 하나를 담을 수 있는 크기
    //int x = 123;
    int x;
    x = 123; // = 은 Assignment Operator (할당 연산자) > '같다' 는 의미가 아님. x 라는 변수(이름이 가리키고 있는 메모리 공간)에 123을 대입해준다!

    std::cout << x << std::endl;

    return 0;
}
