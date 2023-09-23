#include <iostream>

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

    return 0;
}