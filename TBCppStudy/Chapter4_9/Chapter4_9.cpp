#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
    /*
        type aliases (자료형 가명(별명))

        double 이라는 실수형 타입을
        거리에도 쓸 수 있고, 속력에도 쓸 수 있겠지?

        이를 주석으로 표시해둘 수도 있지만,
        아예 '거리 타입을 정의하기 위해 사용하는 double 실수형 타입' 을
        명시하기 위해서, double 타입에 별명을 붙이면 더 인지하기 좋겠지?

        이를 위해 사용하는 것이 type alias!

        c++ 에서는
        typedef 문법으로 자료형에 별칭을 선언할 수 있음!
    */
    //typedef double distance_t; // 여기서 _t 는 '기존 자료형을 상황에 적합하게 가명을 붙여줬다'는 의미의 convention 으로 쓴다고 함.

    // 타입 별칭의 또 다른 장점이, 
    // '속력'에 관한 모든 변수들의 타입을 double > float 으로 바꿔줘야 한다면, 
    // 해당 변수들을 찾아가 일일이 바꾸지 않더라도,
    // 타입 별칭의 원래 자료형만 double > float 으로 바꿔주면
    // 해당 타입 별칭을 사용하고 있는 속력에 관한 변수들의 타입도 자동으로 float 으로 지정할 수 있음!
    typedef float distance_t; 

    std::int8_t i(97); // 이런 식으로, c++ 11 고정너비 정수형 타입에서도 _t 같은 convention 이 들어갔었지?

    // 두 가지 방법 모두 컴파일러 입장에서는 같은 double 타입 실수형 변수.
    // 그러나, 프로그래밍 편의를 위해서 동일한 타입이더라도, 상황에 맞게 별명을 붙여서 사용할 수 있다는 것!
    double      my_distance;
    distance_t  home2work;
    distance_t  home2school;

    // 또, 아래와 같이 굉장히 자료형이 복잡해지는 경우에도,
    // typedef 를 사용하여 별칭을 선언하면, 더욱 보기좋게 코딩할 수 있음!
    //typedef std::vector<std::pair<std::string, int>> pairlist_t;

    // 또 최근에는 typedef 와 동일한 기능을 using 으로도 구현할 수 있음! 
    // 주의할 점은, = 연산자가 들어간다고 해서 '변수에 메모리를 할당'하는 개념이 아님!
    // 그냥 이러이러한 타입을 pairlist_t 라는 별명으로 쓰겠다고 선언하는 것!
    // 내부적으로 작동하는 방식이 아예 다름!
    // 그냥 사람 입장에서 이해하기 쉽게 '=' 를 이용해서 쓴 것!!
    using pairlist_t = std::vector<std::pair<std::string, int>>; 

    pairlist_t pairlist1;
    pairlist_t pairlist2;

    return 0;
}
