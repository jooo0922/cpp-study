#include <iostream>

using namespace std;

int main()
{
    int value = 7;
    int* ptr = &value; // 포인터 변수를 하나 선언하고, 변수 value 의 메모리 주소값을 할당함.

    // 해당 포인터 변수에 저장된 메모리 주소값을 출력
    // 이때, 16진수 메모리 주소값은 보기 불편하니, 보통은 10진수 정수형으로 형변환하여 출력하는데,
    // c++ 에서 uintptr_t() 로 메모리 주소값을 보기좋게 10진수로 변환하는 기능이 있어 사용한 것.
    // 포인터 변수의 메모리 주소값에 각각 -1, +1, +2, .. 등등 해보니
    // 4 bytes 씩 감소 또는 증가하는 걸 볼 수 있음.
    // 왜 4 bytes 씩 이동한걸까? > 포인터 변수 ptr 의 타입인 int 가 4 bytes 이기 때문에,
    // 그거에 맞춰서 메모리 주소값을 +1 할 때마다, 4 bytes 씩 옆칸으로 이동한 것임!
    // 포인터 변수의 타입을 double 로 선언했다면, 8 bytes 단위로 이동하겠군!
    cout << uintptr_t(ptr - 1) << endl; // 20445544 (- 4 bytes)
    cout << uintptr_t(ptr) << endl; // 20445548
    cout << uintptr_t(ptr + 1) << endl; // 20445552 (+ 4 bytes)
    cout << uintptr_t(ptr + 2) << endl; // 20445556 (+ 8 bytes (4 bytes * 2))

    return 0;
}