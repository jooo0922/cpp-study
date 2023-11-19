#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono> // 시간 측정을 위한 함수를 제공하는 표준 라이브러리

// chrono 라이브러리의 함수들로 만든 실행시간 측정 클래스 Timer
// 앞으로 코드 실행시간 측정 시, 이 클래스를 복붙해서 가져다가 사용하면 되겠지?
// https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter8/Chapter8_15/Chapter8_15.cpp 에서 구현한 Timer 클래스 재사용
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
		std::cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << std::endl;
	}
};