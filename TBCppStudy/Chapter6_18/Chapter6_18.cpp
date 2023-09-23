#include <iostream>

using namespace std;

// void pointer (genetic pointer 라고도 함. '포괄적인' 이라는 의미)

int main()
{
    int i = 5;
    float f = 3.0f;
    char c = 'a';

    void* ptr = nullptr; // void pointer 를 일단 nullptr 로 초기화

    // void pointer 에 정수형, 실수형, char 타입 주소값을 넣어도 전부 문제 없음. 
    // 문제는, void pointer 로는 그 주소값이 가리키는 메모리에 실제로 담긴 값이 정수형인지 실수형인지 알 수가 없음!
    ptr = &i;
    ptr = &f;
    //ptr = &c;

    // 다행히, 해당 포인터 변수에 들어간 주소값은 정확히 할당되었음을 확인할 수 있음.
    cout << &f << " " << ptr << endl;

    int* ptr_i = &i;

    //cout << ptr_i << endl;
    //cout << ptr_i + 1 << endl; // 이렇게 int 형 포인터 변수는 포인터 연산을 활용해서 메모리를 몇 칸 이동할 지 연산하는 게 가능하지

    // 반면, void 포인터 변수는 포인터 연산 사용이 불가함!
    // 왜냐? 정수형 포인터는 +1 하면 4 bytes 만 이동하면 되는데, 
    // void 포인터는 메모리 공간을 몇 바이트를 이동해야 할 지 알 수 없기 때문!
    //cout << ptr + 1 << endl;


    // 그러나, void 포인터는 de-referencing 도 안됨!
    // 즉, 어떤 주소에 어떤 값들이 쭉 들어있는 건 알겠는데, 그게 정수를 표현하려고 넣어둔 값들인지,
    // 실수를 표현하려고 넣어둔 값들인지 알 수가 없는 것이지!
    //cout << *ptr << endl;

    // 대신, void pointer 를 float 타입 포인터 변수로 형변환한 다음, 
    // de-referencing 해서 참조하는 건 가능함!
    cout << *static_cast<float*>(ptr) << endl;

    return 0;
}