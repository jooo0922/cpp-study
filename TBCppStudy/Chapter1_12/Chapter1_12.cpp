#include <iostream>
#include "my_work.h"

/*
	프로그래밍을 하다 보면, 
	my_work.h 에서 include 해야 할 헤더파일을 
	여기서 중복 include 하게 되는 경우가 발생!

	이건 결국 뭐냐면, 
	이미 "add.h" 가 include 된 my_work.h 를 include 한 상태에서,
	"add.h" 를 중복해서 include 했기 때문에,

	최종 빌드파일에서는
	add.h 안에 선언 및 정의된 add() 함수가
	두 번 중복해서 정의되는 꼴과 같아져 버림.

	이런 실수가 언제나 발생할 수 있기 때문에,
	헤더가드 전처리기(#pragma once) 를 통해서,
	
	"이 헤더파일이 중복해서 include 되더라도,
	한 번만(once) include 되도록 처리해라!"

	라고 해주는 것임!

	이것이 헤더가드가 필요한 이유!
*/
#include "add.h" 

using namespace std;

int main()
{
	doSomething();

	return 0;
}
