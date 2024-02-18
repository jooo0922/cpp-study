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

            현재 읽어들인 파일의 현재 커서 위치에서
            다시 n bytes 만큼 이동하도록 함.            
        */
        ifs.seekg(5, ios::cur);
        cout << (char)ifs.get() << endl;


        /*
            .seekg() 에는 이러한 탐색 모드들이 몇 가지 더 있음!

            ios::beg 는
            파일 입력 스트림의 시작 지점을 의미하고,

            ios::end 는
            파일 입력 스트림의 끝 지점을 의미함.
        */
        // 파일 입력 스트림의 끝 지점으로부터 0 byte 만큼 이동? 즉, 파일의 끝 지점을 의미!
        //ifs.seekg(0, ios::end);

        // std::ifstream.tellg() 는 현재 파일의 커서 위치를 알려줌.
        //cout << ifs.tellg() << endl;


        /*
            .seekg() 로 현재 파일 커서 위치를 설정한 후,
            std::getline() 으로 읽어오면,

            현재 커서 위치로부터 
            해당 줄의 모든 문자열을 읽어올 것임.
        */
        string str;
        getline(ifs, str);

        cout << str << endl;
    }

    return 0;
}