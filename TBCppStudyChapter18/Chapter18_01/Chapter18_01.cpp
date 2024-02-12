#include <iostream>
#include <string>
#include <iomanip> // input / output manipulator

using namespace std;

int main()
{
    /* std::setw() 로 입력 스트림 버퍼의 값을 가져오기 */

    /*
        istream

        스트림은 기본적으로 
        내부에서 버퍼에 저장을 해두고,
        일부씩 꺼내오는 방식을 사용하고 있음.
    */
    char buf[5];

    /*
        여기서 문자열을 10개 넘게 콘솔 입력하면,
        할당된 메모리 버퍼보다 큰 입력 스트림이 들어오다 보니,
        runtime error 를 발생시킴.

        그런데, 입력하는 사용자가
        매번 10개 입력 제한을 생각해서 입력하기에는 번거로우니,
        
        iomanip 내부의 setw() ('set width'의 약자) 함수를 사용해서
        입력받아서 버퍼에 저장할 값의 크기를 제한할 수 있음!

        정확히 내부적인 작동 구조를 설명하자면,
        10글자 넘게 입력을 하더라도, 입력받은 내용이 전부
        cin 이 자체적으로 갖고 있는 입력 스트림 버퍼에 입력됨.

        이후, setw() 가
        종료문자('\0') 를 넣기 위한 1개의 자리를 제외한
        나머지 4개(5-1) 만 cin 의 입력 스트림 버퍼에서 가져온 뒤,
        char buf[5] 에 할당하는 것임!
    */
    cin >> setw(5) >> buf;

    cout << buf << endl;

    /*
        setw() 가 가져온 4개의 문자 이외의
        나머지 문자들은 모두 cin 의 입력 스트림 버퍼가 계속 갖고 있음.

        그래서, setw() 를 한 번 더 실행하면,
        나머지 문자들을 다시 가져와서 char buf[5] 에 할당하여 
        새롭게 가져온 문자들로 덮어쓸 수 있음!
    */
    cin >> setw(5) >> buf;

    cout << buf << endl;

    return 0;
}