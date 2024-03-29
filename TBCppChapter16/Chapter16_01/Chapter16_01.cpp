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

    // multimap : 중복 key 를 허용함!
    {
        std::multimap<char, int> map;

        map.insert(std::pair('a', 10)); // 컴파일러가 c++ 14 이하이면, 그냥 pair<char, int> 를 사용해야 함.
        map.insert(std::pair('b', 10));
        map.insert(std::pair('c', 10));
        map.insert(std::pair('a', 100)); // 중복된 key 값으로 구성된 std::pair<> 추가 시도!

        // multimap 은 중복된 key 로 등록된 원소가 몇 개인지 .count 로 확인할 수 있음!
        cout << map.count('a') << endl;

        for (auto& e : map)
        {
            // std::map 과 마찬가지로 std::pair<> 로 원소가 추가되어 있으므로,
            // .first, .second 로 원소의 key, value 에 각각 접근 가능!
            cout << e.first << " " << e.second << " ";
        }
        cout << endl;
    }
}

void container_adapters()
{
    // stack
    {
        cout << "Stack" << endl;

        std::stack<int> stack;

        // std::stack<>.push() 는 요소를 '복사'해서 추가함 
        // (int 같은 리터럴은 차이가 없지만, class 같은 사용자 정의 자료형을 push 로 넣을 땐 차이가 날 것임!)
        stack.push(1); 

        // std::stack<>.emplace() 는 새로운 객체를 만들어서 추가함 
        stack.emplace(2);
        stack.emplace(3);

        // stack 의 최상위 노드 출력
        cout << stack.top() << endl;

        // stack 의 최상위 노드 제거
        stack.pop();

        // stack 의 새로운 최상위 노드 출력
        cout << stack.top() << endl;
    }

    // queue
    {
        cout << "Queue" << endl;

        std::queue<int> queue;

        // enqueue
        queue.push(1);
        queue.push(2);
        queue.push(3);

        // std::queue<>.front() 는 Queue 의 헤드노드를 반환하고,
        // std::queue<>.back() 은 Queue 의 테일노드를 반환함.
        cout << queue.front() << " " << queue.back() << endl;

        // dequeue
        queue.pop();

        // 헤드노드 dequeue 후 새로운 헤드노드와 테일노드 재출력
        cout << queue.front() << " " << queue.back() << endl;
    }

    // Priority queue (우선순위 큐)
    {
        cout << "Priority queue" << endl;

        std::priority_queue<int> queue;

        // 아래와 같이 for-each 문을 사용할 수도 있음.
        for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        {
            // 랜덤한 순서의 int 타입 요소 n 값을 우선순위 삼아 정렬하면서 Enqueue 함.
            queue.push(n);
        }

        for (int i = 0; i < 10; i++)
        {
            // 반복문을 순회하며 현재 우선순위 큐의 테일노드(.top())를 출력하고,
            // 해당 테일노드를 Dequeue 한 뒤에 다음 순회로 넘어감.
            cout << queue.top() << endl;
            queue.pop();
        }
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

    // container adapters
    container_adapters();

    return 0;
}