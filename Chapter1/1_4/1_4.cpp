#include <iostream> // cout, cin, endl, ...
#include <cstdio> // printf

int main()
{
	int x = 1024;
	double pi = 3.141592;

	// std 같은 namespace 안에 있는 코드들에 접근하려면 :: 기호를 반드시 붙여줘야 함!
	// << 는 개울가에서 물이 흘러가는 모양 > 출력하고 싶은 문자열이 << << 안에 기호를 타고 cout 으로 흘러들어간다는 의미 > Output Operator 라고도 함.
	// endl 는 "줄바꿈"
	std::cout << "I love this lecture!\n"; // << std::endl; // \n 은 new line 즉, 줄바꿈을 의미! > 이렇게 백슬래시 뒤에 오는 문자들은 특정 기능을 내포하고 있음
	std::cout << "x is " << x << " pi is " << pi << std::endl; // 코드 상에서는 줄바꿈을 했지만, 앞줄에서 endl 을 선언하지 않으면 콘솔에는 줄을 바꾸지 않고 출력함

	std::cout << "abc" << "\t" << "def" << std::endl; // cout 에서 "\t" 를 입력하면, 탭 공간만큼 콘솔에서 띄어 줌.
	std::cout << "ab" << "\t" << "cdef" << std::endl; // 빈 공간을 두고 줄맞춤을 해주는 역할도 함.

	return 0;
}