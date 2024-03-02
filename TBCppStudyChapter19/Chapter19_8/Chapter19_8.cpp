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
};

int main()
{
    Examples examples;

    examples.ex1();

    return 0;
}