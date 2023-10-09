#include <iostream>
#include <string>

using namespace std;

int main()
{
    // syntax error (문법 에러)
    // 컴파일 시, 컴파일러가 자동으로 잡아주므로, 크게 걱정하지 않아도 됨.
    //int x

    // semantic errors (문맥 에러)
    int x;
    cin >> x;

    // 조건식의 등호 = 때문에, 5가 입력된 경우에도, "x is greater than 5" 가 출력됨.
    // 이럴 경우, 문법적 에러는 아니지만, 문맥상 5가 5보다 크다는 게 말이 안되니까 문맥 에러라고 봐야 함.
    // 자주 일어나는 실수이고, 코드를 작성한 프로그래머 본인이 아니면 고치기 힘듦.
    // 디버거를 사용해서 꼼꼼히 문맥 에러가 발생하지 않도록 신경써줄 것!
    if (x >= 5)
        cout << "x is greater than 5" << endl;

    return 0;
}