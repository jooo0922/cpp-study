#include <iostream>
#include <vector>
#include <cstdio>
#include <utility> // std::forward 사용을 위해 포함

using namespace std;

// std::vector 를 커스텀 구현한 클래스
class CustomVector
{
public:
    unsigned n_data = 0;
    int* ptr = nullptr;

    // default 생성자
    CustomVector(const unsigned& _n_data, const int& _init = 0)
    {
        cout << "Constructor" << endl;

        /*
            객체 지향 프로그래밍을 하다보면, 
            생성자에서 직접 초기화하기 보다는, 아래 init() 과 같이
            초기화하는 멤버 함수를 별도로 추출해서 사용하는 게 더 편리함.
        */
        init(_n_data, _init);
    }

    // copy constructor (매개변수는 l-value reference 로 선언)
    CustomVector(CustomVector& l_input)
    {
        cout << "Copy constructor" << endl;

        // 별도로 동적 배열 메모리 할당 및 초기화
        init(l_input.n_data);

        // 전달받은 다른 CustomVector 인스턴스를 깊은 복사
        for (unsigned i = 0; i < n_data; i++)
        {
            ptr[i] = l_input.ptr[i];
        }
    }

    // move constructor (매개변수는 r-value reference 로 선언)
    CustomVector(CustomVector&& r_input)
    {
        cout << "Move constructor" << endl;

        // 전달받은 r-value reference 인 CustomVector 인스턴스의 메모리 소유권(= 포인터 주소값)만 '이동'
        n_data = r_input.n_data;
        ptr = r_input.ptr; 

        // 전달받은 CustomVector 는 r-value reference 이므로, 메모리 소유권을 없애버려도 아무 상관 없음.
        // 어차피 r-value reference 는 메모리에 저장되어 있는 변수가 아니므로, 이 생성자 함수가 끝나면 사라져 버릴 것임.
        r_input.n_data = 0;
        r_input.ptr = nullptr;
    }

    // 소멸자 함수에서 할당된 동적 메모리 반납
    ~CustomVector()
    {
        delete[] ptr;
    }

    // 초기화 함수
    void init(const unsigned& _n_data, const int& _init = 0)
    {
        n_data = _n_data;
        ptr = new int[n_data]; // n_data 개수만큼 힙 메모리에 동적 배열 할당
        for (unsigned i = 0; i < n_data; i++)
        {
            // 할당된 동적 배열의 값들을 _init 으로 초기화
            ptr[i] = _init;
        }
    }
};

// l-value reference 를 매개변수로 전달받는 함수
void doSomething(CustomVector& vec)
{
    cout << "Pass by L-ref" << endl;

    // copy constructor 오버로딩이 실행되겠군
    CustomVector new_vec(vec);
}

// r-value reference 를 매개변수로 전달받는 함수 
// (l-value ref 와 r-value ref 는 서로 다른 매개변수로 오버로딩 가능!)
// (https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter15/Chapter15_02/Chapter15_02.cpp 참고)
void doSomething(CustomVector&& vec)
{
    cout << "Pass by R-ref" << endl;

    // move constructor 오버로딩이 실행되겠군
    CustomVector new_vec(std::move(vec));
}

/*
    Chapter19_07_Ex1 예제와 마찬가지로,
    
    함수 템플릿을 wrapper 로 감싸서
    위의 두 오버로딩된 함수를 호출하면,
    l-value 였는지 r-value 였는지에 대한 정보가 날라가 버려서
    문제가 발생하겠지!

    그래서 std::forward<T>() 를 사용해서
    오버로딩된 함수 doSomething() 에 vec 을 전달할 때,

    r-value 인지 l-value 인지 명확하게 판단해서
    해당하는 참조변수로 변환한 다음 전달시켜 줌!

    -> perfect forwarding!
*/
template<typename T>
void doSomethingTemplate(T&& vec)
{
    // move constructor 오버로딩이 실행되겠군
    doSomething(std::forward<T>(vec));
}



int main()
{
    CustomVector my_vec(10, 1024);

    // l-value reference 를 생성자에 전달 -> copy semantics 로 오버로딩된 생성자 함수가 실행되겠군!
    //CustomVector temp(my_vec);

    // std::move() 로 r-value reference 로 변환하여 생성자에 전달 -> move semantics 로 오버로딩된 생성자 함수가 실행되겠군!
    //CustomVector temp2(std::move(my_vec));

    //cout << my_vec.n_data << endl;

    // l-value reference 오버로딩 함수가 호출
    //doSomething(my_vec);

    // l-value reference 오버로딩 함수가 호출
    //doSomething(CustomVector(10, 8));

    // 함수 템플릿 wrapper 를 통해 오버로딩된 함수 doSomething() 간접 호출
    doSomethingTemplate(my_vec);
    doSomethingTemplate(CustomVector(10, 8));

    return 0;
}