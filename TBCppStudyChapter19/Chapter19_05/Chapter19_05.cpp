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

    return 0;
}