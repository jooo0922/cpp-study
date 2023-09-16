#include <iostream>

using namespace std;

int main()
{
    int length; // 런타임에 동적으로 할당할 배열의 크기

    cin >> length; // 동적으로 할당할 배열의 크기를 cin 스트림 입력으로 받음

    // 동적 배열을 힙 메모리에 할당하려면, 아래와 같이 new int[length] 로 메모리를 할당하고,
    // 해당 배열의 첫 번째 요소의 메모리 공간의 주소값을 array 포인터 변수에 반환받아서 저장해두겠지?
    //int* array = new int[length];

    // 만약, 메모리를 할당받은 동적 배열의 모든 요소의 값을 0으로 초기화하고 싶다면, 아래와 같이 () 괄호를 붙여주면 됨.
    //int* array = new int[length]();

    // uniform initialization 을 통해 동적으로 할당될 배열의 각 요소에 미리 원하는 초기값을 지정할수도 있음.
    // 문제는, 런타임에 입력받는 동적 배열의 크기가 이 초기값 개수보다 크면 상관이 없는데,
    // 초기값 개수보다 작은 경우, 지정된 메모리보다 더 많은 초기값들을 채워넣으려고 하게 되는 셈이다 보니,
    // 컴파일러가 에러를 발생시킴.
    int* array = new int[length] {11, 22, 33, 44, 55, 66};

    // 메모리를 할당받은 동적 배열의 0번째와 1번째 메모리 공간에 값을 할당 
    array[0] = 1;
    array[1] = 2;

    // 런타임에 cin 스트림으로 입력받은 동적 배열의 크기만큼 반복문 순회
    for (int i = 0; i < length; ++i)
    {
        cout << (uintptr_t) & array[i] << endl; // 동적 배열의 각 요소가 저장된 메모리 공간 주소값 출력(10진수 주소 타입으로 형변환)
        cout << array[i] << endl; // 동적 배열의 각 요소의 값 출력
    }

    // 항상 new 키워드로 메모리를 동적 할당 받았다면,
    // new 키워드와 짝지어지는 메모리 반환 키워드인 delete 도 습관적으로 추가해주는 게 좋음.
    // 물론, 이 코드 상에서는 프로그램이 종료되면 자동으로 메모리가 반환되겠지만,
    // 가급적 습관적으로 delete 를 추가해주는 것이 좋음.
    // 이때, 동적 배열 형태로 메모리를 할당받은 포인터 변수는
    // 메모리를 반환할 때, delete 키워드에 [] 기호를 붙여줘서 사용해야 함!
    delete[] array;

    return 0;
}