#include <iostream>
#include <vector> // 동적 배열 사용을 위해 포함
#include <algorithm> // sorting 함수 사용을 위해 포함
#include <random> // random number 생성을 위해 포함
#include <chrono> // 시간 측정을 위한 함수를 제공하는 표준 라이브러리

using namespace std;

// chrono 라이브러리의 함수들로 만든 실행시간 측정 클래스 Timer
class Timer
{
	// Timer 클래스 내에서만 사용될 nested type 을 using 문으로 정의 (chrono 라이브러리 내의 특정 타입들에 별칭을 붙임)
	// using 문 또한 typedef 처럼 type alias 를 정의하는 데 사용할 수 있다고 했었지?
	// https://github.com/jooo0922/cpp-study/blob/main/TBCppStudy/Chapter4_9/Chapter4_9.cpp 참고
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>; // 초 단위 시간간격을 선언하는 타입

	// 클래스 인스턴스가 생성된 시점을 시작 시간으로 하는 private 멤버변수 start_time 선언
	std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
	void elapsed()
	{
		// 경과시간 측정 멤버함수 elapsed() 가 호출된 시점의 시간을 측정하여 변수 end_time 에 저장
		std::chrono::time_point<clock_t> end_time = clock_t::now();

		// 종료 시간 - 시작 시간으로 계산된 경과시간을 second_t(초 단위 시간간격)타입으로 형변환하여 출력
		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
	}
};
 
int main()
{
	// random number 생성
	// random number 생성 관련 https://github.com/jooo0922/cpp-study/blob/main/TBCppStudy/Chapter5_09/Chapter5_09.cpp 참고
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