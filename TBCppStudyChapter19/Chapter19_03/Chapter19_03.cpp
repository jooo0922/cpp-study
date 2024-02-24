#include <iostream>
#include <string>
#include <thread> // std::thread 를 사용하기 위해 포함
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

int main()
{
    /*
        std::thread::hardware_concurrency()


        현재 컴퓨터에서 사용할 수 있는 논리 프로세서의 갯수를 
        unsigned int 타입으로 반환

        thread 는 CPU 의 각 코어(프로세서)에 작업을 위임해서
        동시에 처리할 수 있도록 하는 단위이므로,

        최대 생성할 수 있는 thread 의 갯수는
        CPU 가 제공하는 논리 프로세서 갯수(코어와 같은 경우도 있고, 더 많은 경우도 있음.)
        를 넘을 수 없음.

        따라서, std::thread 생성 및 사용 시, 
        이 논리 프로세서 갯수만큼의 thread 만 생성이 가능하겠지!
    */
    //const int num_pro = std::thread::hardware_concurrency();

    // 현재 main() 함수가 실행되고 있는 thread 의 id 출력
    //cout << std::this_thread::get_id() << endl;


    /* thread 생성 및 사용 */

    // std::thread 를 생성한 뒤, 작업시킬 함수를 함수 포인터, 람다 함수 등으로 매개변수에 전달
    // https://github.com/jooo0922/cpp-study/blob/main/TBCppStudyChapter19/Chapter19_01/Chapter19_01.cpp 참고
    
    /* std::vector 동적 배열로 여러 개의 thread 생성 및 사용 */
    
    // std::thread 타입으로 논리 프로세서 갯수만큼의 동적 배열 메모리 할당
    //vector<std::thread> my_threads;
    //my_threads.resize(num_pro);

    // for-each 문으로 순회하며 std::thread 생성 및 사용
    //for (auto& e : my_threads)
    //{
    //    e = std::thread([]() {
    //        // 새롭게 생성해서 전달받은 작업을 수행하는 thread 의 id 출력 (Main Thread 와 당연히 다름!)
    //        cout << std::this_thread::get_id() << endl;
    //        while (true) {}}
    //    );
    //}

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

        달리 말하면, join() 함수 호출부는
        각 thread 들이 끝나기를 기다리고 있는 것으로도
        볼 수 있음!
    */

    // for-each 문으로 순회하며 작업이 완료된 thread 들을 Main Thread 에 join
    //for (auto& e : my_threads)
    //{
    //    e.join();
    //}


    /* 멀티 쓰레딩 예제 */
    
    // 각 쓰레드에 전달할 작업을 람다함수로 정의
    auto work_func = [](const string& name)
    {
        for (int i = 0; i < 5; i++)
        {
            // chrono 라이브러리를 사용해서 100 ms 동안 일시적으로 매 순회마다 각 쓰레드가 잠자도록(쉬도록) 함 
            // chrono 라이브러리 사용 관련 https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter8/Chapter8_15/Chapter8_15.cpp 참고
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            // 현재 이 람다함수를 실행 중인 쓰레드 id 출력
            /*
                그러나, 멀티 쓰레딩으로 동시에 출력하다 보면,
                아래의 출력 스트림이 꼬여버려서 난잡하게 출력이 됨.

                즉, 그만큼 각 쓰레드가 정상적으로 동시에 실행되고 있다는 증거이기는 하나,
                그래도 출력할 때 만큼은 깔끔하게 출력하고 싶을 수 있잖아?
            */
            cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
        }
    };

    // 2개의 쓰레드 생성 및 실행
    std::thread t1 = std::thread(work_func, "JackJack");
    std::thread t2 = std::thread(work_func, "Dash");

    // 각 쓰레드 실행이 종료될 때까지 기다렸다가 Main Thread 로 합치기
    t1.join();
    t2.join();

    return 0;
}