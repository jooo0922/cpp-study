#include <iostream>
#include <vector>
#include <algorithm> // std::min() 사용을 위해 포함

using namespace std;

class Examples
{
public:
    
    void ex1()
    {
        std::vector<int> vect;

        // 기존에 std::vector 를 순회하려면 STL 반복자의 타입을 일일이 선언해줘야 했음
        for (std::vector<int>::iterator itr = vect.begin(); itr < vect.end(); itr++)
        {
            // 반복자를 de-referencing 해서 출력
            cout << *itr;
        }

        // auto 를 사용하면 자료형을 자동으로 추론해줘서 아주 편리함.
        for (auto itr = vect.begin(); itr < vect.end(); itr++)
        {
            cout << *itr;
        }

        // 위의 auto 를 사용한 반복문을 더 축약해서 for-each 문으로도 만들어서 사용했었지?
        for (auto itr : vect) // for (const auto& itr : vect)
        {
            cout << itr;
        }
    }

    void ex2()
    {
        int x = int();

        // auto_x 변수명에 마우스를 갖다대면 'int auto_x' 와 같이 자료형이 자동으로 추론되고 있음!
        auto auto_x = x;

        const int& crx = x;

        // auto_crx1 에 마우스 갖다대면 'int auto_crx1' 이라고만 추론됨.
        // -> 즉, auto 는 const, &(reference) 등의 예약어들은 제외하고 추론해 줌!
        auto auto_crx1 = crx;

        // auto 로 자료형 추론 시, const, & 를 함께 사용하고 싶다면, 별도로 선언해줘야 함.
        const auto& auto_crx2 = crx;

        /*
            volatile

            값이 자주 변경되는 변수이므로,
            최적화 시 빼달라는 의미를 갖는 예약어.

            이 예약어도 const, & 와 마찬가지로
            auto 가 자동으로 추론해주지는 못함.
        */
        volatile int vx = 1024;

        auto avx = vx;

        volatile auto vavx = vx;
    }

    /*
        함수 템플릿의 파라미터에서
        자료형 추론이 적용된다면?
    */
    template<class T>
    void func_ex3(T arg)
    {}

    /*
        함수 템플릿에서도 마찬가지로
        const, & 등의 예약어 추론까지 포함하고 싶다면,

        템플릿 파라미터의 타입을 선언할 때,
        해당 예약어를 자체적으로 선언해줘야 함.
    */
    /*template<class T>
    void func_ex3(const T& arg)
    {}*/

    void ex3()
    {
        const int& crx = 123;

        /*
            마찬가지로, 함수 템플릿의 
            템플릿 파라미터 타입에 대해 자료형 추론 시,

            const, & 등의 예약어는 다 제외되고,
            'int' 타입만 자동 추론됨!
        */
        func_ex3(crx);
    }

    void ex4()
    {
        const int c = 0;

        /*
            변수 c 가 const 인데,
            이것을 l-value reference(참조변수) 로 가져오려고 한다면,

            당연히 원본변수가 const 이면
            참조변수도 const 여야 하므로,

            이럴 경우, 예외적으로
            auto 가 똑똑하게 const 로 자료형 추론을 해줌!
        */
        auto& rc = c;
        //rc = 123; // error
    }

    // amendment (개정)
    void ex5()
    {
        int i = 42;

        /*
            auto&& 로 r-value reference 를 선언할 경우,

            할당된 값이 r-value 이면,
            r-value reference 로 auto 가 자료형 추론을 해주고,

            할당된 값이 l-value 이면,
            l-value reference 로 auto 가 자료형 추론을 해줌.
            -> 이러한 과정을 'amendment(개정)' 이라고 함!
        */
        auto&& ri_1 = i; // l-value
        auto&& ri_2 = 42; // r-value
    }
};

int main()
{
    Examples examples;

    examples.ex1();

    return 0;
}