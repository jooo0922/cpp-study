#include <iostream>

using namespace std;

 //void printArray(int *array) // 아래 함수는 이렇게 선언하는 것과 동일함.
void printArray(int array[])
{
    // 매개변수를 마치 배열처럼 array[] 이렇게 선언해놔도,
    // 내부적으로는 이것을 포인터 배열로 처리하고 있음.
    // 그래서, main() 함수에서처럼 array 배열에 저장된 모든 요소의 포인터 크기를 합친 20 bytes 가 나오는 게 아니라,
    // 매개변수가 하나의 포인터 변수로 선언된 것이기 때문에,
    // 모든 포인터 변수에 저장된 주소값의 동일한 크기인 4 bytes 가 출력됨
    cout << sizeof(array) << endl; // 4 bytes
    cout << *array << endl; // 9

    *array = 100; // 함수의 마지막 부분에서 배열의 첫 번째 요소에 대한 de-referencing 의 값을 100으로 변경한다면?
}

int main()
{
    // 사이즈가 5개인 정적 배열 선언 및 초기화
    int array[5] = { 9, 7, 5, 3, 1 };

    cout << array[0] << " " << array[1] << endl; // 정적 배열의 각 요소에 접근하여 출력 > 배열의 각 요소 출력

    // 배열 변수의 메모리 주소와 배열의 첫 번째 요소의 메모리 주소가 같네?
    /*
        사실, array (배열 변수)는
        실제로는 배열이 아니라 '포인터' 임!

        포인터 변수라면 주소값을 저장하고 있겠지?
        정확히 어떤 주소값이냐 하면, 
        위 5개의 요소들을 연이어 담고 있는 메모리 공간들에서,
        첫 번째 요소를 담는 메모리 공간의 주소값을 저장하고 있음!
    */
    cout << array << endl; // 배열 변수 자체를 출력 > 메모리 주소값 출력 > 아, 배열이 저장된 메모리의 주소값이 출력되었구나!
    cout << &(array[0]) << endl; // 배열의 첫 번째 요소의 메모리 주소값 출력

    // 그러면, 배열 변수가 '포인터 변수'라고 했으니까,
    // 거기에 담긴 주소값을 de-referencing 도 할 수 있겠네? 당연히 가능!
    cout << *array << endl; // 배열 변수는 배열의 첫 번째 요소의 주소값이 담겨있는 포인터 변수이므로, de-referencing 하면 당연히 배열의 첫번째 요소인 9가 출력됨.


    // 문자열 배열도 동일하게 적용되는지 확인해보자
    char name[] = "jackjack";

    // 마찬가지로, 문자열 배열 변수 name (= 'char 타입 포인터 변수' 라고 봐도 됨.) 에는 
    // 문자열 배열의 첫 번째 요소가 저장된 메모리 공간의 주소값을 담고 있으므로, 
    // de-referencing 하면 첫 번째 문자 j 가 출력됨.
    cout << *name << endl;

    int* ptr = array; // 이번에는 아예 포인터 변수를 선언한 뒤, 거기에 배열 변수 array 에 저장된 주소값을 할당해보자.
    cout << ptr << endl; // 역시 array 에 저장된 메모리 주소와 동일한 주소값이 출력됨.
    cout << *ptr << endl; // array 에 저장된 메모리 주소를 de-referencing 한 것과 마찬가지이므로, 9가 출력됨.


    /*
        그렇다면 배열과 포인터 변수가 완벽히 동일한가?

        그렇지는 않다.
        배열은 사용자의 편의를 위해
        몇 가지 추가 기능을 더 제공하고 있다.
    */
    // sizeof() 로 배열의 크기를 측정하면, 예외적으로 배열은 포인터 변수임에도 불구하고,
    // array 에 담긴 전체 요소의 메모리 주소값의 사이즈가 합쳐져서 반환됨.
    cout << sizeof(array) << endl; // 4 bytes * 5 = 20 bytes
    cout << sizeof(ptr) << endl; // 4 bytes (기본적으로 모든 타입의 포인터 변수에 저장된 메모리 주소값은 x86 아키텍쳐 기준 4 bytes 로 동일하다고 했었지?)

    //printArray(array);

    // printArray() 함수의 마지막 부분에서 de-referencing 된 배열 첫 번째 요소의 값을 100으로 변경했었지?
    // 이 값이 어떻게 바뀌었는지 직접 확인해보자
    // 외부에서 선언된 배열 변수의 de-referencing 된 값을 함수 내부에서 변경할 수 있음!
    // 이런 식으로, 배열(포인터 변수)를 de-referencing 된 값을 함수 내부에서 변경할 때 포인터 변수를 사용하기도 함!
    //cout << array[0] << " " << *array << endl; // 100 100

    // 배열의 첫 번째 메모리 주소값에 +1 을 하면 어떻게 될까?
    // 해당 메모리 공간 '옆'에 있는 메모리 공간의 주소를 얻을 수 있음.
    // 이 원리를 배열에서 응용한다면, 배열의 첫 번째 요소의 메모리 주소값에 +1 해주면
    // 배열의 두 번째 요소가 저장된 메모리의 주소값을 얻을 수 있겠지!
    // 이렇게 포인터 변수의 메모리 주소값에 대해서 어떠한 연산을 해주는 것을 '포인터 연산' 이라고 함.
    cout << *ptr << " " << *(ptr + 1) << endl; // 9 7 > 배열의 첫 번째 요소와 두 번째 요소의 주소값을 de-referencing 한 것을 출력한 셈!

    return 0;
}