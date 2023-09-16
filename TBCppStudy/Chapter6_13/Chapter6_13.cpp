#include <iostream>

using namespace std;

int main()
{
    /*
        const 로 지정한 value 변수의 주소값을 갖는
        포인터 변수 ptr 을 const 로 지정할 경우,
        de-referencing 을 통해서 해당 포인터가 가리키는 메모리의 값을 변경하는 것이 불가능함.

        이것이 의미하는 바가 무엇이냐면,
        포인터 변수를 const 로 지정할 경우,
        해당 포인터 변수가 갖는 메모리 주소를 읽고,
        참조하거나 접근하는 것은 모두 가능함.

        그러나, ptr 변수가 가리키는 메모리 공간에 저장된 값을
        역참조를 통해서 직접 수정하는 것이 불가능하다는 뜻!

        말 그대로 const 가 되어버린 것임!
    */
    //const int value = 5;
    //const int* ptr = &value;
    ////*ptr = 6; // de-referencing 을 통한 역참조 값 수정 불가! why? value 가 const 이기 때문에, value = 6 이 불가능해서!

    //cout << *ptr << endl; // 5. 물론, de-referencing 된 값을 '읽는 것' 자체는 아무 문제없음!


    // 이번에는, 아래와 같이 value 자체는 const 가 아니지만,
    // value 변수가 저장된 메모리 공간의 주소값이 담긴 포인터 변수만 const 로 지정한다면?
    int value = 5;
    const int* ptr = &value;
    //*ptr = 6; // 이럴 경우, 포인터 변수를 de-referencing 해서 값을 바꾸는 건 여전히 불가능! why? 포인터 변수가 const 라서!
    value = 6; // 다만, value 자체는 const 가 아니기 때문에, value 변수를 통해 값을 바꾸는 것은 가능

    // 위와 같은 상황일 경우, 포인터 변수 역참조로 값을 읽어보면,
    // value = 6; 을 통해 직접 변경한 값이 출력되는 것을 확인할 수 있음!
    // 이를 통해 알 수 있는 것은, 포인터 변수만 const 일 경우,
    // 포인터 변수 역참조를 통해 값을 변경하는 것은 불가능하지만,
    // 실제 변수를 통해 변경하는 것은 아무런 상관이 없음을 알 수 있음!
    cout << *ptr << endl; // 6.


    // 이번에는, const 로 지정된 포인터 변수에 담긴 주소값을 바꾸는 게 가능한 지 테스트해보자
    int value1 = 5;
    const int* ptr = &value1;
    //*ptr = 7; // de-referencing 을 통한 값 변경은 여전히 불가능함.
    
    /*
        결론부터 말하면,
        const 로 지정된 포인터 변수에 담긴 주소값을 바꾸는 것은 가능하다!

        이게 뭔 개소리인가 싶을수도 있는데,
        포인터 변수를 const 로 지정한다는 게 어떤 의미인지 정확히 알아야 함.

        포인터 변수가 const 로 지정된다는 건,
        '이 <포인터 변수에 할당된 메모리 주소값을 de-referencing 하여 실제 값을 변경하는 것>을 막아버리겠다' 는 뜻이지,
        '<포인터 변수에 할당된 메모리 주소값 자체>를 불변으로 만들겠다' 는 것이 아님!!

        그러니, 포인터 변수에 담기는 주소값은 얼마든지 수정할 수 없는 것!
    */
    int value2 = 6;
    ptr = &value2;

    return 0;
}
