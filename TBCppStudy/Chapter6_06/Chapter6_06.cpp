#include <iostream>
#include <cstring> // 전통적인 c style 문자열을 사용할 때 필요한 함수들(strcpy() 등...) include

using namespace std;

int main()
{
    // c style 문자열 배열 > mouse over 시, char myString[7] 즉, 7개의 문자가 저장된 배열이라고 뜸.
    // 물론, string 은 6개 문자지만, 마지막에 종료문자 '\0'이 안보이게 들어가 있음! 
    // > 메모리 상에서 해당 문자열까지의 영역을 구분하는 용도! 
    //char myString[] = "string";

    //for (int i = 0; i < 7; ++i)
    //{
    //    // 아스키코드 (int) 로 형변환하여 출력하면, 마지막에 0(=종료문자 '\0') 이 출력되는 걸 알 수 있음.
    //    cout << (int)myString[i] << endl;
    //}

    //cout << sizeof(myString) / sizeof(myString[0]) << endl; // 문자열 전체 바이트 수 / 첫 글자 바이트 수 = 문자열 전체 개수 > 7개 출력

    // 문자열을 cin 으로 입력받기
    //char myString[255]; // 몇 글자가 들어올 지 모르니, 배열 사이즈를 충분히 크게 잡아놓음.

    //cin >> myString; // 런타임에 문자열이 입력될 때까지 이 라인에서 대기
    //cin.getline(myString, 255); // cin 대신 cin.getline() 으로 입력받으면, 띄어쓰기(공백)도 그대로 출력 가능!

    //myString[0] = 'A'; // 입력받은 문자열의 첫 번째 문자를 대문자 'A' 로 변경
    //myString[4] = '\0'; // 이번에는 다섯 번째 문자를 종료문자로 변경 > 네 번째 문자까지만 출력됨 > 문자열은 항상 종료문자까지만 출력된다는 점!

    //cout << myString << endl;

    // 반복문으로 문자열 안에 있는 문자들을 전부 출력해보기 (종료문자를 만날 때까지 출력)
    //int ix = 0;
    //while (true)
    //{
    //    if (myString[ix] == '\0') break; // 종료문자 만나면 반복문 탈출

    //    cout << myString[ix] << " " << (int)myString[ix] << endl; // 문자와 아스키코드 동시 출력
    //    ++ix;
    //}

    char source[] = "Copy this!";
    char dest[50];
    strcpy_s(dest, 50, source); // dest 문자열 배열에 source 문자열 배열 복사
    /*
        strcpy() 의 문제점

        dest 배열의 크기가 source 배열의 크기보다 작을 경우,
        dest 배열 메모리 안에 source 배열에 담긴 문자들을 모두 복사해놓을 수 없어
        메모리 침범이 발생함. 이로 인해, 운영체제에서 빌드 에러를 발생시킴.

        그래서, 아예 dest 배열의 크기를 두 번째 매개변수로
        전달하도록 strcpy_s() 함수를 강제로 사용하도록
        경고메시지를 출력하고 있음.

        _s 는 secured 의 약자겠지? 
        더 안전하게 배열을 복사할 수 있게 해준거니까! 
    */

    cout << source << endl;
    cout << dest << endl;

    return 0;
}