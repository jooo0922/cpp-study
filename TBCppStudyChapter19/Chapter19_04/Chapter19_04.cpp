#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

int main()
{
    // 여러 쓰레드들이 동시에 접근할 4 bytes 의 int 타입 메모리를 0으로 초기화 -> '공유 메모리'
    /*
        atomic


        각 쓰레드가
        1. CPU 에서 메모리로 값을 읽어오고,
        2. 연산을 처리하고,
        3. 처리된 결과값을 다시 메모리에 덮어쓰는

        3단계의 과정을 한 방에 해치우도록 묶어버리는 기능을
        제공하는 변수

        멀티 쓰레딩에서의 Race Condition 이슈 해결을 위해,

        공유 메모리 변수의 타입을 
        atomic 으로 선언하여 사용할 수 있음.

        단, 이럴 경우,
        기존 공유 메모리의 ++ 연산자보다,
        atomic 에 오버로딩된 ++ 연산자가 더 느린 측면이 있음!
    */
    //atomic<int> shared_memory(0);
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
            /*
                만약, 공유 메모리 변수가
                atomic 타입으로 정의되었다면,

                ++ 연산자는 더 이상 int 의 ++ 가 아니고,
                atomic 에 정의되어 있는 ++ 연산자 오버로딩을 의미함!
            */
            //shared_memory++;

            /*
                race condition 이슈는
                mutex.lock(), .unlock() 을 통해서도 해결 가능!
            */
            //mtx.lock();
            //shared_memory++;
            //mtx.unlock();

            /*
                lock guard

                mutex.lock() / unlock() 도 물론 좋은데,
                만약 .unlock() 호출을 빼먹거나,

                예외처리처럼
                mutex.lock() ~ mutex.unlock() 사이에
                다른 부분으로 슝 날라가는 코드가 있으면,
                .unlock() 이 선언되어 있어도 실행이 안될 수 있음.

                이럴 경우 사용하는 클래스 템플릿이
                std::lock_guard<> 라고 보면 됨.
            */
            std::lock_guard<mutex> lock(mtx);

            shared_memory++;
        }
    };

    // 쓰레드 생성 및 실행
    thread t1 = thread(count_func);
    thread t2 = thread(count_func);

    // 생성된 쓰레드가 종료될 때까지 기다렸다가, Main Thread 에 합치기
    t1.join();
    t2.join();

    // 쓰레드 실행 종료 후, 공유 메모리에 저장된 결과 출력
    cout << "After" << endl;
    cout << shared_memory << endl;

    return 0;
}

/*
    Race Condition

    
    멀티 쓰레딩으로 공유 메모리에 각각 접근해서
    1000번씩 증가 연산을 해준다면, 결과값이 2000이 나와야 하는데,
    실제로는 그렇지 않은 이유가 뭘까?

    실제 두 쓰레드는 반복문을 1000번씩 순회한 것이 맞음.

    그러나, 
    예를 들어, 쓰레드 t1 이 먼저 shared_memory 변수에 접근하여
    CPU 에서 값을 읽어오고(읽어온 값이 10 이라고 치자.), 
    
    1만큼 값을 증가시켜서, 
    다시 shared_memory 에 증가시킨 값(11) 을 
    덮어쓰려고 하기도 전에,
    
    다른 쓰레드 t2 가 재빨리
    11 을 먼저 덮어써버릴 경우,

    두 쓰레드가 동일한 값을 덮어써버리는 상황이 
    몇 번 씩 발생하게 되다 보니,

    공유 메모리에 존재하는 값이 정확히 2000이 안 나오게 되는 것임!

    이러한 현상을 'Race Condition' 이라고 부름!

    
    이처럼 멀티 쓰레딩에서의 Race Condition 이슈를 해결하기 위해
    사용하는 라이브러리가 atomic 이라고 보면 됨!
*/