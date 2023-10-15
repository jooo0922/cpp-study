#include <iostream>
#include <cstdarg> // ellipsis (...) 사용을 위해 포함

using namespace std;

/*
    Ellipsis

    들어오는 매개변수의 개수를 정해놓지 않고,
    함수 호출부에서 매번 원하는 개수만큼 전달하고 싶을 때 사용.

    아래 findAverage() 함수가 ellipsis (...) 을 사용하는 예시.

    일단 첫 번째 매개변수는 전달하려는 인자의 개수!
*/
double findAverage(int count, ...)
{
    double sum = 0;
    
    va_list list; // ellipsis 로 들어온 가변 인지 목록들이 자동으로 채워지는 변수

    va_start(list, count); // ellipsis 로 들어온 가변 인자 목록 처리 시작 함수. 이때, 가변 인자 목록 개수도 같이 전달해줘야 함.

    for (int arg = 0; arg < count; ++arg)
    {
        // 실제로 ellipsis 로 들어온 가변 인자 목록을 읽어들일 때에는 va_arg() 사용
        // 이때, 들어온 가변 인자들을 int 타입으로 형변환해서 읽어들이는 것!
        sum += va_arg(list, int);
    }

    va_end(list); // 가변 인자 목록 처리 종료 함수. 

    return sum / count; // count 개수만큼의 가변 인자들의 평균을 내서 반환
}

int main()
{
    return 0;
}