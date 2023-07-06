#include <iostream>

using namespace std;

//int multiplyTwoNumbers(int num_a, int num_b) 
//{
//    int sum = num_a * num_b;
//
//    return sum;
//}

// 별도의 반환값이 없는 함수는 반환 타입을 void 로 지정한다. 
//void printHelloWorld()
//{
//    cout << "Hello World " << endl;
//
//    return; // 반환값이 void 인 경우, return; 만 넣어주는 것도 가능.
//
//    //cout << "Hello World 2 " << endl; // return 이후의 코드는 어떠한 경우에도 실행되지 않음. return 호출 이후 곧바로 main 함수 블록으로 돌아가기 때문! 
//}

void addTwoNumbers(int a, int b)
{
    //return a + b;
}

int main()
{
    // 함수는 아래와 같이 재사용이 가능하다!
    //cout << multiplyTwoNumbers(1, 2) << endl;
    //cout << multiplyTwoNumbers(3, 4) << endl;
    //cout << multiplyTwoNumbers(8, 13) << endl;

    //printHelloWorld();

    // 반환타입이 void 인 함수는 다른 변수에 할당하지만 않으면, 호출 시 별도 에러가 나지는 않음.
    //int sum = addTwoNumbers(1, 2); 
    addTwoNumbers(1, 2);

    return 0;
}