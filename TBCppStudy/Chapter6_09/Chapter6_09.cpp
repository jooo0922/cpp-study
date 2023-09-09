#include <iostream>

using namespace std;

int main()
{
    int value = 7;
    int* ptr = &value; // 포인터 변수를 하나 선언하고, 변수 value 의 메모리 주소값을 할당함.

    // 해당 포인터 변수에 저장된 메모리 주소값을 출력
    // 이때, 16진수 메모리 주소값은 보기 불편하니, 보통은 10진수 int 타입으로 형변환하여 출력하는데,
    // c++ 에서 uintptr_t 타입으로 메모리 주소값을 보기좋게 10진수로 형변환하여 사용한 것.
    // 포인터 변수의 메모리 주소값에 각각 -1, +1, +2, .. 등등 해보니
    // 4 bytes 씩 감소 또는 증가하는 걸 볼 수 있음.
    // 왜 4 bytes 씩 이동한걸까? > 포인터 변수 ptr 의 타입인 int 가 4 bytes 이기 때문에,
    // 그거에 맞춰서 메모리 주소값을 +1 할 때마다, 4 bytes 씩 옆칸으로 이동한 것임!
    // 포인터 변수의 타입을 double 로 선언했다면, 8 bytes 단위로 이동하겠군!
    cout << uintptr_t(ptr - 1) << endl; // 20445544 (- 4 bytes)
    cout << uintptr_t(ptr) << endl; // 20445548
    cout << uintptr_t(ptr + 1) << endl; // 20445552 (+ 4 bytes)
    cout << uintptr_t(ptr + 2) << endl; // 20445556 (+ 8 bytes (4 bytes * 2))


    // 이번에는 포인터 연산을 배열에서 적용해보자
    // 배열은 결국 포인터 변수와 동일하다고 했었지?
    int array[] = { 9, 7, 5, 3, 1 };

    int* arrPtr = array; // 배열의 메모리 주소를 포인터 변수에 할당

    // 배열 요소와 그 배열이 저장된 메모리 공간의 주소값을 확인해보자
    // 출력해보면, 위에서 테스트해봤던 것과 마찬가지로,
    // 각 요소의 메모리 주소값이 4 bytes 씩 증가하는 걸 확인할 수 있음. 
    // 이를 통해, int 타입 배열은 각 요소가 4 bytes 간격으로 메모리에 나란히 저장되어 있는 구조임을 알 수 있음.
    for (int i = 0; i < 5; ++i)
    {
        //cout << array[i] << " " << (uintptr_t) & array[i] << endl;

        // 그렇다면, 배열의 인덱스 i 를 이용해서 4 bytes 간격으로 메모리 주소값을 확인할 수 있다면,
        // 같은 작업을 위에서 연습해 본 포인터 연산으로도 구현할 수 있겠지!
        // *(arrPtr + i) 는 포인터 연산이 적용된 메모리 주소값 (ptr + i) 에 대한 de-referencing,
        // 즉, 해당 메모리 주소에 저장된 값을 참조하여 출력한 것.
        cout << *(arrPtr + i) << " " << (uintptr_t)(arrPtr + i) << endl;
    }


    // 이번에는 문자열 배열에 포인터 연산을 적용해보자
    char name[] = "Jack Jack";

    const int n_name = sizeof(name) / sizeof(char); // 문자열 개수 구하는 방법 > 전체 문자열 메모리 사이즈 / char 타입 1개의 메모리 사이즈 (이때 나오는 개수는 마지막에 숨어있는 공백문자 '\0'을 포함한 값)

    for (int i = 0; i < n_name; ++i)
    {
        // name 은 문자열 배열이기는 하지만, 동시에 포인터 변수라고도 했지?
        // 그래서 위에 int *arrPtr 처럼 별도의 포인터 변수를 만들어서 
        // 배열의 메모리 주소값을 할당하지 않고서도,
        // 포인터 연산 및 de-referencing 을 바로 적용해서
        // 각 포인터 연산의 결과가 되는 메모리 주소값에 담긴 값을 역참조하는 것도 가능함!
        cout << *(name + i);
    }

    cout << endl;

    // 연습문제 
    // while 문에서 포인터 연산으로 문자열 배열 출력하기
    int ix = 0;

    while (true)
    {
        if (*(name + ix) == '\0') break; // de-referencing 한 참조값이 공백문자일 경우 반복문 탈출

        cout << *(name + ix);
        ix++;
    }

    return 0;
}