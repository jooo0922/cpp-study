#include <iostream>
#include <cmath> // sin(), cos() 함수 사용을 위해 포함

using namespace std;

/*
    참조에 의한 전달

    함수 매개변수를 참조변수로 선언하면,
    함수 호출부에서 인자로 전달한 변수 자체의 reference 가
    매개변수로 넘어오게 되므로,

    해당 매개변수의 값을 함수 내부에서 변경할 경우,
    외부에서 전달된 변수의 값을 수정할 수 있게 됨! 
*/
void addOne(int& y)
{
    y = y + 1;
}

int main()
{
    int x = 5;
 
    // 방금 선언된 변수 x 의 값과 주소값 출력
    cout << x << " " << &x << endl;

    // 참조변수로 선언된 매개변수 자리에 변수 x 를 argument(인자)로 전달
    addOne(x);

    // addOne() 함수 내부 로직에 의해 변경된 변수 x 의 값 확인
    cout << x << " " << &x << endl;

    return 0;
}