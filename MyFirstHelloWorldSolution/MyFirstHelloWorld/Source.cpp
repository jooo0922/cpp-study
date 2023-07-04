#include <iostream> // <iostream> 은 화면에 뭔가를 출력하는 기능들을 갖고 있는 코드들. #include 는 해당 코드들을 갖고와서 포함시킨다는 의미.

int main()
{
	// std::cout 은 "console out", std::endl 은 "end line" 이라는 뜻이겠지?
	// << 에 커서를 대보면, "ostream 어쩌구~" 이렇게 뜸. > 이게 위에서 include 했던 <iostream> 코드의 일부겠지?
	// std 는 iostream 와 같은 Standard Template Library 안에 들어있는 모든 것들이 정의된 namespace 를 가리킴
	// std 옆에 :: 이거는 namespace 를 의미함.
	std::cout << "Hello, World!" << std::endl;

	return 0;
}