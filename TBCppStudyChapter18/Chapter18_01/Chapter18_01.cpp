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
    //char buf[5];

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
    //cin >> setw(5) >> buf;
    //cout << buf << endl;

    /*
        setw() 가 가져온 4개의 문자 이외의
        나머지 문자들은 모두 cin 의 입력 스트림 버퍼가 계속 갖고 있음.

        그래서, setw() 를 한 번 더 실행하면,
        나머지 문자들을 다시 가져와서 char buf[5] 에 할당하여 
        새롭게 가져온 문자들로 덮어쓸 수 있음!
    */
    //cin >> setw(5) >> buf;
    //cout << buf << endl;


    /* std::cin.get() 으로 입력 스트림 버퍼에서 가져오기 */
    //char ch[5];

    /*
        cin >> ch 로 입력값을 스트림 버퍼에 받게 되면,
        띄어쓰기를 기준으로 입력을 구분하게 되다 보니.
        띄어쓰기 자체를 공백 문자로 입력받지 못하게 됨.

        이럴 때에는 아래와 같이 
        std::cin.get() 을 사용하여 입력받으면,
        띄어쓰기도 공백문자로 입력받을 수 있게 됨!

        이때, cin.get(char* buf, std::streamsize count) 의
        두 번째 매개변수 count 에 입력 스트림 버퍼로부터
        몇 개의 문자까지 가져올 것인지 설정할 수 있음.

        -> 당연히 종료문자('\0')이 들어갈 자리를 제외하고 가져올 것임!
    */
    //cin >> ch;
    //cin.get(ch, 5);

    // std::cin.get() 으로 몇 글자를 읽어들였는지 반환해주는 함수 ('get count' 의 약자겠지?)
    //cout << cin.gcount() << " " << ch << endl;


    /* std::cin.getline() 으로 입력 스트림 버퍼에서 줄 단위로 가져오기 */

    //char buf[100];

    //cin.getline(buf, 100);

    /*
        std::cin.getline() 은 줄바꿈 문자 '\n' 까지
        같이 읽어들이기 때문에,

        입력 스트림 버퍼에서 가져온 글자의 갯수를
        std::cin.gcount() 로 출력해보면
        실제 글자 수보다 +1 만큼 더 출력해줌!
    */
    //cout << cin.gcount() << " " << buf << endl;


    /* std::string 타입의 버퍼에 입력값을 할당하기 */
    //string buf;

    // char* 정적 배열과 달리, std::getline() 을 직접 호출해주고, 
    // cin 과 std::string 버퍼를 매개변수로 전달해줘야 함.
    //getline(cin, buf);
    //cout << buf << endl;


    /* std::cin.ignore() 로 n 개의 입력값을 무시하고 읽어들이기 */

    //char buf[1024];

    //cin.ignore(2);

    //cin >> buf;
    //cout << buf << endl;


    /* std::cin.peek() 으로 스트림 버퍼에서 꺼내올 입력값을 들여다보기 */
    /*
        std::cin.peek() 은
        입력 스트림 버퍼에서
        직접 입력값을 꺼내오는 것이 아닌,

        입력 스트림 버퍼를 살짝 들여다봐서
        맨 먼저 꺼내올 입력값이 뭔지 미리보기로 알려주는 기능!
    */
    //char buf[1024];
    //cout << (char)cin.peek() << endl;

    //cin >> buf;
    //cout << buf << endl;


    /* std::cin.unget() 으로 마지막에 스트림 버퍼로부터 읽은 입력값을 다시 스트림 버퍼에 집어넣기 */
    //char buf[1024];

    //cin >> buf;
    //cout << buf << endl;

    //// 여기서 입력 스트림 버퍼에 마지막 입력값을 다시 집어넣음
    //cin.unget(); 

    //cin >> buf;

    //// 여기서 cin.unget() 으로 다시 집어넣은 입력값만 출력됨.
    //cout << buf << endl;

    /* std::cin.putback() 으로 비어있는 입력 스트림 버퍼에 원하는 문자를 다시 집어넣기 */
    char buf[1024];

    cin >> buf;
    cout << buf << endl;

    // 여기서 비어있는 입력 스트림 버퍼에 원하는 문자 'A' 를 다시 집어넣음
    cin.putback('A');

    cin >> buf;

    // 여기서 cin.unget() 으로 다시 집어넣은 입력값만 출력됨.
    cout << buf << endl;


    return 0;
}