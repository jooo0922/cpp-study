#include <iostream>

int main()
{
    // x 는 메모리 상의 준비된 어떤 공간의 이름
    // 그 메모리 공간의 크기는 123 이라는 정수형(int) 하나를 담을 수 있는 크기
    //int x = 123;
    int x;
    x = 123; // = 은 Assignment Operator (할당 연산자) > '같다' 는 의미가 아님. x 라는 변수(이름이 가리키고 있는 메모리 공간)에 123을 대입해준다!

    /*
        위 선언문에서 왼쪽에 있는 x 는 Left Value, > 주소를 갖고 있는 것
        오른쪽에 있는 123은 Right Value > 주소를 갖고 있지 않은 것! 즉, "값"

        x = x + 2; 

        위 식에서의 x + 2 의 x 또한 Right Value,
        즉, 주소를 갖고 있지 않음!

        그래서 x 역시 '값'으로 바꿔치기 됨!
    */

    std::cout << x << std::endl;
    std::cout << &x << std::endl; // x 는 결국 '어떤 메모리 공간의 이름' 임을 알 수 있음. > & ampersand 를 붙여서 콘솔 출력 시, 16진수로 표현된 실제 메모리 주소가 출력됨!

    return 0;
}
