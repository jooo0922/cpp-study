#include <iostream>

using namespace std;

int value = 123; // main 함수 영역 외부에 선언된 전역변수

int main()
{
    cout << value << endl;

    int value = 1; // name hiding 이 발생하여 외부에 선언된 동일한 이름의 전역변수 value 가 무시됨.

    cout << ::value << endl; // global scope operation(::) 를 이용해서, name hiding 된 전역변수에 접근 가능!
    cout << value << endl;

    return 0;
}