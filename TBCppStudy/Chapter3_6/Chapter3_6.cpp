#include <iostream>

int main()
{
    using namespace std;

    // logical NOT
    //bool x = true;
    // 
    //cout << !x << endl;

    // logical AND
    //bool x = true;
    //bool y = false;
    // 
    //cout << (x && y) << endl; // 연산자 우선순위가 맞지 않아 에러가 발생하므로, 논리연산을 괄호로 묶어주기

    // logical AND 사용 예제
    //bool hit = true;
    //int health = 10;

    //if (hit == true && health < 20)
    //{
    //    cout << "die" << endl;
    //}
    //else
    //{
    //    health -= 20;
    //}

    // logical OR
    //cout << (x || y) << endl;

    // != 같지 않음 여부를 판단하는 비교연산자
    //int intX = 5;
    //int intY = 7;

    //if (intX != intY)
    //{
    //    cout << "intX does not equal to intY" << endl;
    //}
    //else
    //{
    //    cout << "intX equals to intY" << endl;
    //}

    // logical OR 연산자를 사용한 조건문
    //int v = 1;

    //if (v == 0 || v == 1)
    //    cout << "v is 0 or 1" << endl;

    // short circuit evaluation
    //int x = 2;
    //int y = 2;

    //// && 연산자는 왼쪽 피연산자를 먼저 계산한 뒤, false 가 나오면 오른쪽 피연산자는 계산하지 않음
    //// 따라서, 아래 조건문은 x의 값에 따라 y++ 가 계산될 수도 있고 안될 수도 있음.
    //if (x == 1 && y++ == 2)
    //{
    //    // do something
    //}

    //cout << y << endl;

    bool x = true;
    bool y = false;

    // De Morgan 법칙
    // NOT 연산자는 분배법칙이 적용되지 않는다.
    // 1번 식의 NOT 연산자를 분배시킬 경우, 2번이 아닌 3번과 같이 해줘야 동일한 결과가 나온다.
    // 분배법칙을 적용하려면 && <-> || 논리연산자를 뒤집어줘야 함.
    !(x && y); // 1번
    !x && !y; // 2번 ... 1번 분배법칙 적용 x
    !x || !y; // 3번 ... 1번 분배법칙 적용 o

    // XOR
    // false false > false 가 나와야 함.
    // false true > true 가 나와야 함.
    // true false > true 가 나와야 함.
    // true true > false 가 나와야 함.
    // c++ 에서는 XOR 연산자가 별도로 존재하지 않으므로, != 을 대신 사용
    cout << (x != y) << endl;

    // test
    cout << ((true && true) || false) << endl; // true
    cout << ((false && true) || true) << endl; // true
    cout << ((true && true) || false || true) << endl; // true
    cout << ((14 > 13 || 2 > 1) && (9 > 1)) << endl; // true
    cout << (!(2314123 > 2 || 123123 > 2387)) << endl; // false

    bool v1 = true;
    bool v2 = false;
    bool v3 = false;

    // r1 과 r2 가 같을까 다를까?
    bool r1 = v1 || v2 && v3; // 얘는 마치 v1 || (v2 && v3) 인 것처럼 계산됨. 왜냐하면, && 가 || 보다 우선순위가 높기 때문!
    bool r2 = (v1 || v2) && v3;
    // 항상 이렇게 우선순위가 애매할 경우에는, 괄호로 먼저 계산해줘야 할 부분을 명시해주는 게 가장 마음이 편하고 가독성도 좋다!

    cout << r1 << endl;
    cout << r2 << endl;

    return 0;
}
