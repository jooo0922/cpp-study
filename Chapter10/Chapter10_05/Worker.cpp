#include "Worker.h"
#include "Timer.h" // Timer 클래스는 Worker 클래스의 구현부에서만 알고 있으면 됨!

void Worker::doSomething()
{
	// 어떤 일을 하는 데에 걸리는 경과시간 측정
	/*
		이처럼, 의존 관계(Dependency Relationship)는
		
		클래스 선언부(헤더파일)에서는 몰라도 되고,
		구현부(.cpp) 에서 include 시키면 되기 때문에
		깔끔하게 관계가 정리될 수 있음.

		-> 이러한 클래스 간 의존 관계 패턴이 어떻게 보면
		가장 많은 빈도로 사용될 수 있는 패턴이라고 볼 수 있음!
	*/

	Timer timer; // start timer

	// do some work here

	timer.elapsed(); // end timer and report elapsed time
}
