#include <iostream>

using namespace std;

//int value = 123; // main 함수 영역 외부에 선언된 전역변수 >> 다른 함수나 .cpp 파일에서 값을 여기저기서 바꿀 위험성이 있어 사용 자제!
// 그래도 굳이 사용해야 한다면, 1. 전역변수를 사용하는 함수에 인자로 명시적으로 넘겨주거나, 2. g_value 이런 식으로 전역변수임을 명시하는 변수명으로 작성해서
// 프로그래머가 코드를 읽을 때 주의하도록 함. >> 가장 좋은 건 전역변수를 사용하지 않는 방식으로 프로그래밍하는 것!

// static value (정적 변수)
//void doSomething()
//{
//    // static 은 doSomething 이 두 번째 이후부터 호출되면,
//    // 초기에 선언됬던 int a 의 메모리 주소에 대한 기록을 찾아서 거기에 저장된 데이터를 가져와서 그대로 재사용함.
//    // 이때, static 변수는 그렇기 때문에 최초에는 반드시 어떤 값으로 초기화를 해줘야 함.
//    // 그래서 'static int a;' 단순히 이렇게 선언만 해주는 게 불가능함. 
//    // 반드시 최초 1회에 한해 어떠한 값으로 초기화해줘야 함.
//    // 이런 static 변수는 debugging 시 자주 사용된다고 함. > doSomething() 함수가 몇번 호출되는지 세어볼 때...
//    static int a = 1;
//
//    ++a;
//
//    cout << a << endl;
//}

// forward declaration (전방선언) 
// > test.cpp 에 있는 함수의 '선언'을 main 함수 앞부분에 추가함으로써, main() 안에서도 다른 .cpp 파일 내의 함수를 사용할 수 있댔지?
// 이렇게 하면, "다른 파일들 어딘가에 doSomething() 함수의 몸체(구현)이 존재하니까, 찾아가지고 가져다 붙이세요~" 라는 의미임.
// 실행할 때, linking 해서 가져다붙인 걸 사용하라는 의미!
//void doSomething(); // 이렇게 extern 키워드를 생략해서 사용하는 게 더 일반적!
extern void doSomething();

// 이 방법을 변수에도 그대로 적용할 수 있다!
//extern int a = 456; // 이렇게 다른 .cpp 의 변수 a 를 전방선언해서 가져올 시, 값을 다시 초기화하면, "동일한 변수가 중복 선언되었다"는 linking 에러가 발생!
extern int a;

int main()
{
    //cout << value << endl;

    //int value = 1; // name hiding 이 발생하여 외부에 선언된 동일한 이름의 전역변수 value 가 무시됨.

    //cout << ::value << endl; // global scope operation(::) 를 이용해서, name hiding 된 전역변수에 접근 가능!
    //cout << value << endl;

    /*
        원래대로면, int a 는 로컬 변수이기 때문에, 함수 실행 시에 초기화되어,
        doSomething() 몇번 반복 호출하더라도 항상 2가 출력됨.

        그러나, static int a 와 같이 정적변수로 선언될 경우,
        2, 3, 4, 5, ... 이렇게 호출될 때마다 1씩 더해져서 출력됨! > int a 를 전역변수로 선언하는 것과 동일한 결과!

        static 이란 뭘까?
        c 프로그래밍 언어를 만든 사람의 입장에서 생각해봐야 그 뜻이 이해가 됨.

        "변수 a 가 OS 로부터 받은 메모리가 static 하다" 라는 의미!
        메모리가 정적으로 선언이 된다?

        즉, 그냥 int a 로 선언하면,
        해당 함수블록을 벗어나는 순간 메모리가 해제되고
        다시 호출해서 함수블록이 시작되면 메모리가 다시 할당되고를 반복함.

        반면, static 은
        해당 변수에 최초 할당된 메모리와 동일한 공간을 사용함.
        그리고, 초기화를 한 번 밖에 안함. > 그 다음 선언될 때 다시 1로 초기화가 되지 않고, 2, 3, ... 이렇게 증가했던 이유!
    */
    //doSomething();
    //doSomething();
    //doSomething();
    //doSomething();

    // test.cpp > doSomething() 함수를 main() 함수에서 실행시키고 싶다면?
    doSomething();

    cout << a << endl;

    return 0;
}