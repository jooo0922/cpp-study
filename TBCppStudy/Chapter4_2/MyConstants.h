#pragma once

// 헤더파일 관련 설명할 때,
// 헤더파일 안에 namespace 로 자주 사용되는 심볼릭 상수를 묶어서 정리해봤었지?
namespace Constants 
{
	// 실제 심볼릭 상수의 값은 MyConstants.cpp 에서 초기화해주고,
	// 헤더 파일에서는 상수를 선언만 해줌.
	extern const double pi;
	extern const double gravity;
	// ...
}