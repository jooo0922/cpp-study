#include <iostream>

using namespace std;

int main()
{
    const int x = 5;

    // 참조 변수 선언 및 초기화
    // 참조 변수를 const 로 선언 > 이제 이 참조변수를 de-referencing 해서 원본 변수의 값을 바꿀 수 없음.
    const int& ref_x = x; 

    // 또 다른 const 참조변수를 선언하여 첫 번째 const 참조변수를 할당하는 것도 가능!
    // 어쨋든 이 const 참조변수를 de-referencing 해서 원본 변수 값을 바꾸지 못한다는 것만 알면 됨!
    const int& ref_2 = ref_x;

    return 0;
}