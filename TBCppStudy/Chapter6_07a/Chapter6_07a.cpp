#include <iostream>
#include <cstddef>

using namespace std;

// 보통 아래 함수처럼,
// 매개변수로 받은 포인터 변수가 제대로 된 메모리 주소값을 갖고 있는지
// 널 체크를 먼저 검사하고 작업을 수행하는 패턴으로 많이 사용됨.
void doSomething(double* ptr)
{
    /*
        doSomething() 안에서는 매개변수에 선언한 포인터 변수의 
        '주소값의 주소값'을 찍어보자

        main() 에서 출력한 포인터의 '주소값의 주소값' 과 '다르다'!!!!!!

        왜냐하면, 기본적으로 c++ 함수에서는 파라미터로 전달된 변수의 값을 복사해서
        함수에 선언한 매개변수에 할당하기 때문에, 
        main() 에 있던 ptr 변수에 담긴 메모리 주소값이
        doSomething() 에 선언된 매개변수에 '복사'가 되어서 할당됨!

        결과적으로, main() 에 있던 ptr 포인터 변수와 
        doSomething() 의 매개변수인 ptr 포인터 변수는
        '서로 다른 메모리 공간'을 할당받은 '서로 다른 변수' 라는 것이다!

        그래서, 이 main() 에 있는 
        포인터 변수의 '주소값의 주소값' 을 가져와서 직접 참조하기 위해
        매개변수를 '이중 포인터'로 선언해서 사용하는 기법이 아주 많이 사용됨!
        자료구조&알고리즘 책에서도 이런 방식으로 구현한 것이 많음!
    */
    cout << "address of pointer variable in doSomething() " << &ptr << endl;

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

    // cstddef 라이브러리에서 가져온 타입으로,
    // nullptr 만 파라미터로 받는 함수일 경우, nullptr 타입 변수를 선언할 때 사용.
    // 근데 실제로 많이 사용할 일은 없다고 함.
    nullptr_t nptr;

    // 이제 포인터 변수에 담긴 주소값이 아닌,
    // 포인터 변수에 할당된 메모리 공간의 주소값,
    // 즉, 포인터 변수에 할당된 주소값이 저장된 메모리 공간의 주소값,
    // 즉, '주소값의 주소값' 을 출력해보자!
    cout << "address of pointer variable in main() " << &ptr << endl;

    return 0;
}