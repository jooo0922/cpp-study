#pragma once

#include <iostream>

// 헤더파일 안에서는 가급적 using namespace 사용을 자제
// why? 헤더파일을 include 하는 모든 파일들이 영향을 받게 됨

// 헤더파일 안에 클래스 선언
// 참고로, 클래스의 헤더파일 이름은 클래스 이름과 같게 맞춰야 함!
class Calc
{
private:
	int m_value;

public:
	Calc(int init_value);

	Calc& add(int value);
	Calc& sub(int value);
	Calc& mult(int value);
	void print();
};