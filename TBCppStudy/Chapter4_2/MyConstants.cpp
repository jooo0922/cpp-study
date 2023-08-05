// 이렇게 MyConstants.h 에 있던 상수 namespace 를 그대로 복붙해오고,
// 각 상수들이 external linkage 에 사용될 수 있도록 extern 키워드를 명시해 줌.
// 이렇게 하면, 이 MyConstants.cpp 파일은 컴파일 시 .obj 로 변환되고,
// 링커에 의해 external linking 을 거침으로써, 다른 .cpp 파일들에서 해당 심볼릭 상수들을 가져다 쓸 수 있게 됨.
namespace Constants
{
	extern const double pi(3.141592);
	extern const double gravity(9.8);
	// ...
}