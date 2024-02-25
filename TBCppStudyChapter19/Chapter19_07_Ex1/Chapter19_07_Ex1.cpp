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


int main()
{
    MyStruct s;

    /*
        아래와 같이 
        각각 l-value 와 r-value 로 정의된 매개변수 오버로딩을
        직접적으로 호출하면 컴파일러가 알아서 구분해 줌!
    */

    // l-value reference 로 오버로딩된 함수 실행
    func(s);

    // r-value reference 로 오버로딩된 함수 실행
    func(MyStruct());

    return 0;
}