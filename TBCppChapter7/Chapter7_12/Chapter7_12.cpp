#include <iostream>

using namespace std;

void countDown(int count)
{
    cout << count << endl;
    
    // 무한하게 재귀 호출이 발생하지 않도록, 종료 조건을 추가함.
    if (count > 0)
        countDown(count - 1); // 함수가 자기 자신을 호출하는 함수 > 재귀적 함수 호출
}

int main()
{
    countDown(5);
    return 0;
}