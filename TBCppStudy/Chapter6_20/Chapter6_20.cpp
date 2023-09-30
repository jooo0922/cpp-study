#include <iostream>
#include <array> // 정적 배열 라이브러리 std::array 를 사용하기 위해 라이브러리 추가
#include <algorithm> // 배열 정렬 알고리즘 사용을 위해 라이브러리 추가

using namespace std;

/*
    std::array 를 함수의 매개변수로 사용한다고 하더라도,
    결국 배열의 요소들이 새롭게 선언된 매개변수로 '복사'되어 들어가기 때문에,

    크기가 아주 큰 배열의 경우 복사하는 과정에서 성능저하가 발생할 것임!

    따라서, 배열을 참조 변수 또는 포인터 변수로 선언하면,
    배열의 요소가 복사되는 것이 아니라, 원본 배열을 참조할 수 있는 주소값을 전달받으므로,
    성능 측면에서 훨씬 용이함.
    (관련 내용 https://github.com/jooo0922/cpp-study/blob/main/TBCppStudy/Chapter6_14/Chapter6_14.cpp 참고)

    이때, 원본 배열의 값 변경을 방지해야 할 경우,
    참조변수에 const 만 붙여주면 됨!
*/
//void printLength(std::array<int, 5> my_arr)
void printLength(const std::array<int, 5>& my_arr)
{
    // 일반 배열은 매개변수로 전달하면, 그 배열이 저장된 메모리 공간을 가리키는 주소값만 복사된 '포인터 변수'로 선언된 것이기 때문에,
    // sizeof(일반 배열 매개변수) 로 크기를 측정하면 배열의 크기가 아닌 포인터 변수의 메모리 크기인 4 bytes 가 출력됬었지?
    // (해당 내용은 https://github.com/jooo0922/cpp-study/blob/main/TBCppStudy/Chapter5_12/Chapter5_12.cpp 참고!)
    // 반면, std::array 를 매개변수로 전달하면, .size() 메서드를 통해 원본 배열의 크기를 그대로 확인할 수 있음!
    cout << my_arr.size() << endl;
}

int main()
{
    // 일반적인 배열 생성 방법
    int array[5] = { 1, 2, 3, 4, 5 }; 

    // std::array 를 사용한 배열 생성 방법
    // 이때, 꺽쇠 안에 배열의 크기(여기서는 5)를 반드시 넣어줘야 함.
    // 일반 배열은 [] 안에 배열 크기를 넣어주지 않아도 자동으로 배열의 크기를 계산해줬지만,
    // std::array 는 반드시 넣어줘야 함. 그것 외에는 일반적인 배열로 할 수 있는 모든 걸 처리할 수 있음! 
    // 특히, 함수 파라미터로 넘길 때에는 일반 배열보다 훨씬 편함! 
    // > 왜냐? std::array 는 일반 배열을 클래스 형태로 한 번 감싸준 형태이기 때문에!
    std::array<int, 5> my_arr = { 1, 21, 3, 40, 5 }; 
    
    // 초기에 설정한 배열 크기 이하로 '재할당'도 가능함
    //my_arr = { 0, 1, 2, 3, 4 };
    //my_arr = { 0, 1, 2 };

    // std::array 의 요소를 for-each 문으로 순회하기
    // 각 요소를 전달받는 변수를 참조변수로 설정하면, 각 요소의 값이 복사되지 않아 더 빠르게 순회하겠지!
    for (auto &element : my_arr)
    {
        cout << element << " ";
    }
    cout << endl;

    // sort() 같은 정렬 라이브러리를 사용해서 std::array 요소를 정렬할수도 있음.
    //std::sort(my_arr.begin(), my_arr.end());
    
    // std::array 의 .rbegin(), .rend() 를 사용하여 역순(내림차순) 정렬도 가능함
    std::sort(my_arr.rbegin(), my_arr.rend());

    // 정렬된 std::array 확인
    for (auto& element : my_arr)
    {
        cout << element << " ";
    }
    cout << endl;

    // 배열 요소 접근 시, 인덱스도 사용 가능하지만,
    // std::array 는 .at() 이라는 메서드로도 배열 요소 접근 가능
    // 차이점이 있다면, .at() 은 매개변수로 넘겨준 인덱스 값이 배열 크기를 넘는지 한 번 검사를 함!
    // 이 검사로 인한 약간의 성능 차이가 있기 때문에, 성능이 중요한 프로그램은 당연히 my_arr[idx] 를 쓰는 게 낫겠지!
    cout << my_arr[0] << endl;
    cout << my_arr.at(0) << endl;

    // .size() 메서드로 배열 크기를 확인할 수도 있음.
    cout << my_arr.size() << endl;

    return 0;
}