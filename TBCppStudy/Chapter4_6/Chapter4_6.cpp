#include <iostream>
#include <string> // std::string 을 사용할 시, 이 라이브러리를 include 할 것!
#include <limits>

using namespace std;

int main()
{
    // c++ 기본 제공 문자 타입 char 는 한 글자를 담을 수 있는 변수 타입 > 해당 변수를 배열로 선언 시, 문자'열' 리터럴 할당 가능 > 이게 문자열 변수를 관리하는 가장 기본 방식!!
    const char my_strs[] = "Hello, World"; 

    // std::string 타입을 사용한 문자열 변수 > 프로그래머들이 문자열 변수를 편하게 다루라고 만들어놓은 '사용자 정의 자료형'
    const string my_hello = "Hello, World"; 
    //const string my_hello("Hello, World"); // 아래와 같은 방식으로도 할당 가능 
    //const string my_hello{ "Hello, World" };

    //string my_ID = 123; // 정수형 리터럴을 string 타입으로 암시적 형변환을 할 수는 없다! > 에러 발생!

    cout << my_hello << endl;

    cout << "Your age ? : ";
    int age;
    cin >> age; // 나이는 정수로 입력받고 싶어서, 다시 cin 으로 입력받도록 되돌렸더니, 이번에는 입력한 정수가 다음 std::getline() 의 입력값으로 넘어가버림!
    //std::getline(std::cin, age);

    // 정수값 cin 입력 시 발생한 이슈를 해결하는 cin.ignore()
    // 아래 코드가 무슨 의미냐면, '\n'이 올 때까지, 즉, 엔터를 치고 개행을 할 때까지 입력받았던
    // 최대 32767 개의 글자들을 무시해라. 잊어버려라. > 그러면, 다음 std::getline() 입력 시, 이전에 입력받았던 나이 정수는 무시되겠지?
    //std::cin.ignore(32767, '\n');

    // 그런데, 32767 글자 수 제한은 약간 매직 넘버(하드코딩) 이므로,
    // 아래와 같이 고칠 수 있다
    // 즉, std::streamsize (=long long) 의 최대 사이즈만큼의 글자들을 무시하라는 뜻!
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Your name ? : ";
    string name;
    //cin >> name; // cin 으로 입력받으면, space(즉, 띄어쓰기)를 입력으로 인식해서 다음 cin 으로 띄어쓰기 다음에 입력한 문자를 넘겨버리는 이슈가 있음
    std::getline(std::cin, name); // cin 의 문자열 입력 한계를 보완해주는 std::getline() 함수! > 엔터 키를 누르기 전까지의 해당 라인 단위를 모두 입력받도록 함!

    cout << name << " " << age << endl;

    // 문자열 더하기
    // 참고로, 문자열 변수 a에 마우스를 갖다대면, char[8] 이라고 나옴. 즉, 메모리에는 char 타입 메모리 8개가 할당되어 있다고 표시하는 것.
    // 왜 8개냐면, 마지막 1개는 문자열 종료를 알리는 종료 문자 null 이 숨어있기 때문!
    string a("Hello, ");
    string b("World");
    string hw = a + b; // append (문자열 뒤에 문자열을 더하는 개념) >> 이게 가능한 이유는, string 타입을 만든 프로그래머가 '+' 연산자를 라이브러리에 정의해놨기 때문!

    hw += " I'm good";

    cout << hw << endl;

    cout << a.length() << endl; // 7. 문자열 길이 측정(js 랑 비슷하네)

    return 0;
}