#include <iostream>
#include <algorithm> // STL 알고리즘 함수들 (정확히는 util 함수들에 더 가까움)
#include <vector>

using namespace std;

int main()
{
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


    return 0;
}