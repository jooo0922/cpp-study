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

    // 현재 main() 함수가 실행되고 있는 thread 의 id 출력
    cout << std::this_thread::get_id() << endl;


    /* thread 생성 및 사용 */

    // std::thread 를 생성한 뒤, 작업시킬 함수를 함수 포인터, 람다 함수 등으로 매개변수에 전달
    // https://github.com/jooo0922/cpp-study/blob/main/TBCppStudyChapter19/Chapter19_01/Chapter19_01.cpp 참고
    std::thread t1 = std::thread([]() {
        // 새롭게 생성해서 전달받은 작업을 수행하는 thread 의 id 출력 (Main Thread 와 당연히 다름!)
        cout << std::this_thread::get_id() << endl;
        while (true) {}}
    );

    /*
        main() 함수가 돌고 있는 Main Thread 에서
        std::thread 를 새롭게 생성하면,

        새롭게 생성된 thread 에서 
        전달받은 작업(함수)를 실행하게 되는데,
        
        그 작업이 종료되고 나서,
        다시 Main Thread 로 돌아왔을 때,
        어떠한 커뮤니케이션도 없이 main() 함수가 종료되어
        Main Thread 도 종료될 경우, 런타임 에러가 발생함.

        이때, 새롭게 생성된 thread 에서
        작업 완료 후, 다시 Main Thread 에
        결과값을 갖고 복귀해서 합류하도록 하는 것이
        std::thread.join() 함수라고 보면 됨!
    */
    t1.join();

    return 0;
}