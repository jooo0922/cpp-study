#include <iostream>
#include <string> // std::string 문자열 자료구조를 사용하기 위해 포함

using namespace std;

/*
    모든 실행 프로그램의 entry point 함수인 main() 에는
    어떤 인자를 넣어줄 수 있을까?

    OS 가 main() 에 인자를 넣어줄 때는,
    2개의 인자를 전달할 수 있도록 함.

    첫 번째 매개변수 argc 는 명령줄 인수의 개수,
    두 번째 매개변수 argv 는 명령줄에서 입력한 인수들이 담긴 문자열 배열

    즉, 터미널이나 명령 프롬프트 ("x86 Native Tools Command Prompt for VS 2019" 사용 권장)
    에서 빌드된 실행파일 이름을 입력한 후,
    그 뒤에 여러 문자나 숫자 등을 터미널 명령줄에 차례대로 입력하면,

    아래와 같이 main() 함수에서 각 명령줄에 입력한 문자들을
    argv 매개변수로 받아서 출력할 수 있음!

    이때, 터미널에 명령줄 인수들을 입력하기 귀찮다면,
    Solution Explorer > 현재 프로젝트 우클릭 > Properties > Configuration Properties > Debugging > Command Arguments
    에서 원하는 명령줄 인수들을 직접 입력해줄 수 있음!
*/
int main(int argc, char* argv[])
{
    // main() 에서 매개변수로 전달받는 명령줄 인수들을 출력해보자
    for(int count = 0; count < argc; ++count)
    {
        std::string argv_single = argv[count];
     
        // count == 0, 즉, 맨 첫 번째 명령줄 인수는 항상 실행파일 이름으로 고정되어 있음!
        // 두 번째 명령줄 인수 (1024, 즉 숫자 형태의 문자열)를 실제 숫자로 변환해서 사용하는 것도 가능! 
        if (count == 1) // 1024
        {
            /*
                std::stoi() (string to int)
                함수를 사용하면 std::string 타입의 문자열을
                정수로 바꿔서 사용할 수 있음!
            */
            int input_number = std::stoi(argv_single);
            cout << input_number + 1 << endl; // 정수이니 계산이 가능하다는 걸 확인하기 위해서 1을 더해서 출력해보자
        }
        else
        {
            cout << argv_single << endl;
        }
    }

    return 0;
}