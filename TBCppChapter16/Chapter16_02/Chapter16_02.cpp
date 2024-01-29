#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
    // vector 컨테이너 생성 후, 데이터 초기화
    vector<int> container;
    for (int i = 0; i < 10; i++)
    {
        container.push_back(i);
    }

    // vector 컨테이너의 각 요소들을 순회할 때 사용할 반복자 자체를 하나의 변수로 선언함
    vector<int>::const_iterator itr;

    // vector 컨테이너의 반복자를 초기화할 때에는, std::vector<>.begin() 을 사용함.
    /*
        이 STL 반복자의 장점은,
        다른 컨테이너에서도 동일한 반복자를 사용할 수 있다는 것!

        즉, 여러 종류의 컨테이너에서 동일한 반복자 인터페이스를 제공함으로써,
        다양한 컨테이너 순회를 일관되게 다룰 수 있음!
    */
    itr = container.begin();
    
    // 반복자가 container.end() 와 같아질 때까지 계속 순회함
    while (itr != container.end())
    {
        // 반복자를 de-referencing 한 값을 출력 (de-referencing 연산자를 오버로딩해서 커스텀하게 무언가를 출력 가능)
        cout << *itr << " ";

        // 반복자를 증가 연산자로 증가시킴
        ++itr;
    }
    cout << endl;

    // 아래와 같이 for 문에서는 auto 타입으로 반복자 타입을 자동 형변환하여 사용 가능!
    for (auto itr = container.begin(); itr != container.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}