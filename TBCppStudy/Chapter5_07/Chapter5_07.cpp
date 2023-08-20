#include <iostream>

// 거듭제곱 함수를 for 문으로 직접 구현
int pow(int base, int exponent)
{
    int result = 1;

    for (int count = 0; count < exponent; ++count)
    {
        result *= base;
    }

    return result;
}

int main()
{
    using namespace std;

    //for (int count = 0; count < 10; ++count) // iteration (하나의 반복 순회) > 그래서 보통 이것의 약자 i 를 for 문 제어 변수명으로 많이 씀.
    //{
    //    cout << count << endl;
    //}

    // cout << count << endl; // for 문을 빠져나오면 초기화된 제어 변수 count 는 메모리 해제됨.

    // 만약, count 변수를 for 문 바깥에서도 접근하고 싶다면,
    // for 문 바깥에서 count 변수를 선언 및 초기화하면 됨. > while 문이랑 구조가 거의 비슷해 짐.
    //int count = 0;
    //for (; count < 10; ++count)
    //{
    //    cout << count << endl;
    //}

    //cout << count << endl; // 여기서 찍어보면 for문의 증가연산자에 의해 남아있는 값 10 이 찍힘.

    // for 문으로 무한루프 돌리기
    //int count = 0;
    //for (; true; ++count) // 또는 true 생략해도 무한루프가 돌아감.
    //{
    //    cout << count << endl;
    //}
    
    //cout << pow(2, 4) << endl; // 구현한 거듭제곱 함수 테스트

    // count 를 감소시키는 for 문
    //for (int count = 9; count >= 0; count -= 2)
    //{
    //    cout << count << endl;
    //}

    // for 문 안에서 제어변수 두 개씩 사용하기
    //for (int i = 0, j = 0; (i + j) < 10; ++i, j += 2)
    //{
    //    cout << i << " " << j << endl;
    //}

    // 이중 for 문
    //for (int j = 1; j <= 9; ++j)
    //{
    //    for (int i = 1; i <= 9; ++i)
    //    {
    //        //cout << i << " " << j << endl;
    //        cout << j << " * " << i << " = " << j * i << endl; // 이중 for 문으로 구구단 출력하기
    //    }
    //}

    // unsinged int 타입은 음수 표현이 안되기 때문에, 의도치 않은 무한 루프를 생성함. > while 문 에서와 동일한 문제
    for (unsigned int i = 9; i >= 0; --i)
    {
        cout << i << endl;
    }

    return 0;
}
