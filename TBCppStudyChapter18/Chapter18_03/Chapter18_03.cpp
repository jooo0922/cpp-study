#include <iostream>
#include <sstream> // string stream (문자열 스트림)

using namespace std;

int main()
{
    /* stringstream 에 문자열 삽입하기 */

    stringstream os;

    // insertion operator (문자열 삽입 연산자)
    /*
        참고로, << endl; 에 의한 줄바꿈도
        stringstream 에 저장됨.

        정확히 말하면,
        개행문자 '\n' 이 저장되는 것!
    */
    os << "Hello, World!" << endl;

    /*
        stringstream.str() 은 stringstream 에 저장된 문자열을
        매개변수로 전달받은 문자열로 '덮어씀'
    */
    //os.str("Hello, World!");

    // insertion operator 는 전달받은 문자열을 '덧붙임'
    os << "Hello, World!2";


    /* stringstream 에 삽입된 문자열 추출해오기 */ 

    string str;

    /*
        extraction operator(문자열 추출 연산자) 사용

        -> 띄어쓰기를 기준으로 문자열 추출을 구분하기 때문에, 
        띄어쓰기 이전의 문자열까지만 추출 가능함.
    */
    //os >> str;
    
    /*
        띄어쓰기 추출 구분 이슈를 해결하기 위해, 
        string stream 에 저장된 모든 문자열을

        stringstream.str() 을 통해
        std::string 으로 변환하여 할당
    */
    str = os.str();

    cout << str << endl;


    /* 공백을 기준으로 stringstream 삽입 및 추출 구분 */
    stringstream os2;

    // 공백을 기준으로 insertion operation 구분
    os2 << "1234 567.89";  

    string str1;
    string str2;

    // 공백을 기준으로 extraction operation 구분
    os2 >> str1 >> str2;

    cout << str1 << "|" << str2 << endl;


    /* stringstream 에 숫자 삽입 및 추출 */
    stringstream os3;
    
    int i = 12345;
    double d = 67.89;

    // 공백을 기준으로 삽입 연산 구분
    os3 << i << " " << d;

    int i2;
    double d2;

    // 공백을 기준으로 추출 연산 구분
    os3 >> i2 >> d2;

    cout << i2 << "|" << d2 << endl;
    
    return 0;
}