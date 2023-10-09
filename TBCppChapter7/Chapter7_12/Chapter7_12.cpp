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

// 피보나치 수열을 재귀 호출로 출력하는 함수
void printFibonacci(unsigned int firstTerm, unsigned int secoundTerm)
{
    unsigned int nextTerm = firstTerm + secoundTerm; // 수열의 다음 항을 앞 두 항의 합으로 계산
    cout << firstTerm << endl; // 앞 두 항에서 첫째 항만 출력

    // 메모리 크기 한계 상, 수열의 항이 100,000 을 넘어가면 재귀호출하지 않도록 함. 
    if (nextTerm < 100000)
        printFibonacci(secoundTerm, nextTerm); // 둘째 항과 다음 항을 인자로 넘겨서 재귀호출
}

int main()
{
    //countDown(5);

    //cout << sumTo(10) << endl;

    printFibonacci(0, 1);

    return 0;
}