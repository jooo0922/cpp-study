#include <iostream>

using namespace std;

int main()
{
    int value = 5;

    // 포인터 변수는 아래와 같이 선언 및 초기화할 수 있었지?
    // 근데, 이렇게 포인터 변수에 별첨자 붙여주고 하는 게 귀찮지?
    int* ptr = nullptr;
    ptr = &value;


    // 위와 같이 포인터 변수를 생성하는 게 귀찮기 때문에,
    // 포인터 변수와 유사한 기능을 수행하면서도 좀 더 쓰기 편리한
    // '참조 변수' 를 사용해볼 수 있음!
    /*
        참조 변수

        아래와 같이 & 주소연산자를 사용해서
        참조 변수를 선언할 수 있는데,

        여기서 참조 변수 ref 는 내부적으로
        마치 value 와 같은 변수처럼 작동함.

        마치 value 와 같은 메모리 공간을
        사용하는 변수인 것처럼 작동한다!

        이때, 참조 변수는 별명이기 때문에,
        원래 이름이 있어야 별명을 지을 수 있을 거잖아?
        그러니 당연히 선언과 동시에 원본 변수로 initialization 이 되어야 함!
    */
    int& ref = value;

    cout << ref << endl; // 초기화된 참조 변수 ref 의 값 출력 > 5 (value 의 값이 그대로 출력)
    
    ref = 10; // 참조변수 ref 의 값 변경 > 마치 포인터 변수에서 *ptr = 10; 처럼 de-referencing 으로 값 변경하는 것과 동일하게 작동함!

    cout << value << " " << ref << endl; // 참조 변수 ref 와 원본 변수 value 를 모두 출력 > 10 10 (ref 를 통해 변경된 값 10이 value 로 출력했을 때에도 동일하게 출력!)

    // 위의 예제 코드처럼, 참조변수는 마치 원본 변수의 '별명'처럼 사용될 수 있는 변수!


    // 그렇다면, 원본변수 주소값, 참조변수 주소값, 포인터 변수에 할당된 주소값, 포인터 변수 자체의 주소값을 각각 출력해보자!
    cout << &value << endl; // 00EFFB8C
    cout << &ref << endl; // 00EFFB8C (원본변수랑 주소값이 같네? > 참조변수는 같은 메모리 공간을 가리키며 '별칭'처럼 쓰임!)
    cout << ptr << endl; // 00EFFB8C
    cout << &ptr << endl; // 00EFFB80 (포인터 변수 자체의 주소값만 다르구나!)


    // 참조변수와 const
    const int y = 8;
    //int& ref1 = y; // 원본변수가 const 불변인데 참조변수는 const 가 아니라면, 참조변수에 의해 값 변경이 일어날 수 있어 컴파일러가 에러를 발생시킴!
    const int& ref1 = y; // 원본변수를 const 로 지정했다면, 별명인 참조변수도 const 로 지정해줘야 에러가 안남!


    // 참조변수는 재할당이 가능한가?
    int value1 = 5;
    int value2 = 10;

    int& ref2 = value1;
    cout << ref2 << endl; // 5

    ref2 = value2;

    cout << ref2 << endl; // 10. 가능하군!

    return 0;
}