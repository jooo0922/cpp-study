#include <iostream>

using namespace std;

/*
    아래와 같이,
    R-value reference 와
    L-value reference 는

    서로 다른 매개변수로 오버로딩이 가능함.

    즉, 서로 다르게 기능할 수 있는 오버로딩으로
    컴파일러가 인정해준다는 것!
*/

// 함수의 매개변수를 L-value reference 로 오버로딩
void doSomething(int& lref)
{
    /*
        L-value 참조변수는
        이 함수 외부에서도 접근이 가능한,
        즉, 메모리 공간을 갖는 변수이기 때문에,

        이 함수 내에서 L-value 참조변수에 담긴 값을
        'move semantics'(메모리 소유권 이동)을 하면
        
        이 함수 외부에서 이 참조변수에 접근할 때,
        값이 이동되어서 사라져버린 상태가 될테니 문제가 되겠지! 
    */
    cout << "L-value ref" << endl;
}

// 함수의 매개변수를 R-value reference 로 오버로딩
void doSomething(int&& ref)
{
    /*
        R-value 참조변수는 
        어차피 소멸될 R-value 들(리터럴, 표현식 등)을
        담고 있기 때문에,

        이 R-value 참조변수를 이 함수 내에서
        'move semantics'(메모리 소유권 이동)을 해도 아무런 지장이 없음.

        해당 참조변수는 이 함수 외부에서 접근할 일이 아예 없는 R-value 니까!
    */
    cout << "R-value ref" << endl;
}

int getResult()
{
    return 100 * 100;
}

int main()
{
    // 아래에서 int x 는 L-value, 5 같은 리터럴 값이나 표현식을 R-value 라고 했었지?
    int x = 5;
    int y = getResult();

    const int cx = 6;
    const int cy = getResult();

    // L-value reference

    int& lr1 = x; // 변수 x 에 대한 참조변수 -> lr1 과 x 는 같은 주소값을 갖고 있으며, 상호 간 값 수정이 가능함. (Modifiable l-values)
    //int& lr2 = cx; // 참조변수 자신이 const 가 아니라면, const 변수는 할당할 수 없음. (Non-modifiable l-values)
    //int& lr3 = 5; // 참조변수에는 메모리를 갖는 변수만 할당 가능. 리터럴이나 표현식을 할당할 수 없음. 즉, R-value 는 할당 불가.

    // 아래 L-value reference 들은 모두 문법적으로 컴파일이 가능함!
    const int& lr4 = x; // Modifiable l-values
    const int& lr5 = cx; // Non-modifiable l-values
    const int& lr6 = 5; // R-values (어차피 상수 참조변수는 '심볼릭 상수'와 다름이 없으므로, 리터럴을 예외적으로 할당할 수 있음.)
    

    // R-value reference
    /*
    * 참고로, R-value reference 는
    * & 기호를 두 번 붙여서 표현함.
    * 
    * L-value reference 와 다르게,
    * 어떤 메모리를 갖는 변수는 담을 수 없고,
    * 
    * 리터럴이나 표현식처럼
    * 메모리에 저장되어 있지 않아서
    * 어느 곳에서도 접근할 수 없는,
    * 
    * 대입하는 지점을 지나면 사라질 운명의
    * R-value 만 담기 위해 만든 새로운 개념의 변수가
    * R-value reference 라고 보면 됨.
    */
    // int&& rr1 = x; // Modifiable l-values 는 메모리에 저장되어 어딘가에서 접근 가능한 변수이니 R-value reference 에 할당 불가
    // int&& rr2 = cx; // 마찬가지로 Non-modifiable l-values 도 할당 불가
    int&& rr3 = 5; // 메모리에 저장되어 있지 않은 리터럴 값, 즉, R-value 만 할당 가능

    //const int&& rr4 = x; // 마찬가지로 상수 R-value reference 에도 Modifiable l-values 는 할당 불가
    //const int&& rr5 = cx; // 마찬가지로 Non-modifiable l-values 도 할당 불가
    const int&& rr6 = 5; // 메모리에 저장되어 있지 않은 R-value 는 상수인 R-value reference 에도 할당 가능

    // L/R-value reference parameters
    doSomething(x); // L-value 매개변수로 오버로딩된 함수가 실행될 것임.
    doSomething(5); // R-value 매개변수로 오버로딩된 함수가 실행될 것임.
    doSomething(getResult()); // R-value 매개변수로 오버로딩된 함수가 실행될 것임.

    return 0;
}