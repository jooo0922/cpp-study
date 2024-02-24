#include <iostream>
#include <string>
#include <thread> // std::thread 를 사용하기 위해 포함
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

int main()
{
    // 현재 컴퓨터에서 사용할 수 있는 논리 프로세서의 갯수를 unsigned int 타입으로 반환 
    // ㄷ-> 이 갯수를 가지고서 std::thread 에서 사용 가능!
    const int num_pro = std::thread::hardware_concurrency();

    // 현재 main() 함수가 실행되고 있는 thread 의 id 를 출력
    //cout << std::this_thread::get_id() << endl;

    return 0;
}