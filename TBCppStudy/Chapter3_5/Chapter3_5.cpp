#include <iostream>
#include <iomanip> // io manipulator 즉, 입출력 조작 관련 라이브러리 > 숫자를 몇째자리 수까지 출력할 것인지 옵션 조정 가능
#include <cmath>

int main()
{
    using namespace std;

    // 두 개의 숫자 입력 후 비교 로직 무한 반복
    //while (true)
    //{
    //    int x, y;
    //    cin >> x >> y; // cin 함수로 콘솔에서 2개의 값 입력받기
    //    cout << "Your input values are : " << x << " " << y << endl;

    //    // 입력받은 두 값 x, y가 서로 어떤 관계인지 확인
    //    if (x == y)
    //        cout << "equal" << endl;
    //    if (x != y)
    //        cout << "Not equal" << endl;
    //    if (x > y)
    //        cout << "x is greater than y" << endl;
    //    if (x < y)
    //        cout << "x is less than y" << endl;
    //    if (x >= y)
    //        cout << "x is greater than y or equal to y" << endl;
    //    if (x <= y)
    //        cout << "x is less than y or equal to y" << endl;
    //}

    // 실수(부동소수점) 간 관계 비교  
    double d1(100 - 99.99); // 0.01
    double d2(10 - 9.99);   // 0.01

    // 사람이 생각했을 때, d1 과 d2 는 같은 숫자로 보이지만,
    // 컴파일러는 두 값을 다르게 처리함.
    // 근데 아무런 처리 없이 두 값을 콘솔로 찍으면 똑같은 값이 나오므로,
    // iomanip 라이브러리 내의 setprecision() 함수로 소숫점 17번째 자리까지 출력하도록 설정해두면 두 값의 차이를 알 수 있음.
    //cout << setprecision(17);
    cout << d1 << endl; // 0.01
    cout << d2 << endl; // 0.01

    if (d1 == d2)
        cout << "equal" << endl;
    else
    {
        cout << "Not equal" << endl;

        if (d1 > d2) cout << "d1 > d2 " << endl;
        else cout << "d1 < d2" << endl; // if(d1 < d2) 와 같음. 위에서 == 동등비교연산을 한번 처리해줬으니까!
    }

    // 그렇다면, 두 값이 얼마나 다른지 확인하는 방법은?
    cout << std::abs(d1 - d2) << endl; // 5.32907e-15 > 즉, 5.32907 / 10^15 제곱으로, 아주 작은 값의 오차가 있음을 볼 수 있음.

    // 그렇다면, std::abs() 로 확인한 정도의 작은 오차 정도는 같은 값으로 쳐줬으면 좋겠다~ 라고 컴퓨터한테 명령하면 되겠지! > 이런 게 수치해석
    // 그러면 엡실론 값을 결정하는 기준이 뭔가? > 우리가 푸는 문제에 따라서 그때그때 다르다! 이런 것들이 엔지니어의 도메인 기본 지식...
    const double epsilon = 1e-10; // 1 / 10^10 제곱 정도의 오차

    if (std::abs(d1 - d2) < epsilon)
    {
        cout << "Approximately equal" << endl; // 오차가 epsilon 보다 작으면 대강 비슷하다!
    }
    else
    {
        cout << "Not equal" << endl; // epsilon 보다 오차가 크면 다르다!
    }

    return 0;
}
