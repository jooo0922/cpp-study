#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;

int main()
{
    // 여러 쓰레드들이 동시에 접근할 4 bytes 의 int 타입 메모리를 0으로 초기화 -> '공유 메모리'
    int shared_memory(0);

    // 각 쓰레드에 전달할 작업(함수)를 람다함수로 구현
    auto count_func = [&]() {
        for (int i = 0; i < 1000; i++)
        { 
            /*
                각 쓰레드 1ms 동안 휴식

                각 쓰레드마다 이러한 sleep_for 를 넣어둔 이유는,

                멀티 쓰레딩같은 병렬 프로그래밍에서는
                간단한 작업만 시킬 경우, 아주 빠르게 작업을 처리해버려서
                문제가 안보일 수 있음.

                그래서, 실전에서의 코드와 같이,
                시간이 약간 걸리는 다른 작업이 있는 것처럼 '가정'하기 위해
                sleep_for 코드를 모의로 넣어둠.
            */
            this_thread::sleep_for(chrono::milliseconds(1));
            
            // 반복문을 순회할 때마다 공유 메모리에 접근하여 1 씩 증가시킴.
            // -> 각 쓰레드마다 최종적으로 1000번 증가시킴!
            shared_memory++;
        }
    };

    // 쓰레드 생성 및 실행
    thread t1 = thread(count_func);

    // 생성된 쓰레드가 종료될 때까지 기다렸다가, Main Thread 에 합치기
    t1.join();

    // 쓰레드 실행 종료 후, 공유 메모리에 저장된 결과 출력
    cout << "After" << endl;
    cout << shared_memory << endl;

    return 0;
}