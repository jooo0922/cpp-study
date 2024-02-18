#include <iostream>
#include <fstream> // 파일 스트림 사용을 위해 포함
#include <string>
#include <cstdlib> // exit() 사용을 위해 포함
#include <sstream> // 문자열 스트림 사용을 위해 포함

using namespace std;

int main()
{
    // 파일 이름 선언
    const string filename = "my_file.txt";

    // 파일 출력 스트림으로 파일 생성
    {
        ofstream ofs(filename);

        // 'a' ~ 'z' 까지의 문자 리터럴을 파일 출력 스트림에 흘려보냄.
        for (char i = 'a'; i <= 'z'; i++)
        {
            ofs << i;
        }
        ofs << endl;
    }

    // 파일 입력 스트림으로 파일 읽기
    {
        ifstream ifs(filename);

        /*
            std::ifstream.seekg(n)

            파일 입력 스트림으로 연 파일에서,            
            파일의 현재 위치를 n bytes 만큼 이동시킴.
        */
        ifs.seekg(5);

        // n bytes 만큼 이동한 뒤, 해당 파일을 읽어들임. (std::ifstream.get())
        cout << (char)ifs.get() << endl;

        /*
            ios::cur

            현재 읽어들인 파일의 현재 위치에서
            다시 n bytes 만큼 이동하도록 함.
        */
        ifs.seekg(5, ios::cur);
        cout << (char)ifs.get() << endl;
    }

    return 0;
}