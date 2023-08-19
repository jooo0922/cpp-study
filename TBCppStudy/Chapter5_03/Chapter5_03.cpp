#include <iostream>

using namespace std;

// 클래스 열거형 Chapter4_8.cpp 참고
enum class Colors
{
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE
};

void printColorName(Colors color)
{
    // 이렇게 열거형을 하나하나 조건문으로 입력하기 번거롭지 않나? > 이럴 때 쓰는 게 switch-case 문!
    //if (color == Colors::BLACK)
    //    cout << "Black" << endl;
    //else if (color == Colors::WHITE)
    //    cout << "White" << endl;
    //else if (color == Colors::RED)
    //    cout << "Red" << endl;

    // switch 문의 파라미터가 열거형일 경우, 알아서 case 들을 자동완성 해줌!
    // 또는, 열거형을 다 입력하기 귀찮으면, 파라미터를 static_cast<int>(color) 로 해서
    // 열거형 타입을 정수형으로 변환하면, 각 case 들을 0, 1, 2, 3, 4, ... 이런 식으로 짧게 축약해서 작성 가능!
    switch (color)
    {
    case Colors::BLACK:
        cout << "Black" << endl;
        break;
    case Colors::WHITE:
        cout << "White" << endl;
        break;
    case Colors::RED:
        cout << "Red" << endl;
        break;
    case Colors::GREEN:
        cout << "Green" << endl;
        break;
    case Colors::BLUE:
        cout << "Blue" << endl;
        break;
    default:
        break;
    }
}

int main()
{
    //printColorName(Colors::BLACK);

    int x;
    cin >> x;

    //{
    //    switch (x)
    //    {
    //    case 0:
    //        cout << "Zero";
    //        break; // switch 문을 빠져나갈 때 사용. break 를 걸어주지 않으면 아래의 case 들을 모두 실행해버림.
    //    case 1:
    //        cout << "One";
    //        break;
    //    case 2:
    //        cout << "Two";
    //        break;
    //    }

    //    cout << endl; // 이거는 switch-case 문 중 하나가 실행되고 나서 출력된 라인을 종결짓는 것!
    //}

    {
        // 가급적 switch 문 안에서 사용할 변수가 있다면, switch 문 밖에서 먼저 선언 및 초기화를 해두고,
        // 해당 변수의 쓰임이 끝나면 OS 에 메모리를 반납할 수 있도록 블록 처리해서 감싸주는 식으로 작성하는 게 좋다!
        // 나아가서, 각 case 문도 block 으로 감싸주면 훨씬 더 좋음!
        // 이런 식으로, 변수 사용은 가급적 적은 범위(scope) 내에서 사용되도록 하는 게 좋다!
        int y = 0;

        switch (x)
        {
            //int a; // 변수 '선언'까지는 switch 문 block 안에서 가능
            //int b = 5; // 그러나, 선언된 변수의 값 '초기화'를 여기서 하면 빌드 에러 > case 문 다음에서부터 값을 할당 가능!
            case 0:
            {
                //a = 1;
                //cout << a << endl;
                //int y; // case 문에서도 변수 선언 가능.
                //y = 5;
                // 다만, 변수 초기화를 0번 case 문에서 하고 나서, 
                // 1번 case 문에서 y 변수를 출력하면 쓰레기값이 출력됨 
                // -> why? 처음부터 1번 케이스로 넘어가면 0번 케이스에서의 초기화는 이루어지지 않기 때문에,
                // 선언된 변수 y의 메모리 공간에 남아있던 쓰레기값만 출력되는 셈!

                int y = 5; // case 문을 블록으로 감쌌으니 동일한 이름의 변수를 추가 선언하는 것도 가능!
                y = y + x;
                cout << y << endl;
                break;
            }

            case 1:
            {
                //y = 5; // 그런데, 이전 case 문에서 선언된 변수에 값을 할당하는 것도 가능할까? > 가능함!

                int y = 5; // case 문을 블록으로 감쌌으니 동일한 이름의 변수를 추가 선언하는 것도 가능!
                y = y - x;
                cout << y << endl;
                break;
            }

            default: // case 문에 정의되지 않은 모든 경우에 대해서 기본으로 실행시켜주는 로직들
                cout << "Undefined input " << x << endl;
                //break; // default 문에 break 를 달아주는 경우도 있지만, default 문 밑에는 선언된 케이스들이 없으므로, break 를 달지 않아도 문제될 것 없음!
        }
    }

    return 0;
}
