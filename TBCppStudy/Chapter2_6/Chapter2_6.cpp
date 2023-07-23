#include <iostream>

// 숫자 두 개가 같은지 비교하는 함수
bool isEqual(int a, int b)
{
    bool result = (a == b); // a와 b 가 같으면 true, 다르면 false 로 평가됨.
    
    return result;
}

// 입력받은 숫자가 홀수인지 판단하는 함수
bool isOdd(int num)
{
    bool result = (num % 2 == 1);

    return result;
}

int main()
{
    using namespace std;

    // boolean 타입 변수 초기화
    bool b1 = true; // copy initialization
    bool b2(false); // direct '''
    bool b3{ true }; // uniform '''
    b3 = false; // 할당도 가능

    // boolean 타입은 메모리에 0 또는 1 로 저장됨.
    //cout << std::boolalpha; // 이렇게 하면 콘솔 출력 시, boolean 타입 변수의 값이 true / false 로 나옴
    cout << std::noboolalpha; // 반대로 이거는 콘솔 출력 시, boolean 타입 변수의 값이 1 / 0 으로 나옴
    cout << b3 << endl; // 0 (false)
    cout << b1 << endl; // 1 (true)

    // 버그가 생기면 찾기 힘들어서 ! 연산자는 가급적 안쓰는 편이라 함.
    cout << !b1 << endl; // NOT Operator > !true = false 가 됨
    cout << !b2 << endl; // NOT Operator > !false = true 가 됨

    // 논리연산자
    // &&(and) 연산자는 왼쪽과 오른쪽의 조건문이 모두 true 일 때에만 true 를 반환
    cout << (true && true) << endl;
    cout << (true && false) << endl;
    cout << (false && true) << endl;
    cout << (false && false) << endl;

    // ||(or) 연산자는 왼쪽과 오른쪽 둘 중 하나만 true 여도 true 반환
    cout << (true || true) << endl;
    cout << (true || false) << endl;
    cout << (false || true) << endl;
    cout << (false || false) << endl;

    // if 문
    // 괄호 안의 코드를 조건에 따라 실행시킬지 결정 > 조건은 괄호 안의 bool 타입에 의해 결정
    // 실행시키고 싶은 코드가 1줄이면 중괄호를 생략할 수 있음.
    if (3 > 1) 
    {
        cout << "This is true" << endl;
        cout << "true second line" << endl;
    }
    else
    {
        cout << "This is false" << endl;
    }

    cout << std::boolalpha;
    cout << isEqual(1, 1) << endl;
    cout << isEqual(0, 3) << endl;

    // if 조건문에 숫자를 넣는 경우
    /*
        if 문은 0이 들어가면 false 로 평가되고,
        나머지는 다 true 로 평가됨.
    */
    if (0)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    // boolean 타입을 입력으로 받을 경우
    // boolean 은 메모리에서 0 또는 1로 저장되기 때문에, 입력 시에도 0 또는 1로 입력해줘야 정상적으로 결과가 출력됨.
    bool b;
    cin >> b;
    cout << std::boolalpha;
    cout << "Your input : " << b << endl;

    cout << "1 is Odd ? " << isOdd(1) << endl; // true (홀수)
    cout << "2 is Odd ? " << isOdd(2) << endl; // false (짝수)
    cout << "3 is Odd ? " << isOdd(3) << endl; // true
    cout << "4 is Odd ? " << isOdd(4) << endl; // false

    return 0;
}
