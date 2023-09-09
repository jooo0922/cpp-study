#include <iostream>

using namespace std;

// 보통 아래 함수처럼,
// 매개변수로 받은 포인터 변수가 제대로 된 메모리 주소값을 갖고 있는지
// 널 체크를 먼저 검사하고 작업을 수행하는 패턴으로 많이 사용됨.
void doSomething(double* ptr)
{
    if (ptr != nullptr)
    {
        // do something useful
        // nullptr 이 아닌 경우, 포인터 변수에는
        // 어떤 유의미한 메모리 주소가 저장되어 있다는 뜻이므로,
        // ptr 로 어떤 작업을 해도 됨.
        cout << *ptr << endl; // 포인터 변수를 de-referencing
    }
    else
    {
        // do nothing with ptr
        // ptr 에 nullptr 이 들어갔다면,
        // 이 포인터 변수에는 초기화를 위해 아무 의미없는
        // null pointer 로 초기화된 것이므로, 
        // 이 ptr 변수를 가지고 아무런 작업도 할 필요가 없음.
        cout << "Null ptr, do nothing" << endl;
    }
}

int main()
{
    // null pointer (널 포인터)
    /*
        Chapter6_07 강의 마지막 부분에서
        메모리 주소값이 초기화되지 않은 포인터 변수를
        de-referencing 하면, 

        초기화되지 않은 변수를 de-referencing 하려고 한다고
        빌드 에러가 발생했었지?

        이러한 현상을 방지하기 위해,
        주소값을 초기화하지 않은 포인터 변수에
        넣어주는 값을 null pointer 라고 함.
    */
    //double *ptr = NULL; // c-style (또는 0을 넣어주기도 함.)
    double *ptr = nullptr; // modern c++ > 최신 c++ 에서는 nullptr 을 사용함.
    //double *ptr{ nullptr }; // 일반적인 초기화해서 쓰이는 uniform initialization 도 사용 가능.

    doSomething(ptr); // nullptr 입력 > 아무런 작업도 안함.
    doSomething(nullptr); // nullptr 입력 > 아무런 작업도 안함.

    double d = 123.4;

    doSomething(&d); // double 타입 변수 d 의 주소값 입력 > de-referencing 출력

    ptr = &d;

    doSomething(ptr); // 변수 d의 주소값이 할당된 ptr 포인터 변수 입력 > de-referencing 출력

    return 0;
}