#include <iostream>
#include <cstdlib> // exit() 함수를 사용하기 위해 include

int main()
{
    std::cout << "I love you " << std::endl;

    /*
        exit() 은 return 0; 과 유사하게
        함수 실행을 중간에 탈출시키는 역할을 하지만,
        exit() 가 좀 더 긴급하게 지금 당장 끝내라는 뉘앙스가 더 강함.

        주로 디버깅할 때, 
        해당 지점까지의 실행된 사항들만 우선적으로 보고 싶을 때
        exit() 함수를 많이 사용한다고 함.

        그리고, exit() 은 함수의 반환 타입과 무관하게,
        그냥 인자로 0, 1, -1 등의 정수값만 전달해주면 됨.
    */
    exit(0);

    // ....

    /*std::cout << "I love you, too" << std::endl;

    return 0;*/
}
