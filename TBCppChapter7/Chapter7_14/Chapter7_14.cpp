#include <cassert> // 컴파일러를 활용한 디버깅에 assert() 사용을 위해 포함
#include <array> // 정적 배열 std::array 사용을 위해 포함
#include <iostream>

using namespace std;

/*
    정적 배열과 해당 배열을 검색할 인덱스를 입력 매개변수(= const 참조변수)로 전달받은 뒤,
    인덱스에 해당하는 배열의 요소를 출력하는 함수
*/
void printValue(const std::array<int, 5>& my_array, const int& ix)
{
    // 이때, ix 입력 매개변수에 my_array 범위를 벗어난 값이 들어올 경우,
    // 이에 대해 명시적으로 에러를 출력하면 디버깅이 더 쉬울테니, 이럴 때 assert() 를 사용하기 좋음
    // 이처럼, assert() 는 런타임에 사용하기 좋은 디버깅 도구라고 볼 수 있음.
    // 런타임에 사용자가 지정된 범위 외의 입력값을 넣어줄 경우, 이런 식으로 에러를 출력하여 디버깅할 수 있으니까!
    assert(ix >= 0);
    assert(ix <= my_array.size() - 1);

    cout << my_array[ix] << endl;
}

int main()
{
    int number = 5;

    // 프로그램 빌드 후 실행, 또는 디버기 실행 시, 이 부분에서 특정 조건을 검사하고, 
    // 해당 조건이 잘못되었으면 이 부분에서 에러가 발생했다고 출력함! 
    // -> 콘솔로 직접 찍어보는 것보다 디버깅에 훨씬 용이함!
    // 참고로 assert() 는 Debug 로 빌드한 실행파일에서만 사용 가능하고, Release 빌드는 실행 x
    // Release 모드에서는 가급적 프로그램이 빠르게 돌아가야 하므로, assert() 같은 디버깅 로직은 빼버리고 실행함!
    assert(number == 5);

    std::array<int, 5> my_array{ 1, 2, 3, 4, 5 };

    //printValue(my_array, 100);

    
    /* static assert */
    /*
        static assert 는 그냥 assert 와 달리,
        '컴파일 타임'에 에러를 표시할 수 있는 디버깅 툴!

        그래서, 컴파일 타임 이후, 런타임에 값이 변경될 수 있는
        일반 변수의 경우, static_assert() 로 검사할 수 없음.

        오로지 const 변수를 사용해야만
        런타임에 값이 변경되지 않으므로,
        컴파일 타임에 에러를 검사하는 static_assert 는
        const 변수를 사용해야만 함.
    */
    //int x = 5;
    const int x = 10;

    // 추가로, static_assert() 는 두 번째 인자로 에러가 출력될 때 어떤 문구를 같이 전달하여 출력할 수 있음.
    // 그래서 이것은 실행파일을 실행하기 전 단계, 
    // 즉, 빌드 단계와 컴파일 단계에서 하단의 Output 창에 표시할 수 있는 에러라고 보면 됨!
    static_assert(x == 5, "x should be 5");

    return 0;
}