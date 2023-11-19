//#include <iostream> // Monster.h 에서 이미 include 하고 있으므로 중복 include 불필요
#include "Monster.h" // Monster 클래스 생성을 위해 포함

using namespace std;

int main()
{
    Monster mon1("Sanson", 0, 0);
    
    //while (1) // game loop
    {
        // event
        // 몬스터 위치 이동
        mon1.moveTo(1, 1);

        // 몬스터 정보를 출력 스트림 오버로딩 함수를 통해 출력
        cout << mon1 << endl;
    }
    
    return 0;
}