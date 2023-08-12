#include <iostream>
#include <string>

// 공격받은 데미지 계산 함수
int computeDamage(int weapon_id)
{
    // 어떤 무기로 맞았느냐에 따라 데미지가 달라지도록 구현
    // 일단, 지금까지 배운 자료형 중에서, 무기를 구분하는 자료형으로 가장 적합한 건 정수형이니
    // 정수형으로 일단 만들어보자
    if (weapon_id == 0) // sword
    {
        return 1;
    }

    if (weapon_id == 1) // hammer 
    {
        return 2;
    }

    // ...

    // 그런데, 위와 같이 정수형으로 무기를 구별하면,
    // 어떤 무기의 정수값은 무엇인지 구별하고 인식하기 어려움.

    // 이런 무기들을 아무 의미없는 정수값보다는, '기호적으로' 표현할 수 있는 방법은 없을까?
    // 이걸 위해서 사용하는 게 '열거형(enum)'
}

// 색상을 기호적으로 표현하는 enum 을 정의해보자!
// 이런 것도 일종의 사용자 정의 자료형(user-defined data type)
// 아래와 같이 각 열거형에 마우스를 갖다대면 0, 1, 2, ... 이런 식으로 
// 각 열거형 기호에 할당된 정수값이 뜨는 것을 볼 수 있음.
//enum Color
//{
//    COLOR_BLACK = -3, // 열거형에 할당되는 정수값을 바꿀 수 있음. 이럴 경우, 다음 열거형에는 차례대로 +1 씩 올려서 정수값을 할당해 줌.
//    COLOR_RED,
//    COLOR_BLUE = 5,
//    COLOR_GREEN = 5, // 두 열거형에 동일한 정수값을 수동으로 할당할 경우, 열거형이 구별이 안되므로 문제가 발생!!
//    COLOR_SKYBLUE, // 열거형을 추가해야 할 경우가 있으므로, 마지막 열거형에도 편의상 쉼표(,)를 달아두는 게 편하다!
//}; // 열거형은 중괄호 뒤에 세미콜론(;) 을 반드시 붙여줘야 에러가 안남!

enum Color
{
    COLOR_BLACK,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_SKYBLUE,
};

enum Feeling
{
    HAPPY,
    JOY,
    TIRED,
    BLUE, // 만약 Color 열거형에도 COLOR_BLUE 를 BLUE 로 정의해놨다면, 두 개의 열거형이 redefinition 에러가 발생! > 가급적 prefix(접두어)를 붙여서 구분해주는 게 좋음!
};

int main()
{
    using namespace std;

    // 다른 변수형들 처럼 3 가지 방식으로 할당 가능
    Color paint = COLOR_BLACK;
    Color house(COLOR_BLUE);
    Color apple(COLOR_RED);

    Color my_color = COLOR_RED;

    cout << my_color << " " << COLOR_RED << endl; // 콘솔로 출력하면 각 열거형에 대응되는 정수값이 나옴

    // 두 열거형에 동일한 정수값을 수동으로 할당할 경우, 열거형이 구별이 안되므로 문제가 발생!! > 권장 x
    if (COLOR_BLUE == COLOR_GREEN)
    {
        cout << "Equal" << endl;
    }

    int color_id = COLOR_RED; // enum 은 내부적으로 정수 리터럴로 저장되므로, 정수값처럼 다룰 수는 있다!

    //Color my_col = 3; // 다만, enum 타입으로 선언한 변수에 실제 정수 리터럴을 할당하는 건 불가능하다. > 애초에 정수 리터럴이 아닌, '기호적'으로 구분하려고 만든 게 enum 이니까!
    Color my_col = static_cast<Color>(3); // 대신 명시적으로 형변환(캐스팅)하는 것은 가능!

    cout << color_id << endl;

    //cin >> my_col; // 안타깝게도, cin 으로 enum 타입을 직접 입력받는 건 불가능함!

    // 다만, 아래와 같이 정수형으로 cin 입력을 받은 후,
    // 해당 정수형과 맵핑되는 enum 을 원하는 변수에 할당하는 것은 가능하다! > '우회적' 입력 방식!
    int in_number;
    cin >> in_number;

    //if (in_number == 0) my_col = COLOR_BLACK;
    if (in_number == static_cast<Color>(0)) my_col = static_cast<Color>(0); // 이렇게 우회적 입력방식을 사용할 때, enum 의 강제 형변환 사용 가능!
    // ...

    // 문자열로도 enum 을 우회적으로 입력받을 수 있지 않을까?
    string str_input;
    std::getline(cin, str_input);

    // 가능은 하지만, 이렇게 조건문을 작성할 때, 프로그래머도 사람이기 때문에
    // enum 문자열 입력 시 오타가 날 우려가 있어서 오히려 권장되지 않음!
    if (str_input == "COLOR_BLACK") my_col = static_cast<Color>(0);

    return 0;
}