#pragma once

/*
	프로그래밍할 때 필요한 상수가 여러가지가 있을 때,
	이런 식으로 헤더 파일에 네임스페이스를 하나 정의해두고,
	거기에 상수들을 한 곳에 모아두는 게 가독성이 좋음.
*/
namespace constants
{
	constexpr double pi(3.141592);
	constexpr double avogadro(6.0221413e23);
	constexpr double moon_gravity(9.8 / 6.0);
	// ...
}