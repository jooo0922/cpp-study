#include <iostream>

using namespace std;

void countDown(int count)
{
    cout << count << endl;
    
    // 무한하게 재귀 호출이 발생하지 않도록, 종료 조건을 추가함.
    if (count > 0)
        countDown(count - 1); // 함수가 자기 자신을 호출하는 함수 > 재귀적 함수 호출
}

// 인자로 전달한 sumto 보다 작은 숫자들의 합을 재귀 호출로 계산
int sumTo(int sumto)
{
    if (sumto <= 0)
        return 0;
    else if (sumto <= 1)
        return 1;
    else
        return sumTo(sumto - 1) + sumto;
}

int main()
{
    //countDown(5);

    cout << sumTo(10) << endl;
    return 0;
}