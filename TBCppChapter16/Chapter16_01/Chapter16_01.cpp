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
}

int main()
{
    /* STL - 컨테이너 */
    // C++ STL 컨테이너에는 아래 세 가지 종류가 있음.

    // sequence containers
    sequence_containers();

    return 0;
}