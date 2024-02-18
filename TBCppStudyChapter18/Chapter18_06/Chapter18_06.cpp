#include <iostream>
#include <fstream> // file stream 사용을 위해 포함
#include <string>
#include <cstdlib> // exit() 사용을 위해 포함
#include <sstream> // std::stringstream 사용을 위해 포함

using namespace std;

int main()
{
    // writing
    if (true)
    {
        // 파일 출력 스트림 std::ofstream 생성
        /*
            std::ofstream(std::string) 생성자는
            
            생성자 매개변수로 전달한 파일명이 존재하면, 
            해당 파일을 열어주고,

            존재하지 않으면, 
            해당 이름으로 파일을 직접 만든 뒤,
            파일을 열어주는 역할을 함.
        */
        ofstream ofs("my_first_file.dat");

        // 파일을 열 때에는, 아래와 같이 std::ofstream.open() 함수로 직접 파일 열기 명령을 호출할 수도 있음!
        //ofs.open("my_first_file.dat");

        /*
            파일 열기에 실패했다면,
            아래와 같이 경고를 띄울 수 있도록
            예외처리를 해놔야 안전하게 실행할 수 있음.

            특히 파일 입출력은
            이러한 예외처리를 신중하게 처리해놔야 함.
        */
        if (!ofs)
        {
            cerr << "Couldn't open file" << endl;
            exit(1);
        }

        /*
            다른 스트림 객체들처럼 
            << 출력 스트림 연산자를 이용해서

            열어둔 파일에 원하는 값을
            출력(write) 할 수 있음!

            참고로, 출력 스트림 연산자로
            열려있는 파일에 write 할 경우,
            텍스트 모드로 저장이 됨.
            즉, ASCII 포맷으로 저장됨.

            -> 따라서, 메모장에서 해당 파일을
            열어서 write 된 값을 확인해볼 수 있음!

            (참고로, 아래에서도 설명하겠지만,
            파일을 binary 모드로 write 할 때에는,
            std::ofstream.write() 멤버함수를 사용함.)
        */
        //ofs << "Line 1" << endl;
        //ofs << "Line 2" << endl;


        /*
            그러나, 게임같은 용량이 큰 프로그램의 파일을
            텍스트 모드, 즉, ASCII 포맷으로 저장하면,
            
            파일을 저장하는 데만 해도 매우 느리고,
            저장된 파일을 불러오는 것도 매우 느림.

            따라서, 실무에서는 일반적으로
            대부분의 파일들은 binary 포맷으로
            저장하는 경우가 많음!

            binary 로 저장할 때에는,
            말 그대로 이진수로 변환되어 저장되기 때문에,
            어떤 데이터가 어디까지 저장되어 있는지 알 수가 없음.

            따라서,
            어떤 데이터가 얼마만큼 몇 개가 저장되어 있는지
            미리 약속을 해서 알고 있어야 함.

            아래 예제와 같이,
            0 ~ 9 까지의 10개의 숫자를 저장하고자 한다면,
            
            맨 먼저 저장할 숫자들의 갯수가 10개라는 것을
            std::ofstream 에 맨 처음 write 해줘야 함.

            그리고 나서,
            파일을 std::ifstream 으로 파일을 읽어들일 때,
            맨 먼저 저장된 숫자가 몇 개인지부터 읽어들여서
            저장된 숫자의 갯수를 알고 있어야 binary 파일을 제대로 읽을 수 있음.

            즉, 파일을 '쓰는 사람'과 '읽는 사람'이 
            파일이 저장되는 방식에 대해 사전에 약속이 되어있어야 함!

            참고로,
            std::ofstream 에 binary(이진 데이터)를 write 할 때에는,
            std::ofstream.write() 멤버함수를 사용하면 됨.
        */
        // 먼저 binary 포맷으로 저장할 데이터의 갯수를 c-style 문자열(char*)로 캐스팅하여 입력
        const unsigned num_data = 10;
        ofs.write((char*)&num_data, sizeof(num_data));

        // 실제 10개의 데이터를 저장함
        for (int i = 0; i < num_data; i++)
        {
            ofs.write((char*)&i, sizeof(i));
        }

        /*
            파일 닫기 명령도 std::ofstream.close() 로 
            직접 실행할 수 있지만,

            대부분의 파일 입출력 작업은
            특정 block {} 내에서 수행하는 경우가 많으므로,
            
            해당 block 이 끝나면
            std::ofstream 도 메모리가 해제됨.

            이때, 소멸자 함수에서
            파일 닫기를 자동으로 실행하므로,
            굳이 파일 닫기 함수인 .close() 를 직접 실행할 필요는 없음!
        */
        //ofs.close();
    }

    // reading
    if (true)
    {
        /*
            입력 파일 스트림인 std::ifstream 생성하여
            원하는 파일을 열 수 있음!
        */
        ifstream ifs("my_first_file.dat");

        // 파일 열기에 실패했을 때의 예외 처리
        if (!ifs)
        {
            cerr << "Cannot open file" << endl;

            // 파일 열기에 실패할 경우, std::exit() 으로 프로그램을 강제 종료함.
            // (참고로, 가급적 exit() 은 예외처리 내에서만 사용하는 것을 권장한다고 함.)
            exit(1);
        }

        /*
            열려있는 파일을 읽어들일 때,
            
            입력 파일 스트림에 흘러들어온 값들을
            std::getline() 을 통해
            "\n" 를 기준으로 한 줄 단위로 읽어들임.

            읽어들인 각 문자열을
            std::string 문자열 변수에 저장해서 출력하고,

            입력 파일 스트림에서 더 이상 읽어들일 값이 없으면,
            while 문의 조건문이 false 가 뜨게 되어
            반복문이 종료됨.
        */
        /*while (ifs)
        {
            std::string str;
            getline(ifs, str);

            cout << str << endl;
        }*/

        /*
            입력 파일 스트림에서 
            binary 데이터를 읽어들이려면,

            std::ifstream.read() 멤버함수를 사용함.

            이때, std::ofstream.write() 으로 작성한
            'write 한 데이터의 갯수'를 먼저 읽어옴.

            즉, '바이너리를 읽기 위한 서로간의 약속, 규칙'을
            먼저 확인하는 것임.
        */
        
        // 읽어들일 데이터 갯수를 먼저 확인함.
        unsigned num_data = 0;
        ifs.read((char*)&num_data, sizeof(num_data));

        // 위에서 확인한 데이터 갯수만큼 실제 binary 데이터를 읽어들임
        for (unsigned i = 0; i < num_data; i++)
        {
            int num;
            ifs.read((char*)&num, sizeof(num));

            std::cout << num << endl;
        }
    }

    return 0;
}
