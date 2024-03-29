#include <iostream>
#include <chrono>
#include <mutex> // mutex 사용을 위해 포함 (mutex.lock()/unlock())
#include <random>
#include <thread> // std::thread 사용을 위해 포함
#include <utility>
#include <vector>
#include <atomic> // atomic<> 으로 공유 메모리 race condition 이슈 해결을 위해 포함
#include <future> // async, future, promise 등 작업 기반 비동기 프로그래밍 사용을 위해 포함
#include <numeric> // std::inner_product (벡터 내적) 사용을 위해 포함
#include <execution> // parallel execution

#include <boost/asio.hpp>

using namespace std;

mutex mtx;

// 멀티쓰레딩으로 계산할 벡터 내적 함수
void dotProductNaive(
    const vector<int>& v0, // 첫 번째 벡터
    const vector<int>& v1, // 두 번째 벡터
    const unsigned i_start, // 현재 thread 가 계산할 각 벡터의 시작 컴포넌트 위치 (즉, 1억 개의 컴포넌트들 중에서 i_start 번째부터는 이 thread 가 계산)
    const unsigned i_end, // 현재 thread 가 계산할 각 벡터의 끝 컴포넌트 위치 (즉, 1억 개의 컴포넌트들 i_end 번째 까지는 이 thread 가 계산)
    unsigned long long& sum // 각 thread 에서 벡터 내적 결과를 누산할 l-value reference(참조변수)  
)
{
    for (unsigned i = i_start; i < i_end; i++)
    {
        sum += v0[i] * v1[i];
    }
}

// std::scoped_lock (c++ 17 이후 버전만 사용 가능) 으로 race condition 이슈를 해결한 벡터 내적 함수
void dotProductLock(
    const vector<int>& v0, // 첫 번째 벡터
    const vector<int>& v1, // 두 번째 벡터
    const unsigned i_start, // 현재 thread 가 계산할 각 벡터의 시작 컴포넌트 위치 (즉, 1억 개의 컴포넌트들 중에서 i_start 번째부터는 이 thread 가 계산)
    const unsigned i_end, // 현재 thread 가 계산할 각 벡터의 끝 컴포넌트 위치 (즉, 1억 개의 컴포넌트들 i_end 번째 까지는 이 thread 가 계산)
    unsigned long long& sum // 각 thread 에서 벡터 내적 결과를 누산할 l-value reference(참조변수)  
)
{
    for (unsigned i = i_start; i < i_end; i++)
    {
        std::scoped_lock lock(mtx); // c++ 17

        sum += v0[i] * v1[i];
    }
}

// 공유 메모리 sum 을 atomic 으로 선언하여 race condition 이슈를 해결한 벡터 내적 함수
/*
    atomic 으로 선언된 공유 메모리의
    += 연산자는 atomic 에서 오버로딩된 연산자를 사용하므로,

    빈번하게 사용할 경우
    마찬가지로 성능이 느려지는 이슈가 있음.
*/
void dotProductAtomic(
    const vector<int>& v0, // 첫 번째 벡터
    const vector<int>& v1, // 두 번째 벡터
    const unsigned i_start, // 현재 thread 가 계산할 각 벡터의 시작 컴포넌트 위치 (즉, 1억 개의 컴포넌트들 중에서 i_start 번째부터는 이 thread 가 계산)
    const unsigned i_end, // 현재 thread 가 계산할 각 벡터의 끝 컴포넌트 위치 (즉, 1억 개의 컴포넌트들 i_end 번째 까지는 이 thread 가 계산)
    atomic<unsigned long long>& sum // 각 thread 에서 벡터 내적 결과를 누산할 공유 메모리를 atomic 으로 선언
)
{
    for (unsigned i = i_start; i < i_end; i++)
    {
        std::scoped_lock lock(mtx); // c++ 17

        sum += v0[i] * v1[i];
    }
}

