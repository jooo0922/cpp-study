#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    int x, y;
    cin >> x >> y;

    int op;
    cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
    cin >> op;

    // 정적 바인딩 (static binding 또는 early binding)
    /*int result;

    switch (op)
    {
    case 0: result = add(x, y); break;
    case 1: result = subtract(x, y); break;
    case 2: result = multiply(x, y); break;
    }

    cout << result << endl;*/

    // 동적 바인딩 (dynamic binding 또는 late binding)
    // 메모리에 저장된 함수를 가리킬 '함수 포인터 변수' func_ptr 선언 및 초기화
    // 함수 포인터 관련 https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter7/Chapter7_09/Chapter7_09.cpp 참고
    int(*func_ptr)(int, int) = nullptr;

    // 입력 스트림으로 받은 op 값에 따라, 함수 포인터에 할당될 주소값이 '동적으로' 결정됨
    switch (op)
    {
    case 0: func_ptr = add; break;
    case 1: func_ptr = subtract; break;
    case 2: func_ptr = multiply; break;
    }

    // 결과적으로, 이 line 에서 실행될 함수 func_ptr() 이 런타임에 '동적으로' 결정됨
    // -> 이러한 기법을 '동적 바인딩' 이라고 함!
    cout << func_ptr(x, y) << endl;

    return 0;
}