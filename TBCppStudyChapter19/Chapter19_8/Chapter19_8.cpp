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

    void ex6()
    {
        int x = 42;
        const int* p1 = &x;

        /*
            const 포인터 변수의 경우,
            auto 키워드가 const 까지 알아서 추론해 줌.
        */
        auto p2 = p1;
    }

    /*
        decltype

        자료형이 다른 두 피연산자 간의
        연산의 결과를 추론해주는 예약어
    */
    template<typename T, typename S>
    void func_ex7(T lhs, S rhs)
    {
        /*
            기존 auto 키워드 가지고는
            자료형이 서로 다른 두 매개변수 lhs 와 rhs 의
            곱 연산의 결과값의 자료형 추론이 어려웠음.
        */
        auto prod1 = lhs * rhs;

        /*
            아래와 같이 decltype 예약어를 이용함으로써,
            
            서로 다른 두 자료형 lhs 와 rhs 의 
            연산 결과에 대한 타입을
            
            user-defined 타입을 선언할 수 있게 됨!
        */
        typedef decltype(lhs * rhs) product_type;
        
        product_type prod2 = lhs * rhs;

        decltype(lhs * rhs) prod3 = lhs * rhs;
    }

    /*
        decltype 으로
        함수의 반환값 타입도 선언할 수 있음.

        auto 와 함께 '-> 반환값 타입' 형식으로
        반환값 타입을 정의하는 것은

        C++ 에서 함수의 반환 타입을 정의하는 
        'Trailing return type' 이라는 기법이다!

        특히, 아래처럼
        복잡한 템플릿 파라미터로 선언되어 있는
        함수 템플릿에서 반환 타입을 정의할 때 
        자주 사용되는 문법이라고 함!
    */
    template<typename T, typename S>
    auto func_ex8(T lhs, S rhs) -> decltype(lhs* rhs)
    {
        return lhs * rhs;
    }

    void ex7_8()
    {
        func_ex7(1.0, 345);
        func_ex8(1.2, 345);
    }

    // 예제 설명을 위한 구조체 선언
    struct S
    {
        int m_x; // int 타입 멤버 선언

        // 구조체의 생성자 함수 선언 후, 내부에서 멤버변수 초기화 (구조체도 생성자 함수가 있구나...)
        S()
        {
            m_x = 42; 
        }
    };

    void ex9()
    {
        int x;
        const int cx = 42; // const int 변수
        const int& crx = x; // r-value reference
        const S* p = new S(); // 구조체 S 의 포인터 변수

        // 위에 선언된 변수들에 대한 auto 키워드의 자동 타입 추론을 아래 코드들에서 확인해보자!
        auto a = x;
        auto b = cx;
        auto c = crx;
        auto d = p;

        /*
            p 가 const 이므로 변경이 불가하다면, 
            멤버변수인 m_x 도 변경이 불가할테니 auto 키워드가
            const 까지는 자동 추론을 해줘야 할 것 같지만,

            m_x 의 리터럴 값 자체를
            변수 e 에 복사한다면,
            변수 e 는 이제 const 포인터 변수 p 와 무관하므로,

            얼마든지 수정 가능하게 되어
            const 추론이 빠지게 된 것임!
        */
        auto e = p->m_x;

        /*
            decltype vs auto

            decltype 은 말 그대로
            '선언되어 있는 타입'을 그대로 가져옴.

            따라서, auto 와 달리
            const, &(reference) 등의 예약어를
            그대로 추론하여 가져옴.
        */
        typedef decltype(x) x_type;
        typedef decltype(cx) cx_type;
        typedef decltype(crx) crx_type;

        // 여기서는 m_x 멤버변수가 구조체 내부에서는 'int' 로만 선언(declared) 되어 있으니 int 까지만 추론
        typedef decltype(p->m_x) m_x_type;

        /*
            decltype(()) 로 이중 괄호로 선언할 경우,
            해당 타입을 l-value reference 로 만들어 줌!
        */
        typedef decltype((x)) x_with_parens_type;
        typedef decltype((cx)) cx_with_parens_type;
        typedef decltype((crx)) crx_with_parens_type;
        typedef decltype((p->m_x)) m_x_with_parens_type;
    }

    // 반환값이 const S 인 멤버함수 선언
    const S foo()
    {
        return S();
    }

    // 반환값이 const s& 인 멤버함수 선언
    const int& foobar()
    {
        return 123;
    }

    void ex10()
    {
        std::vector<int> vect = { 42, 43 };

        /*
            각 케이스별
            auto vs decltype
            의 타입 추론 차이점
        */
        auto a = foo();
        typedef decltype(foo()) foo_type;

        auto b = foobar();
        typedef decltype(foobar()) foobar_type;

        auto itr = vect.begin();
        typedef decltype(vect.begin()) iterator_type;

        /*
            왜 std::vector 의 요소들이
            auto 에서는 그냥 'int' 로 추론되고,
            decltype 에서는 'int&' 로 추론될까?

            std::vector 내의 [] 연산자 오버로딩 함수에서는
            l-value reference(&) 를 반환하도록 되어 있음!

            따라서, 반환값의 타입 선언(decl)을 그대로 유지한 채
            가져오기 때문에, int& 로 타입 추론이 되는 것임.
        */
        auto first_element = vect[0];
        decltype(vect[1]) second_element = vect[1];
    }

    /*
        decltype 으로 
        자료형이 서로 다른 두 피연산자의 
        연산 결과 타입 추론하기
    */
    void ex11()
    {
        int x = 0;
        int y = 0;
        const int cx = 42;
        const int cy = 43;
        double d1 = 3.14;
        double d2 = 2.72;

        typedef decltype(x * y) prod_xy_type;
        auto a = x * y;

        /*
            cx, cy 는 const int 이지만,
            두 피연산자를 곱한 결과값은 리터럴, 
            
            즉, r-value reference 이므로,
            const 가 붙지 않고, int 까지만 추론해 줌!
        */
        typedef decltype(cx * cy) prod_cxcy_type;
        auto b = cx * cy;

        /*
            decltype 으로 삼항연산자의 결과값의 자료형을 추론할 때에는,
            & 가 하나 붙어서 l-value reference 로 추론됨.
        */
        typedef decltype(d1 < d2 ? d1 : d2) cond_type;
        auto c = d1 < d2 ? d1 : d2;

        /*
            서로 다른 자료형 int 와 double 로
            삼항 연산자를 비교할 경우, int 가 double 로 promotion 되어
            결과값의 타입이 double 로 추론됨!
        */
        typedef decltype(x < d2 ? x : d2) cond_type_mixed;
        auto d = x < d2 ? x : d2;

        /*
            std::min() 함수는
            크기를 비교할 두 피연산자의 자료형을
            동일하게 맞춰줘야 한다는 한계점이 있음.

            decltype 을 이용하여,
            자료형이 서로 다른 두 연산자 간의 크기를 비교하는
            함수를 직접 구현해보자 (하단 fpmin() 함수 참고)
        */
        //auto d = std::min(x, d1); // error
    }

    /*
        아래와 같이 크기 비교 함수를 구현할 경우,
        x, y 가 서로 같은 자료형일 경우,
        위에서 확인해 본 바와 같이,

        decltype() 에 의해 l-value reference 로 
        타입이 추론되어 버리는 문제점이 있음!
    */
    template<typename T, typename S>
    auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)
    {
        return x < y ? x : y;
    }

    /*
        std::remove_reference<decltype(표현식)>::type

        아래와 같이 std::remove_reference 와 decltype 을 같이 사용하면,
        
        동일한 타입의 템플릿 파라미터에 대해 
        decltype 이 l-value reference 로 타입을 추론해버리는
        문제를 해결할 수 있음!
    */
    template<typename T, typename S>
    auto fpmin(T x, S y) -> 
        typename std::remove_reference<decltype(x < y ? x : y)>::type
    {
        return x < y ? x : y;
    }

    void ex12()
    {
        int i = 42;
        double d = 45.1;

        auto a = std::min(static_cast<double>(i), d);
        
        // int 타입 변수 i 에 대한 참조변수 선언
        int& j = i;

        // 전달되는 두 템플릿 파라미터의 타입이 동일할 경우, l-value reference 로 반환 타입이 추론되어 버림.
        typedef decltype(fpmin_wrong(d, d)) fpmin_return_type1;

        // 희한하게 두 파라미터의 타입이 다르면 double 로 추론해 줌.
        typedef decltype(fpmin_wrong(i, d)) fpmin_return_type2;

        // 파라미터 중 하나가 l-value reference 여도 double 로 추론함 -> 그냥 지 맘대로 추론해버림. 이런 게 문제라는 거..
        typedef decltype(fpmin_wrong(j, d)) fpmin_return_type3;
    }

    void ex13()
    {
        /*
            decltype 은 std::vector 가 실제로는 비어있더라도,
            그저 타입 추론을 위해 사용되는 것이므로,

            std::vector 내부에 오버로딩된
            [] 연산자를 사용해서 비어있는 요소에 접근하더라도,
            에러를 발생시키지 않고 타입 추론만 해줌! 
        */
        std::vector<int> vect; // vect is empty
        typedef decltype(vect[0]) integer;
    }
};

int main()
{
    Examples examples;

    examples.ex1();

    return 0;
}