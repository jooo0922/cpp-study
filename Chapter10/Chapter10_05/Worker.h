#pragma once

#include "Timer.h"

class Worker
{
public:
	void doSomething()
	{
		// 어떤 일을 하는 데에 걸리는 경과시간 측정
		// 이때, 놀랍게도 Worker 클래스는 Timer 클래스에 대해 몰라도 됨!

		Timer timer; // start timer

		// do some work here

		timer.elapsed(); // end timer and report elapsed time
	}
};