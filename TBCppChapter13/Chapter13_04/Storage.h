#pragma once

#include <iostream>

// 클래스 템플릿
template <typename T>

class Storage
{
private:
	T m_value;

public:
	// 생성자 함수
	Storage(T value)
	{
		m_value = value;
	}

	// 소멸자 함수
	~Storage()
	{

	}

	void print()
	{
		std::cout << m_value << '\n';
	}
};

/*
	클래스 템플릿에서
	특정 멤버함수에 대해서도 템플릿 특수화를 구현할 수 있을까? 
	물론 가능!

	예를 들어, print() 멤버함수에 대해
	double 타입으로 템플릿 파라미터가 들어오면,
	scientific notation 으로 출력하도록 
	템플릿 특수화를 하고 싶을 수 있겠지?

	이럴 경우,
	해당 클래스 바깥에
	print() 멤버함수의 double 타입에 대한 
	템플릿 특수화를 프로그래머가 직접 작성해주면 됨.

	이때, explicit instantiation 을 사용해서
	외부의 .cpp 파일로 분리할 수 있을 것 같지만,
	안타깝게도 템플릿 특수화는 explicit instantiation 을
	직접적으로 인식할 수 없는 이슈가 있음.

	이는 아래 코드에서와 유사한 원인이라고 볼 수 있음.
	https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter13/Chapter13_02/MyArray.cpp 

	굳이 explicit instantiation 을 해야겠다면,
	main() 함수가 위치한 파일에 템플릿 특수화가 분리된 .cpp 파일을 include 하면 되지만,
	이럴거면 차라리 헤더파일에 추가해놓는 게 더 낫기 때문에,
	일반적으로 템플릿 특수화는 같은 헤더파일 안에 구현해두는 경우가 많음.
*/
template <>
void Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << m_value << '\n';
}