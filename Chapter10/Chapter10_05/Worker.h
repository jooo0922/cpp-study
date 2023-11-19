#pragma once

/*
	이제 Worker 클래스는 
	멤버함수의 구현부가 Worker.cpp 로 분리되었으므로,

	Timer 클래스에 대해서 몰라도 상관없음
	-> #include "Timer.h" 를 제거해도 됨
*/
class Worker
{
public:
	void doSomething();
};