#include <iostream>

using namespace std;

// return by value (값에 의한 반환)
// 가장 간단하고 안정적
// but, 변수 생성 및 값 복사가 여러 번 발생한다는 단점
int getValue1(int x)
{
    int value = x * 2;
    return value;
}

// return by address (주소값에 의한 반환)
int* getValue2(int x)
{
    int value = x * 2;
    return &value;
}

// 주소값에 의한 반환이 사용되는 예시
int* allocateMemory(int size)
{
    // 배열을 힙 메모리에 할당한 뒤,
    // new 키워드는 할당된 배열의 첫 번째 메모리 공간 주소값을 반환함 
    return new int[size];
}

int main()
{
    int value1 = getValue1(3); // 반환된 값이 복사되어 저장

    // 함수가 주소값을 반환할 때, 반환값을 부적절하게 다루는 케이스들 (권장 x)
    //int* value2 = getValue2(3); // 함수 내의 로컬 변수 value 는 함수가 종료되면 메모리가 자동 반납되는데, 반납된 변수의 주소값을 저장해두는 것은 위험하다! 
    //int value2 = *getValue2(3); // 마찬가지로 함수 내 로컬 변수의 주소값을 반환받아 de-referencing 하면, 자동 반납된 로컬 변수를 de-referencing 하지 못하는 경우 발생!


    // 힙 메모리에 할당된 변수는 함수가 종료된다고 해서 자동으로 반납되는 게 아니기 때문에, (delete[] 로 직접 반납해야 함!)
    // 자동으로 반납되지 않는 배열 힙 메모리 공간의 주소값을 반환받아 저장해두는 경우에 적절하게 사용될 수 있음!
    int* array = allocateMemory(1024);

    // 단, 위와 같이 배열의 힙 메모리 주소값을 반납받는 기법도 안전한 코딩은 못되는 것이,
    // new 키워드랑 delete 키워드가 짝짝이로 같이 다녀야 가독성 좋고 안전한 코딩이 되는데,
    // new 키워드는 함수 내에만 존재하고 delete 키워드가 함수 바깥에 존재하니 메모리 할당-반납의 흐름을 확인하기 어려울 것임!
    delete[] array;

    return 0;
}