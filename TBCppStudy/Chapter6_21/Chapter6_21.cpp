#include <iostream>
#include <vector> // std::vector 로 동적 배열 라이브러리 사용하기 위해 포함

using namespace std;

int main()
{
    // std::array 와 달리 동적 배열 라이브러리(동적 배열 = 리스트) 이므로, 처음부터 크기를 할당하지 않아도 됨.
    /*
        추가로, 배열을 힙 메모리에 동적으로 할당(생성)할 때,
        int* my_arr = new int[5]; 
        이런 식으로 할당하고,

        함수 블록이 종료되기 전에
        delete [] my_arr; 
        이런 식으로 힙 메모리를 반납하는 작업을 일일이 해줘야 했음.

        그러나,
        std::vector 는 이렇게 동적으로 할당된 힙 메모리를
        함수 블록이 끝나면 알아서 자동으로 반납해주기 때문에
        메모리 관리에 대한 스트레스를 줄여준다는 장점!
    */
    std::vector<int> array;

    // 동적 배열 std::vector 초기화 방법
    std::vector<int> array2 = { 1, 2, 3, 4, 5 };

    // std::vector 는 동적 배열도 std::array 와 마찬가지로 .size() 로 배열 크기를 바로 확인할 수 있음.
    cout << array2.size() << endl;

    std::vector<int> array3 = { 1, 2, 3 };

    cout << array3.size() << endl;

    // uniform initialization 도 가능
    std::vector<int> array4 { 1, 2, 3 };

    cout << array4.size() << endl;

    // std::vector 를 for-each 문으로 출력하기
    vector<int> arr = { 1, 2, 3, 4, 5 };

    // .resize() 메서드로 std::vector 의 크기를 동적으로 변경하는 것도 가능함.
    // 현재 5개의 요소가 들어있는데 동적 배열 크기를 10개로 변경한다면, 나머지 요소들은 0으로 초기화됨!
    arr.resize(10);
    arr.resize(2); // 또는 원래 크기보다 더 적은 크기로 변경할 경우, {1, 2}까지만 살아남고 나머지 요소들은 날려버림!

    for (auto& itr : arr)
    {
        cout << itr << " ";
    }
    cout << endl;

    // std::vector 의 각 요소 접근 (std::array 와 동일)
    cout << arr[1] << endl;
    cout << arr.at(1) << endl;

    return 0;
}