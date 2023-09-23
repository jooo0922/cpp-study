#include <iostream>

using namespace std;

int main()
{
    int* ptr = nullptr;

    // 포인터에 대한 포인터 > 이중 포인터를 만들 수도 있음!
    // 자료구조 알고리즘 구현 시 많이 사용해봤었지?
    int** ptrptr = nullptr; // 포인터에 대한 포인터인데, 원래 변수의 타입은 int 다! 라고 이해하면 됨.

    int value = 5;
    ptr = &value;

    ptrptr = &ptr; // 즉, <특정 포인터 변수(ptr)에 저장된 메모리 주소값>이 저장된 메모리 주소값이 ptrptr 에 할당됨! 

    // 포인터 변수에 담긴 주소값, 포인터 변수 de-referencing, <포인터 변수에 담긴 주소값>이 저장된 메모리의 주소값 각각 출력
    cout << ptr << " " << *ptr << " " << &ptr << endl;

    // 이중 포인터 변수에 담긴 주소값, 이중 포인터 변수 de-referencing, <이중 포인터 변수에 담긴 주소값>이 저장된 메모리의 주소값 각각 출력
    cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;

    // 이중 포인터 변수를 이중으로 de-referencing 한 값 출력
    /*
        좀 풀어서 설명하자면, 
        **ptrptr 은 *(*ptrptr) 과 같고,
        이는 *(ptr) 과 같음.

        *ptr 은 value 와 같으므로,
        결과적으로 이중 de-referencing 의 값은
        value 에 할당된 값인 5가 출력될 것임!
    */
    cout << **ptrptr << endl;

    // 실제로 3중, 4중 포인터까지도 사용할 수는 있지만, 거의 사용할 일은 없고,
    // 이중 포인터의 경우 2차원 행렬 구현 시 주로 사용됨.

    return 0;
}