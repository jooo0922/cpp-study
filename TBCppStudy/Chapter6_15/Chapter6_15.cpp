#include <iostream>

using namespace std;

// doSomething() 함수의 매개변수는 const 참조변수로 선언됨!
// 이 덕분에, 외부 호출부에서 인자를 어떤 방식으로든 자유롭게 전달할 수 있음!
void doSomething(const int& x)
{
    cout << x << endl;
}

int main()
{
    const int x = 5;

    // 참조 변수 선언 및 초기화
    // 참조 변수를 const 로 선언 > 이제 이 참조변수를 de-referencing 해서 원본 변수의 값을 바꿀 수 없음.
    const int& ref_x = x; 

    // 또 다른 const 참조변수를 선언하여 첫 번째 const 참조변수를 할당하는 것도 가능!
    // 어쨋든 이 const 참조변수를 de-referencing 해서 원본 변수 값을 바꾸지 못한다는 것만 알면 됨!
    const int& ref_2 = ref_x;

    /*
        원래 참조변수는 리터럴 값을 직접 할당할 수 없음.

        그러나, const 참조변수라면,
        리터럴 값이나 표현식으로 초기화할 수 있다!

        이 참조변수의 값이나 주소도 스트림 출력이 가능!

        그러면, 
        대체 이 const 참조변수는
        아래와 같은 일반 변수와 다를 게 뭔가?
        const int ref_x2 = 3 + 4;

        이는 함수 파라미터로 const 참조변수를 넣을 때 아주 유용해 짐!

        무슨 말인지는 아래 코드를 좀 더 살펴보면서 알아보자!
    */
    const int& ref_x2 = 3 + 4;
    cout << ref_x2 << endl;
    cout << &ref_x2 << endl;

    int a = 1; // 함수 doSomething 의 인자로 전달할 변수 선언 및 초기화

    doSomething(a); // 만약 doSomething 의 매개변수가 그냥 참조변수 였다면, 인자를 전달하기 위해 원본 변수의 형태로만 전달이 가능함.

    // 그러나, doSomething 의 매개변수가 const 참조변수로 선언된 덕분에,
    // 리터럴, 표현식, 변수와 리터럴를 피연산자로 하는 표현식 등 어떤 형태로든 자유롭게 전달이 가능하다!
    doSomething(1);
    doSomething(a + 3);
    doSomething(3 * 4);


    return 0;
}