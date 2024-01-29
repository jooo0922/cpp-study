#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
    // vector 컨테이너 생성 후, 데이터 초기화
    //vector<int> container;

    // 동일한 반복자 인터페이스를 List 컨테이너에서도 사용 가능
    // -> 아래 for 문에서 auto 키워드를 통해 List 컨테이너에 맞는 반복자 타입으로 자동 형변환 해줌. 
    //list<int> container;

    // 이번에는 Set 컨테이너에 반복자를 사용해보자
    //set<int> container;

    // 이번에는 Map 컨테이너에 반복자를 사용해보자
    map<int, char> container;

    for (int i = 0; i < 10; i++)
    {
        //container.push_back(i);

        // set 컨테이너는 요소 추가 시, insert() 를 사용했었지?
        //container.insert(i);

        // map 컨테이너는 요소 추가 시, std::pair<key, value> 형태로 추가했었지?
        // std::pair<key, value> 는 std::make_pair(key, value) 로도 만들 수 있음!
        container.insert(make_pair(i, char(i + 65)));
    }

    // vector 컨테이너의 각 요소들을 순회할 때 사용할 반복자 자체를 하나의 변수로 선언함
    // 다만, 이처럼 특정 컨테이너의 반복자 타입을 명시하면 다른 컨테이너에서 사용할 때 컴파일 에러가 발생함...
    //vector<int>::const_iterator itr;

    // vector 컨테이너의 반복자를 초기화할 때에는, std::vector<>.begin() 을 사용함.
    //itr = container.begin();
    
    // 반복자가 container.end() 와 같아질 때까지 계속 순회함
    //while (itr != container.end())
    //{
    //    // 반복자를 de-referencing 한 값을 출력 (de-referencing 연산자를 오버로딩해서 커스텀하게 무언가를 출력 가능)
    //    cout << *itr << " ";

    //    // 반복자를 증가 연산자로 증가시킴
    //    ++itr;
    //}
    //cout << endl;

    // 아래와 같이 for 문에서는 auto 타입으로 반복자 타입을 자동 형변환하여 사용 가능!
    /*
        이처럼 STL 반복자는 
        auto 타입으로 자동 형변환을 활용하면,
        다른 컨테이너에서도 동일한 반복자를 사용할 수 있다는 것!

        즉, 여러 종류의 컨테이너에서 동일한 반복자 인터페이스를 제공함으로써,
        다양한 컨테이너 순회를 일관되게 다룰 수 있음!
    */
    for (auto itr = container.begin(); itr != container.end(); ++itr)
    {
        //cout << *itr << " ";

        // map 컨테이너에서는 반복자를 de-referencing 할 경우, std::pair<key, value> 를 가리키므로,
        // 얘내들을 출력하려면, .first, .second 를 사용해야 된다고 했었지?
        cout << itr->first << " " << itr->second << endl;
    }
    cout << endl;

    return 0;
}