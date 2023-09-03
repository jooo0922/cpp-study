#include <iostream>

using namespace std;

// 배열을 순회하며 출력하는 함수 추출
void printArray(const int array[], const int length) // 매개변수를 함수 내에서 변경하지 않을 것이므로, const 를 붙여서 데이터를 불변으로 만듦. > 실수를 최대한 줄이기 위함.
{
    for (int index = 0; index < length; ++index)
    {
        cout << array[index] << " ";
    }
    cout << endl;
}

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

    printArray(array, length);

    // 위 알고리즘에서 사용된 swap (배열 요소 간 위치 변경)은 어떻게 구현하나?
    // int temp = array[0]; // 일반적으로, 교체할 배열 요소의 값을 임시로 보관해놓는 변수 temp 에 값을 복사해 놓고 사용함.
    // array[0] = array[1];
    // array[1] = temp;
    // printArray(array, length); // swap 된 배열 확인
    // 위 방식과 동일한 기능을 하는 함수가 std::swap() 으로 라이브러리에 구현되어 있음!

    // 위 알고리즘 대로라면, 
    // 하나의 배열을 각 배열 요소를 출발점으로 하여 순회하고, 
    // 또 각 배열 요소 출발점부터 마지막 배열 요소까지 순회를 해야 하니, 
    // 이중 for loop 를 사용해야 한다는 걸 눈치챘을 것임!
    for (int startIndex = 0; startIndex < length - 1; ++startIndex) // 위 알고리즘에서 마지막 번째 요소는 출발점으로 두고 순회하지 않았으므로, length - 1(출발점으로 두고 순회할 배열 요소의 개수는 마지막 요소는 제외!) 만큼만 반복문을 돌려줘야겠지!
    {
        int smallestIndex = startIndex; // 위 알고리즘에서 출발점 요소 이후의 요소들과 비교하면서 가장 작은 요소의 index 값을 저장해뒀었지? 그걸 저장해둘 변수!

        // 안쪽 반복 루프에서는 각 배열 요소를 반복 순회의 출발점으로 지정하기 때문에,
        // 안쪽 반복문의 초기 인덱스 값은 각 배열 요소의 인덱스 + 1 로 초기화함.
        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            if (array[smallestIndex] > array[currentIndex])
            {
                // 각 반복 루프의 출발점 이후의 요소들과 비교하면서 더 작은 요소의 index 를 계속 갱신함.
                // 참고로, 우리는 index 값만 알고 있으면 index 에 대응되는 value 는 array[index] 로 접근 가능하므로,
                // index 에 대응되는 value 는 별도로 저장하지 않고 있음.
                smallestIndex = currentIndex;
            }
        }

        // 안쪽 반복 루프를 순회하고 나면, 출발점부터 각 요소들끼리 value 의 크기를 비교해서
        // 가장 작은 value 에 해당하는 index 가 smallestIndex 에 저장되어 있겠지?
        // 가장 작은 값을 찾았다면, 위에 알고리즘대로 출발점 요소와 가장 작은 value 에 해당하는 요소를 swapping 해줬었지?
        // std::swap() 으로도 가능하다고 했지?
        // std::swap(array[smallestIndex], array[startIndex]); 요렇게 사용해주는 것과 동일함!
        int temp = array[smallestIndex];
        array[smallestIndex] = array[startIndex];
        array[startIndex] = temp;

        printArray(array, length); // 이렇게 출발점 요소가 바뀔 때마다(즉, swap 이 일어날 때마다) 현재 변경된 array 상태를 출력해보면, 위 알고리즘에 정렬 과정과 똑같이 출력되는 걸 볼 수 있음!
    }

    return 0;
}