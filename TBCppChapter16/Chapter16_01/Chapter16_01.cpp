#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void sequence_containers()
{
    // vector
    {
        // #include <vector> 헤더를 포함시켜야 함.
        // 컨테이너의 경우, 사용하는 헤더와 이름이 겹치는 경우가 많음.
        vector<int> vec;
        for (int i = 0; i < 10; i++)
        {
            vec.push_back(i);
        }

        for (auto& e : vec)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    // deque
    {
        deque<int> deq;
        for (int i = 0; i < 10; i++)
        {
            /*
                vector 가
                요소들을 뒤에만 추가할 수 있는 것과 달리,

                deque 는
                요소들을 앞 / 뒤 모두에 추가할 수 있음!
            */
            deq.push_back(i);
            deq.push_front(i);
        }

        for (auto& e : deq)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

void associative_containers()
{
    // set
    /*
        영어 단어 뜻 그대로 '집합' 자료구조

        중복된 원소를 허용하지 않음.
        js 의 Set 과 유사한 자료구조
    */
    {
        set<string> str_set;

        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello"); // 중복된 원소 추가 시도

        cout << str_set.size() << endl; // 중복된 원소를 제외한 set 의 크기는 2

        for (auto& e : str_set)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

int main()
{
    /* STL - 컨테이너 */
    // C++ STL 컨테이너에는 아래 세 가지 종류가 있음.

    // sequence containers
    sequence_containers();

    // associative containers
    associative_containers();

    return 0;
}