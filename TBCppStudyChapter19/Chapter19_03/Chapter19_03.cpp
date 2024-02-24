#include <iostream>
#include <string>
#include <thread> // std::thread 를 사용하기 위해 포함
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

/*
    mutex


    'mutual exclusion' 의 약자
    '상호 배제' 라는 의미를 가짐.

    즉, 
    '서로 못건들게 한다',
    '이건 내 것이니 나만 쓸 수 있어'
    이렇게 선언할 수 있는 존재!

    -> 즉, 각 쓰레드들 내에서 동시에 일률적으로
    처리하는 작업들 중에서,

    특정 작업만큼은
    하나의 쓰레드만 담당하도록 하려고 할 때
    mutex 를 사용하기 좋음!
*/
mutex mtx;

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
                그래도 출력할 때 만큼은 깔끔하게 정리해서 출력하고 싶을 수 있잖아?

                이럴 때, mutex 를 사용해서 
                특정 하나의 쓰레드만 '상호 배제적으로' 출력 작업을 처리할 수 있도록
                설정하는 방법이 있음!

                어떤 쓰레드가 되었던 지 간에,
                맨 먼저 100 ms 휴식을 다 취한 뒤에,
                mtx.lock() 지점에 도착해서 잠가버리면,

                다음 쓰레드는 mtx.lock() 에 의해 잠겨진
                이후의 코드들에는 접근 및 실행이 불가해 짐!
                
                mutex.lock() 에 가장 먼저 도달해서 
                직접 잠가버린 쓰레드 당사자만 mutex.lock() ~ mutex.unlock() 사이의
                코드를 실행할 수 있는 '상호 배제적인 권한'이 생기게 됨!

                -> 이처럼, 멀티 쓰레딩에서는 단순히 각 쓰레드에 
                할 일을 넣어주는 게 중요한 게 아니고,
            
                각 쓰레드들의 중복되는 작업을 mutex 같은 걸 사용해서
                잘 처리할 줄 아는 것이 중요함!
            */
            mtx.lock();
            cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
            
            // 특정 쓰레드만 처리시킬 작업 앞에서 mutex.lock() 을 걸어줬으면 
            // 해당 작업 종료 후 mutex.unlock() 으로 반드시 풀어줘야 함. 
            mtx.unlock();
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