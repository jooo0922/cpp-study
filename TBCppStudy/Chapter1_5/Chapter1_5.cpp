#include <iostream>

using namespace std;

//int multiplyTwoNumbers(int num_a, int num_b) 
//{
//    int sum = num_a * num_b;
//
//    return sum;
//}

// 별도의 반환값이 없는 함수는 반환 타입을 void 로 지정한다. 
void printHelloWorld()
{
    cout << "Hello World " << endl;

    return; // 반환값이 void 인 경우, return; 만 넣어주는 것도 가능.

    //cout << "Hello World 2 " << endl; // return 이후의 코드는 어떠한 경우에도 실행되지 않음. return 호출 이후 곧바로 main 함수 블록으로 돌아가기 때문! 
}

int main()
{
    //cout << multiplyTwoNumbers(1, 2) << endl;
    //cout << multiplyTwoNumbers(3, 4) << endl;
    //cout << multiplyTwoNumbers(8, 13) << endl;

    printHelloWorld();

    return 0;
}