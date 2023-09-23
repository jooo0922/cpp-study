#include <iostream>
#include <limits> // numeric_limits<> 관련 함수(상수?)를 사용하기 위해 포함
#include <algorithm> // max() 함수를 사용하기 위해 포함

using namespace std;

int main()
{
    int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    
    // for-each 문으로 배열 요소 순회하며 값 변경하기
    // 이때, 각 요소를 의미하는 number 변수를 일반 변수로 선언하면,
    // 함수 매개변수 선언하는 것과 마찬가지로, 내부 블록에서 값을 바꾸더라도, 원본 배열을 변경시키지 못함!
    // 따라서, number 변수를 참조변수로 선언해야 원본 배열을 변경시킬 수 있을 것임!
    //for (int number : fibonacci)
    //for (int& number : fibonacci)
    for (auto& number : fibonacci) // 좀 더 많이 사용되는 방식으로는, 왼쪽과 같이 배열 요소에 대한 자동 타입 추론을 위해 auto 를 사용하는 경우가 많음!
        number *= 10;


    // for-each 문으로 배열 순회하기
    // 배열의 각 요소를 출력하기
    // 배열 요소 '출력'만 담당하므로, 내부 블록에서 값을 변경시키지 않도록 const 참조변수로 선언
    for (const auto& number : fibonacci)
        cout << number << " ";

    cout << endl;

    int max_number = numeric_limits<int>::lowest(); // int 타입 데이터로 표현할 수 있는 최솟값을 반환함.

    for (const auto& n : fibonacci)
        // 표현할 수 있는 가장 작은 int 타입 정수값과 배열 안의 정수값들을 비교해가면서
        // 더 큰 정수값을 계속 덮어씀 > 반복문 순회가 끝나면 가장 큰 정수값이 들어있게 되겠지!
        max_number = max(max_number, n); 

    cout << max_number << endl;

    return 0;
}