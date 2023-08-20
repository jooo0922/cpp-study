#include <iostream>
#include <cmath> // sqrt() 사용을 위해 include

using namespace std;

int main()
{
    double x;

// 특정 조건일 경우, ~~로 가라(goto) 를 사용하는데,
// 이 때, goto 가 가리키는 지점을 책갈피처럼 표시할 때 사용하는 문법이 'label'
// label 의 이름은 아래와 같이 tryAgain 등 내가 원하는데로 이름을 지을 수도 있음.
tryAgain : // label

    cout << "Enter a non-negative number" << endl;
    cin >> x;

    if (x < 0.0)
    {
        // goto 는 기능상으로 보면 반복문의 원조(원형)이라고 볼 수 있지만,
        // 최근에는 for 문이나 do-while 문을 사용하는 경우가 많기 때문에, 자주 사용되는 문법은 아니다.
        goto tryAgain; // x 에 음수를 입력받을 경우, label 로 표시한 지점(책갈피) 로 돌아가라(goto) 라는 의미
    }

    cout << sqrt(x) << endl;

    return 0;
}