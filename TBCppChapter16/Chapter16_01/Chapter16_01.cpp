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

    // multiset : set 과 거의 같으나, 중복 원소를 허용함!
    {
        std::multiset<string> str_set;

        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello"); // 중복 원소 추가 허용
    
        cout << str_set.size() << endl;

        for (auto& e : str_set)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    // map : key/value 쌍의 자료구조 -> json 구조와 동일함
    {
        std::map<char, int> map;
        map['a'] = 10;
        map['b'] = 20;
        map['c'] = 50;

        cout << map['a'] << endl;

        map['a'] = 100; // 'a' 의 value 를 변경함.

        cout << map['a'] << endl;

        for (auto& e : map)
        {
            /*
                std::map<key, value>.first 는 key 가 할당된 field 이고,
                std::map<key, value>.second 는 value 가 할당된 field 임.

                first 에 마우스를 갖다대면,
                내부적으로 std::pair<key, value> 타입으로
                저장되어 있다는 것을 알 수 있음!
            */
            cout << e.first << " " << e.second << " ";
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