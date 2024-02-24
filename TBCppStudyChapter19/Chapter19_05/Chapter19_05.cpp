#include <iostream>
#include <future> // async, future, promise 사용을 위해 포함
#include <thread>

using namespace std;

int main()
{
    // multi-threading (이전 강의에서 살펴봤던 멀티쓰레딩 예제)
    {
        int result;
        std::thread t([&] { result = 1 + 2; });
        t.join();
        cout << result << endl;
    }

    // task-based parallelism (async 로 구현한 작업 기반 비동기 프로그래밍)
    /*
        작업 기반 비동기 프로그래밍 vs 멀티쓰레딩


        멀티쓰레딩은 '여러 개의 thread 를 생성하는 것' 
        자체에 초점을 두는 형태로 프로그래밍하는 반면,
        
        std::async() 를 활용한 작업 기반 비동기 프로그래밍은
        '어떤 task(작업)을 할 것인가'에 초점을 맞추어 프로그래밍함.

        둘 다 여러 개의 thread 를 사용하여 작업들을 병렬 처리하지만,
        코드 형태로 표현할 때, 어떤 부분에 더 초점을 두어서 프로그래밍 하느냐가 다른 것임!

        또한, 비동기 프로그래밍으로 처리한 결과값은
        현재 받을 수 있는 게 아님.

        비동기 프로그래밍에 전달하는
        람다 함수 내부의 작업들이 아주 오래 걸릴 수도 있기 때문에,
        람다 함수의 return 값을 곧바로 받을 수 없음!

        그래서 반환값이 std::future<int> 타입인 것임.
        즉, '미래에 async 작업이 끝나면, int 타입의 결과값을 받아오겠다'는
        의미의 타입이라고 보면 됨!
    */
    {
        /*
            std::async() 는 
            
            자바스크립트 async 와 유사하게,
            Main Thread 가 진행되는 것과 별도로 
            비동기적으로 작업이 이루어짐.

            std::async() 로 비동기 작업을 처리한 결과를
            std::future 타입으로 반환해 줌.

            일반적으로는
            멀티쓰레딩 기반 병렬 처리보다는,
            작업 기반 비동기 처리를 선호하므로,

            std::thread 보다는
            std::async 를 선호하는 편!
        */
        auto fut = std::async([] { return 1 + 2; });

        /*
            std::future<int>.get() 은
            위의 std::async() 작업이 종료될 때까지 기다렸다가,
            
            async 작업이 종료되고 나면,
            그 미래의 시점에 std::async() 내부의 람다함수에서
            반환한 int 타입의 값을 얻어옴.
        */
        cout << fut.get() << endl;
    }

    return 0;
}