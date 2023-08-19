#include <iostream>

using namespace std;

int min(int x, int y)
{
    if (x > y)  
        return y;
    else        
        return x;

    // 위 조건문을 삼항 연산자로 간략화할 수 있음
    //return (x > y) ? y : x;
}

int main()
{
    //int x, y;
    //cin >> x >> y;

    int x;
    cin >> x;

    //if (x > 10)
    //{
    //    // 조건문의 실행 내용이 2줄 이상이면 반드시 block 으로 감싸줄 것!
    //    cout << x << " is greater than 10" << endl;
    //    cout << "Test 1" << endl;
    //}
    //else
    //{
    //    cout << x << " is not greater than 10" << endl;
    //    cout << "Test 1" << endl;
    //}

    // 조건식이 숫자일 때, 0 이 아니면 암묵적으로 true 로 판별
    //if (1)
    //{
    //    int x = 5; // 조건문 블록 안에서 선언한 변수의 생명주기는 해당 조건문 블록을 벗어나면 끝남.
    //    // ...
    //}

    // 조건문 chaining
    // 참고로, 특별한 경우가 아니면 중첩 if-else 문은 논리구조 파악이 어려워 비권장 > 가급적 else if 로 사용할 것!
    //if (x > 10)
    //    cout << "x is greater than 10" << endl;
    //else if (x < 10)
    //    cout << "x is less than 10" << endl;
    //else // if (x == 10)
    //    cout << "x is exactly 10" << endl;

    // 중첩 조건문에서 헷갈릴 수 있는 부분
    // else 문은 indenting 칸 수에 관계없이 무조건 안쪽 if 문과 붙는다
    // 이런 걸 헷갈리기 싫으면 조건문은 가급적 블록으로 구분해줄 것!
    //if (x > 10)
    //    if (x <= 20)
    //        cout << "x is between 10 and 20 " << endl;
    //    else
    //        cout << "..." << endl;

    // 논리연산자로 조건문 연결
    //if (x > 0 && y > 0)
    //    cout << "both numbers are positive" << endl;
    //else if (x > 0 || y > 0)
    //    cout << "one of the numbers is positive" << endl;
    //else
    //    cout << "Neither number is positive" << endl;

    //if (x > 10)
    //    cout << "A" << endl;
    //else if (x == -1)
    //    return 0; // 어떠한 경우에 프로그램(함수)를 긴급하게 중단시킬 경우에도 사용 가능 (exit(0) 과 동일)
    //else if (x < 0)
    //    cout << "B" << endl;

    //cout << "Hello" << endl;

    // null statement > 그냥 if block 을 쳐 놓고, 그 안에서 아무것도 안하는 것과 동일함.
    //if (x > 10)
    //    ;           // ... (왜 null statement 를 쓴 건지 주석으로 정리해두는 게 좋음.)

    // 이렇게 조건문 옆에 null statement 가 딱 붙어있을 경우,
    // 조건문 여부와 관계 없이, 실제 block 은 분리되어서, x = 1; 이 작성된 block 이 항상 실행되어버림.
    // 반면, 조건문은 null statement 가 되어버리고... -> if문의 원래 의도와 정반대가 되어버리는 셈
    //if (x > 10);
    //{
    //    x = 1;
    //}

    // 대입 연산자와 동등비교 연산자를 헷갈리지 않게 주의...
    // 이럴 경우, x = 0 을 대입한 상태에서, if (0) 으로 조건문을 판단하게 되는 꼴...
    if (x = 0) // if ( x == 0 ) 
        cout << x << endl;
    
    cout << x << endl; // 실제 x 에는 0이 할당되어 0으로 출력됨.


    return 0;
}