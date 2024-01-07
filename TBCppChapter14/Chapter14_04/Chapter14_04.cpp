#include <iostream>
#include <exception> // 표준 라이브러리에 구현된 std::exception 예외 클래스를 사용하기 위해 포함
#include <string>

/*
	std::exception


	표준 라이브러리에 구현된 예외 클래스로써,
	이 안의 함수들을 잘 사용할 수 있다면,

	우리가 직접 커스텀 예외 클래스를 만들지 않아도
	catch 문 안에서 적절한 예외 처리를 할 수 있고,

	std::string 등 다른 표준 라이브러리에 존재하는
	클래스와 호환성있게 사용 가능하여 아주 편리함.
*/

/*
	아래와 같이,
	std::exception 을 상속받는 예외 클래스를
	직접 구현할 수도 있음.

	이때, std 내에 정의된 수많은
	std::exception 의 자식 클래스들과 동일한 방식으로
	작동하기를 원한다면,

	std::exception 클래스 내의
	필수 멤버함수인 what 을 반드시 override 해줘야 함!
*/
class CustomException : public std::exception
{
public:
	// 멤버함수 what() overrdie
	/*
		다른 키워드들은 다 익숙한데
		'noexcept' 는 처음 보지?

		이거는 c++ 11 이상 컴파일러를 사용한다면
		what() 멤버함수 override 시 반드시 들어가줘야 한다고 함.

		이게 뭐냐면,
		"적어도 해당 멤버함수 안에서는
		throw std::exception 을 던지지 않음"을
		보장하도록 하는 키워드라고 함.
	*/
	const char* what() const noexcept override
	{
		return "Custom exception";
	}
};

int main()
{
	try
	{
		std::string s;

		/*
			아래와 같이, std::string 타입의 문자열 배열을 
			리사이징 하는데, -1 과 같은 이상한 파라미터가 들어가게 되면,

			std::string::resize() 함수 내부에서
			부적절한 인자들에 대해 std::exception 타입 에러를 
			throw 하도록 되어있음.

			우리는 이 std::exception 타입의
			표준 에러를 catch 하는 코드만 구현해두면
			예외 처리를 적절하게 handling 할 수 있겠지!
		*/
		//s.resize(-1);

		/*
			아래와 같이,
			std::exception 의 자식클래스 중 하나인 std::runtime_error 를 
			
			throw 할 에러 객체의 타입으로 사용할 수도 있음!
		*/
		//throw std::runtime_error("Bad thing happened");

		/*
			std::exception 클래스를 상속받아 직접 만든
			CustomException 타입의 에러 객체를 throw 해보자!
		*/
		throw CustomException();
	}
	catch (std::length_error& exception)
	{
		/*
			std::string::resize() 에서 던지는
			std::length_error(std::exception 의 자식클래스) 타입 에러를
			먼저 catch 하기 위해,

			자식클래스 타입 에러에 대한 catch 문을 먼저 구현함.

			그러나, 매번 std 의 어떤 클래스가 어떤 예외클래스를 던지는 지
			매번 확인해갖고 자식클래스 에러 타입에 대한 catch 문을
			일일이 구현하는 게 굉장히 번거롭기 때문에,

			실제로 이렇게 자식 클래스 타입의 catch 문을 
			별도로 구현하는 경우는 거의 없고,

			대부분은 아래와 같이 std::exception 타입의
			최상위 부모인 예외 클래스를 선언하여 catch 문을 구현함
		*/
		std::cerr << "Length_Error" << std::endl;
	 	std::cerr << exception.what() << std::endl;
	}
	catch (std::exception& exception)
	{
		// std::string::resize() 에서 던져진 에러를 catch 하여 적절히 예외처리 함.

		/*
			std::exception 은
			표준 라이브러리 내에 구현된 수많은 예외 클래스들의
			부모 클래스라고 보면 됨.

			그래서, catch 된 std::exception 타입 에러가
			정확히 어떤 자식 클래스 타입의 예외 클래스가 던져진 것인지
			typeid().name() 으로 확인해볼 것!

			이는 cppreference.com 웹사이트에서도 확인할 수 있는데,
			(참고: https://en.cppreference.com/w/cpp/string/basic_string/resize)

			해당 웹페이지에는 std::string::resize() 메서드 내에서
			어떤 Exception 클래스를 던질 수 있는지 정리되어 있음.
		*/
		std::cout << typeid(exception).name() << std::endl; // class std::length_error

		/*
			이때, std::exception::what() 메서드는
			어떤 에러가 발생했는지 const char* 타입 c-style 문자열로 반환해 줌. 
		*/
		std::cerr << exception.what() << std::endl;
	}

    return 0;
}