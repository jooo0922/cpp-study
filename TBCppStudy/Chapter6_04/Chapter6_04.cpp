#include <iostream>

using namespace std;

int main()
{
    /*                  value       index
        3 5 2 1 4         1           3      // 0번 index 요소부터 반복문을 돌린 결과, 3번 index 의 값 1 이 가장 작다는 걸 확인 > 0번 index 의 3과 교체(swapping)!
        1 5 2 3 4         2           2      // 1번 index 요소부터 반복문을 돌린 결과, 2번 index 의 값 2 가 가장 작다는 걸 확인 > 1번 index 의 5와 교체
        1 2 5 3 4         3           3      // 2번 index 요소부터 반복문을 돌린 결과, 3번 index 의 값 3 이 가장 작다는 걸 확인 > 2번 index 의 5와 교체
        1 2 3 5 4         4           4      // 3번 index 요소부터 반복문을 돌린 결과, 4번 index 의 값 4 가 가장 작다는 걸 확인 > 3번 index 의 5와 교체 ... 5가 점점 밀려나는 걸 볼 수 있음.
        1 2 3 4 5                            // 최종적으로 1, 2, 3, 4, 5 의 오름차순으로 배열 요소가 정렬된 것을 볼 수 있음! -> 이것을 '선택정렬' 이라고 함!
    */
    
    // 위에서 설명한 선택정렬을 코드로 구현해보자
    const int length = 5;

    int array[length] = { 3, 5, 2, 1, 4 };

    for (int index = 0; index < length; ++index)
    {
        cout << array[index] << " ";
    }
    cout << endl;

    return 0;
}