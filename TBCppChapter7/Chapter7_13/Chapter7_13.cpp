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


    // violated assumption (가정 위반)
    // 사용자가 내가 작성한 의도와 전혀 다른 방식으로 사용하는 경우 
    string hello = "Hello, my name is Jack Jack";

    // 우선 사용자에게 hello 의 마지막 인덱스까지의 숫자만 입력할 것을 요청함.
    cout << "Input from 0 to " << hello.size() - 1 << endl;

    // 만약 여기에 hello 문자열보다 긴 1004 같은 index 값이 사용자로부터 입력되면 런타임 에러가 발생하겠지!
    // 그래서, 이런 오류가 발생할 수 있는 것을 미리 방지하는 게 좋음! > 방어적 프로그래밍!
    // 아래와 같이 방어적 프로그래밍은 그냥 프로그래밍보다 손이 많이 가며, 
    // 출시할 때 모든 프로그램들은 아래와 같이 방어적 프로그래밍이 되어 있어야 한다!
    
    // 그 다음, 사용자가 잘못된 값을 입력하면 반복해서 입력을 받도록 while 문에서 스트림 입력을 구현함. 
    while (true)
    {
        int ix;
        cin >> ix;

        // 입력된 인덱스가 범위 내에서 유효한 값인지 검사함 -> 방어적 프로그래밍!
        if (ix >= 0 && ix <= hello.size() - 1)
        {
            // 유효한 값인 경우, 입력된 인덱스에 해당하는 문자를 출력하고 반복문 종료
            cout << hello[ix] << endl;
            break;
        }
        else
            cout << "Please try again" << endl; // 유효하지 않은 값이라면, 재입력을 요청하고 스트림 입력을 반복함!
    }

    return 0;
}