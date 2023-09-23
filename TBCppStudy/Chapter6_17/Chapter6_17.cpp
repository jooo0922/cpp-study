#include <iostream>

using namespace std;

int main()
{
    const int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    
    // for-each 문으로 배열 순회하기
    // 배열의 각 요소를 출력하기
    for (int number : fibonacci)
        cout << number << " ";

    cout << endl;

    return 0;
}