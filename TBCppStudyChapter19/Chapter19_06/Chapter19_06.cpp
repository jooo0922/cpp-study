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

using namespace std;

mutex mtx;

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

    return 0;
}