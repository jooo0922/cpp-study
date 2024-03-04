#include <iostream>
#include <string>
#include <boost/asio.hpp> // asio 를 사용한 TCP/IP 네트워킹 구현을 위해 포함

/* asio 를 사용하여 서버-클라이언트 모델을 구현해보자 */

// tcp 네임스페이스 선언
using boost::asio::ip::tcp;

/*
	클라이언트 단에서는 특이하게
	명령줄 인수로 서버의 주소를 입력받게 됨!

	즉, 프로젝트 > Properties > Debugging > Command arguments
	에 설정한 내 컴퓨터의 ip 주소인
	127.0.0.1 이 명령줄 인수로 입력될 것임!
*/
int main(int argc, char* argv[])
{
    /* 이 프로젝트에서는 클라이언트 단 작업을 구현할 것임 */
	try
	{
		/*
			내 컴퓨터의 ip 주소를 포함하는
			명령줄 인수의 갯수가 맞지 않을 경우,
			
			명령줄 인수를 제대로 입력하는 방식을
			에러로 출력하고 try 문을 탈출함.
		*/
		if (argc != 2)
		{
			std::cerr << "Usage: client <host>" << std::endl;
			return 1;
		}

		/*
			명령줄 인수로 ip 주소가 제대로 들어왔다면,
			tcp::iostream 에 입력받은 주소를 전달함.

			두 번째 매개변수는 서버 단에서
			endpoint 에 설정한 '통신에 사용할 포트번호'인
			13 을 전달함.
		*/
		tcp::iostream stream(argv[1], std::to_string(int(13)));
		
		/*
			만약, 하드웨어적인 문제나 여러 네트워크 상태에 의해
			네트워크 입출력 스트림이 제대로 만들어지지 않았다면,
			에러를 출력하고 try 문 종료함
		*/
		if (!stream)
		{
			std::cout << "Unable to connect: " << stream.error().message() << std::endl;
			return 1;
		}

		/*
			일반적인 입출력 스트림에서 사용하듯이
			입력 스트림 연산자(<<) 를 통해
			네트워크 스트림으로 서버에 전송할 메시지를 흘려보냄
		*/
		stream << "Hello from client";
		stream << std::endl;

		/*
			서버 단 구현에서
			'클라이언트로부터 먼저 메시지를 받고,
			그 다음에 서버로부터 메시지를 전달하도록'
			전송 순서를 정의해놓았기 때문에,

			클라이언트 단 구현에서도
			서버에 메시지 전송을 먼저 정의하고,
			그 다음에 서버로부터 메시지를 받아서 읽는 작업을 구현한 것임!
		*/
		std::string line;
		std::getline(stream, line);
		std::cout << line << std::endl;
	}
	catch (std::exception& e)
	{
		// 던져진 에러의 내용을 출력함
		std::cout << "Exception: " << e.what() << std::endl;
	}
    return 0;
}