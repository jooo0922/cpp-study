#include <iostream>
#include <algorithm> // STL 알고리즘 함수들 (정확히는 util 함수들에 더 가까움)
#include <vector>

using namespace std;

int main()
{
    /* std::min_element(), std::max_element() */

    // vector 컨테이너 선언 및 동적 배열에 요소들을 추가
    vector<int> container;
    for (int i = 0; i < 10; i++)
    {
        container.push_back(i);
    }

    /*
        vector 컨테이너에 추가된 요소들 중, 
        가장 작은 요소를 반환하려면, 

        컨테이너 반복자 std::vector<>.begin() 과 std::vector<>.end() 를 
        min_element() 함수에 전달하면, begin 과 end 사이에서
        가장 작은 요소를 반환해 줌.
    */
    auto itr = min_element(container.begin(), container.end());

    // 반환된 가장 작은 요소를 de-referencing 하여 출력
    cout << *itr << endl;

    // 반대로 가장 큰 요소를 반환하려면 max_element() 를 사용
    itr = max_element(container.begin(), container.end());
    cout << *itr << endl;

    cout << endl;


    /* std::find() */

    /*
        특정 컨테이너의 반복자 .begin() 부터 .end() 까지 중에서
        특정 요소를 찾으려면,

        find() 함수에
        '.begin(), .end(), 찾고자 하는 요소' 를 전달함.

        이때, itr 은 해당 요소를 가리키는 반복자 포인터 주소값이 할당됨!
    */
    itr = find(container.begin(), container.end(), 3);

    /*
        std::vector<>.insert() 를 사용하면,
        컨테이너 내의 특정 요소의 메모리 공간을 가리키는 반복자 포인터를 사용해서,
        해당 반복자가 가리키는 메모리 공간에 저장된 요소를 변경할 수 있음!

        -> 여기서는 3이 차지하던 메모리 공간에 128이 들어가고,
        3 이후부터의 요소들은 한 칸씩 뒤로 밀려날 것임!
    */
    container.insert(itr, 128);

    for (auto& e : container)
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}