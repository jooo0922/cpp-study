#include <iostream>
#include <vector>
#include <utility> // std::forward 사용을 위해 포함

using namespace std;

struct MyStruct
{};

// l-value reference 를 매개변수로 전달받는 함수
void func(MyStruct& s)
{
    cout << "Pass by L-ref" << endl;
}

// r-value reference 를 매개변수로 전달받는 함수 
// (l-value ref 와 r-value ref 는 서로 다른 매개변수로 오버로딩 가능!)
// (https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter15/Chapter15_02/Chapter15_02.cpp 참고)
void func(MyStruct&& s)
{
    cout << "Pass by R-ref" << endl;
}

/*
    void func() 함수에 대한
    wrapper 함수를 함수 템플릿으로 구현

    그러나, 아래와 같이
    함수 템플릿을 거친 후에,
    각 매개변수 오버로딩을 간접 호출하면

    템플릿 파라미터 T 로 전달되는 값이 Templatize 되면서

    원래 l-value 였는지 r-value 였는지에 대한 정보가
    날아가 버리기 때문에

    컴파일러가
    r-value reference 와 l-value reference 오버로딩을
    구분하지 못함!

    이처럼 오버로딩을 구분하지 못하는 문제는
    perfect forwarding 이라는 기법으로 해결 가능하며,
    이는 std::forward<T>() 로 구현할 수 있음!
*/
template<typename T>
void func_wrapper(T&& t) // perfect forwarding 을 사용하려면 일단 템플릿 파라미터를 r-value reference 로 선언해야 함.
{
    /*
        std::forward<T>() 가 하는 일은,
        매개변수로 들어온 t 가
        l-value 로 들어왔다면 l-value reference 를 반환해주고,
        r-value 로 들어왔다면 r-value reference 를 반환해줌!
    */
    func(std::forward<T>(t));
}

int main()
{
    MyStruct s;

    /*
        아래와 같이 
        각각 l-value 와 r-value 로 정의된 매개변수 오버로딩을
        직접적으로 호출하면 컴파일러가 알아서 구분해 줌!
    */    
    //func(s); // l-value reference 로 오버로딩된 함수 실행
    //func(MyStruct()); // r-value reference 로 오버로딩된 함수 실행

    /*
        그러나, 아래와 같이
        함수 템플릿을 거친 후에,
        각 매개변수 오버로딩을 간접 호출하면

        컴파일러가 
        r-value reference 와 l-value reference 오버로딩을
        구분하지 못함!

        why?
        -> 템플릿 파라미터 T 로 전달되는 값이
        Templatize 되면서 

        원래 l-value 였는지 r-value 였는지에 대한 정보가
        날아가 버리기 때문!
    */
    func_wrapper(s);
    func_wrapper(MyStruct());

    return 0;
}