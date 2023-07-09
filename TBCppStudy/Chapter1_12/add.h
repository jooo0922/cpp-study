//#pragma once

/*
	Chapter1_11 에서와 다르게
	이번에는 왜 함수의 본문을 .cpp 파일로 분리하지 않고,
	헤더파일에 전부 때려넣었나?

	원래는 이렇게 하면 안됨.
	가급적 함수 본문 정의는 .cpp 파일을 별도로 쪼개고,
	선언만 헤더파일에 해놓는 게 가장 모범적인 방식이나,

	실제 개발 시, 바쁘다보니 모든 걸 헤더 파일에 때려넣는 경우가 많음.
	이때, 헤더가드 전처리기(#pragma once) 가 선언되어 있으면
	이런 식으로 때려넣더라도 문제없이 빌드할 수 있도록 해주는 것임!
*/

// 헤더가드는 아래와 같은 전처리기 문법으로도 선언 가능!
#ifndef MY_ADD // include 를 통해서 MY_ADD 가 정의가 되어있지 않다면, (if not defined)
#define MY_ADD // MY_ADD(#endif 전처리기 까지의 함수 정의)를 정의하고,

int add(int a, int b)
{
	return a + b;
}

#endif // !MY_ADD // 그렇지 않다면(include 를 통해서 MY_ADD 가 이미 정의되어 있다면), 전처리문을 종료해라 (endif)

