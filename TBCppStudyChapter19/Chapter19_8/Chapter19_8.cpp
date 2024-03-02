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
};

int main()
{
    Examples examples;

    examples.ex1();

    return 0;
}