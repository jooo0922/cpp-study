#include <iostream>
#include <vector> // 동적 배열 사용을 위해 포함
#include <algorithm> // sorting 함수 사용을 위해 포함
#include <random> // random number 생성을 위해 포함
#include <chrono> // 시간 측정을 위한 함수를 제공하는 표준 라이브러리

using namespace std;

class Timer
{
public:
	Timer();
	~Timer();

private:

};
 
int main()
{
	// random number 생성
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	// 0 ~ 9 까지의 값을 동적 배열에 초기화
	vector<int> vec(10);
	for (unsigned int i = 0; i < vec.size(); ++i)
	{
		vec[i] = i;
	}

	// 생성한 random number 로 동적 배열을 무작위로 섞어줌
	std::shuffle(begin(vec), end(vec), mersenne_engine);

	// for-each 문으로 뒤섞인 동적 배열을 출력
	for (auto& e : vec) cout << e << " ";
	cout << endl;

	Timer timer; // 시간을 측정하는 Timer 클래스 인스턴스 생성

	// c++ 표준 라이브러리로 뒤섞인 동적 배열에 대해 퀵 정렬 수행
	std::sort(begin(vec), end(vec));

	// Timer 가 정렬될 때까지 측정한 시간을 출력
	timer.elapsed(); 

	// for-each 문으로 정렬된 동적 배열을 출력
	for (auto& e : vec) cout << e << " ";
	cout << endl;

    return 0;
}