// std::async() 가 비동기로 처리할 벡터 내적 함수
auto dotProductFuture(
    const vector<int>& v0, // 첫 번째 벡터
    const vector<int>& v1, // 두 번째 벡터
    const unsigned i_start, // 현재 thread 가 계산할 각 벡터의 시작 컴포넌트 위치 (즉, 1억 개의 컴포넌트들 중에서 i_start 번째부터는 이 thread 가 계산)
    const unsigned i_end // 현재 thread 가 계산할 각 벡터의 끝 컴포넌트 위치 (즉, 1억 개의 컴포넌트들 i_end 번째 까지는 이 thread 가 계산)
)
{
    // std::async() 가 처리한 작업에서 반환할 local sum 초기화
    int sum = 0;
    for (unsigned i = i_start; i < i_end; i++)
    {
        sum += v0[i] * v1[i];
    }

    return sum;
}


int main()
{
    /* 멀티쓰레딩으로 벡터 내적 구현 */

    /*
        벡터 내적이란?

        v0 = {1, 2, 3}
        v1 = {4, 5, 6}
        v0_dot_v1 = 1*4 + 2*5 + 3*6;
    */

    // 데이터 갯수
    const long long n_data = 100'000'000;

    // thread 갯수
    const unsigned n_thread = 4;

    // 테스트할 두 벡터 동적 메모리 할당 (n_data 크기만큼!)
    std::vector<int> v0, v1;
    v0.reserve(n_data);
    v1.reserve(n_data);

    // 난수 생성기 및 고정 seed 선언
    random_device seed;
    mt19937 engine(seed());

    // 난수 생성 범위를 [1, 10] 으로 제한
    uniform_int_distribution<> uniformDist(1, 10);

    // 각각 1억 개의 컴포넌트(각 컴포넌트의 범위는 [1, 10] 사이의 랜덤한 int)를 갖는 두 벡터 초기화
    for (long long i = 0; i < n_data; i++)
    {
        v0.push_back(uniformDist(engine));
        v1.push_back(uniformDist(engine));
    }

    // 멀티쓰레딩으로 구현할 벡터 내적 연산과의 결과 비교를 위해 std::inner_product 먼저 실행
    cout << "std::inner_product" << endl;
    {
        // 내적 연산이 시작된 시점 저장
        const auto sta = chrono::steady_clock::now();

        /*
            std::inner_product 는
            두 std::vector 의 반복자를 세 번째 매개변수까지 입력함.

            두 번째 vector 의 v1.end() 를 입력하지 않은 이유는,
            어차피 내적 연산할 v0 과 v1 의 컴포넌트 길이가 같다고 가정하기 때문!

            또한, 100,000,000 개의 컴포넌트를 갖는 벡터의 내적이므로,
            결과값이 아주 큰 정수값으로 나올 것이기 때문에,

            0ull, 즉 '부호가 없는 long long 정수 타입의 리터럴'을
            네 번째 매개변수에 전달함으로써, 벡터 내적의 계산 결과 타입을 설정함.

            0ull 에서
            '0'은 정수 리터럴이고,
            'ull' 은 'unsigned long long'을 나타내는 접미사
        */
        const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

        // 내적 연산 종료 시점에서 시작 시점을 빼서 경과시간 기록
        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

        // 경과시간 출력
        cout << dur.count() << endl;

        // 내적 연산 결과 출력
        cout << sum << endl;
        cout << endl;
    }

    // 멀티쓰레딩으로 벡터 내적 연산 구현
    cout << "Naive" << endl;
    {
        // 내적 연산이 시작된 시점 저장
        const auto sta = chrono::steady_clock::now();

        // 내적 연산의 결과를 누산할 변수 초기화
        unsigned long long sum = 0;

        // 4개의 쓰레드가 담길 동적 배열 생성 및 초기화
        vector<thread> threads;
        threads.resize(n_thread);

        // 1억 개의 컴포넌트를 갖는 벡터의 내적에서 각 thread 가 연산을 맡을 컴포넌트 갯수 (25,000,000 개)
        const unsigned n_per_thread = n_data / n_thread;

        // 각 쓰레드 생성 및 실행
        for (unsigned t = 0; t < n_thread; t++)
        {
            /*
                각 thread 마다
                0번 ~ 25,000,000번 컴포넌트 계산,
                25,000,000번 ~ 50,000,000 번 컴포넌트 계산,
                ...

                이런 식으로 1억 개의 컴포넌트를
                25,000,000 개씩 나눠 맡아서 작업시킴.

                참고로, std::ref() 는
                값이나 객체를 l-value reference,
                즉, '참조변수'로 바꿔서 전달하는 기능!
            */
            threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        }

        // 각 thread 작업이 끝나면 Main Thread 로 join 시킴
        for (unsigned t = 0; t < n_thread; t++)
        {
            threads[t].join();
        }

        // 내적 연산 종료 시점에서 시작 시점을 빼서 경과시간 기록
        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

        // 경과시간 출력
        cout << dur.count() << endl;

        // 내적 연산 결과 출력
        cout << sum << endl;
        cout << endl;
    }

    // 멀티쓰레딩으로 벡터 내적 연산 구현 (lock guard 기법으로 race condition 이슈 해결)
    //cout << "Lockguard" << endl;
    //{
    //    // 내적 연산이 시작된 시점 저장
    //    const auto sta = chrono::steady_clock::now();

    //    // 내적 연산의 결과를 누산할 변수 초기화
    //    unsigned long long sum = 0;

    //    // 4개의 쓰레드가 담길 동적 배열 생성 및 초기화
    //    vector<thread> threads;
    //    threads.resize(n_thread);

    //    // 1억 개의 컴포넌트를 갖는 벡터의 내적에서 각 thread 가 연산을 맡을 컴포넌트 갯수 (25,000,000 개)
    //    const unsigned n_per_thread = n_data / n_thread;

    //    // 각 쓰레드 생성 및 실행
    //    for (unsigned t = 0; t < n_thread; t++)
    //    {
    //        threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1),
    //            t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
    //    }

    //    // 각 thread 작업이 끝나면 Main Thread 로 join 시킴
    //    for (unsigned t = 0; t < n_thread; t++)
    //    {
    //        threads[t].join();
    //    }

    //    // 내적 연산 종료 시점에서 시작 시점을 빼서 경과시간 기록
    //    const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

    //    // 경과시간 출력
    //    cout << dur.count() << endl;

    //    // 내적 연산 결과 출력
    //    cout << sum << endl;
    //    cout << endl;
    //}

    // 멀티쓰레딩으로 벡터 내적 연산 구현 (atomic 으로 race condition 이슈 해결)
    //cout << "Atomic" << endl;
    //{
    //    // 내적 연산이 시작된 시점 저장
    //    const auto sta = chrono::steady_clock::now();

    //    // 내적 연산의 결과를 누산할 공유 메모리를 atomic 으로 선언
    //    atomic<unsigned long long> sum = 0;

    //    // 4개의 쓰레드가 담길 동적 배열 생성 및 초기화
    //    vector<thread> threads;
    //    threads.resize(n_thread);

    //    // 1억 개의 컴포넌트를 갖는 벡터의 내적에서 각 thread 가 연산을 맡을 컴포넌트 갯수 (25,000,000 개)
    //    const unsigned n_per_thread = n_data / n_thread;

    //    // 각 쓰레드 생성 및 실행
    //    for (unsigned t = 0; t < n_thread; t++)
    //    {
    //        threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1),
    //            t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
    //    }

    //    // 각 thread 작업이 끝나면 Main Thread 로 join 시킴
    //    for (unsigned t = 0; t < n_thread; t++)
    //    {
    //        threads[t].join();
    //    }

    //    // 내적 연산 종료 시점에서 시작 시점을 빼서 경과시간 기록
    //    const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

    //    // 경과시간 출력
    //    cout << dur.count() << endl;

    //    // 내적 연산 결과 출력
    //    cout << sum << endl;
    //    cout << endl;
    //}

    // std::future, std::async 로 작업 기반 비동기 프로그래밍을 구현하여 벡터 내적 계산
    //cout << "Future" << endl;
    //{
    //    // 내적 연산이 시작된 시점 저장
    //    const auto sta = chrono::steady_clock::now();

    //    // 내적 연산의 결과를 누산할 공유 메모리 선언
    //    unsigned long long sum = 0;

    //    // 4개의 std::future 가 담길 동적 배열 생성 및 초기화
    //    vector<std::future<int>> futures;
    //    futures.resize(n_thread);

    //    // 1억 개의 컴포넌트를 갖는 벡터의 내적에서 각 thread 가 연산을 맡을 컴포넌트 갯수 (25,000,000 개)
    //    const unsigned n_per_thread = n_data / n_thread;

    //    // 각 std::async 를 실행한 결과값이 저장된 std::future 를 반환받음.
    //    for (unsigned t = 0; t < n_thread; t++)
    //    {
    //        futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1),
    //            t * n_per_thread, (t + 1) * n_per_thread);
    //    }

    //    // 각 std::future.get() 으로 async 결과값을 공유 메모리에 누산
    //    /*
    //        std::async() 는 join() 같은 함수가 없어도
    //        알아서 작업이 종료될 때까지 기다렸다가,
    //        작업이 종료되면 알아서 처리해 줌.
    //    */
    //    for (unsigned t = 0; t < n_thread; t++)
    //    {
    //        sum += futures[t].get();
    //    }

    //    // 내적 연산 종료 시점에서 시작 시점을 빼서 경과시간 기록
    //    const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

    //    // 경과시간 출력
    //    /*
    //        다른 멀티쓰레딩 벡터 내적 예제들보다
    //        수행 시간이 훨씬 빨라짐.

    //        오히려 std::inner_product() 보다도 더 빠름.

    //        뿐만 아니라,
    //        결과값도 정확함.
    //    */
    //    cout << dur.count() << endl;

    //    // 내적 연산 결과 출력
    //    cout << sum << endl;
    //    cout << endl;
    //}

    // std::transform_reduce 벡터 내적 계산
    /*
        std::transform_reduce 는
        std::inner_product 의 병렬 처리 버전이라고 보면 됨.

        사실, 이처럼 병렬 처리가 필요한 부분들은
        STL 에서 지원을 해주기 때문에,
        위 예제들처럼 병렬 처리를 직접 구현할 필요는 없음.

        그러나, STL 에서 제공해주는 병렬 처리 함수들을 사용하기 전,
        멀티쓰레딩을 직접 구현해 본 것이 좋은 연습이 되었을 것임.
    */
    cout << "std::transform_reduce" << endl;
    {
        // 내적 연산이 시작된 시점 저장
        const auto sta = chrono::steady_clock::now();

        // std::transform_reduce 로 벡터 내적 계산
        /*
            std::inner_product 와 대부분 매개변수가 동일하나,
            첫 번째 매개변수로 들어오는 플래그가 추가됨.

            std::execution::par 에서
            par 은 parallel 의 약자로써,

            해당 작업을 parallel(병렬)로 돌려달라고 설정하는
            플래그라고 보면 됨.

            반대 플래그는
            std::execution::seq 로써,
            seq, 즉, sequantial(순서대로) 로 돌려달라고 설정하는 것임.

            -> std::execution::seq 플래그로 설정해서 연산한다면,
            std::inner_product 와 속도가 동일할 것임! (병렬 처리가 미적용되기 때문에...)
        */
        unsigned long long sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);

        // 내적 연산 종료 시점에서 시작 시점을 빼서 경과시간 기록
        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

        // 경과시간 출력
        cout << dur.count() << endl;

        // 내적 연산 결과 출력
        cout << sum << endl;
        cout << endl;
    }

    return 0;
}