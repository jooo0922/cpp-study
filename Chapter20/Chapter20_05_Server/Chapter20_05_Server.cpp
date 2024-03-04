#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp> // asio 를 사용한 TCP/IP 네트워킹 구현을 위해 포함

/* asio 를 사용하여 서버-클라이언트 모델을 구현해보자 */

// tcp 네임스페이스 선언
using boost::asio::ip::tcp;

int main()
{
	/*
		네트워크 프로그래밍에서는
		여러 가지 불안정적인 상황을 고려해야 하므로,
		대부분 예외 처리를 사용하는 것이 필수!

		또, 네트워크 프로그래밍은
		네트워크 과목을 공부해야 이해할 수 있는 부분들이 있으므로,
		
		이 예제를 모두 이해하려고 하지 말고,
		대략적인 원리만 파악하는 정도만 해도 충분함. 
	*/
	try
	{
		// io_service 선언
		boost::asio::io_service io_service;

		/*
			endpoint 선언

			endpoint 란,
			통신의 주체가 되는 양 끝점을 의미함.

			즉, 종이컵 전화기에서 양 끝에 위치하는
			두 종이컵과도 같음.

			이때, tcp ver4 를 사용하기 위해
			tcp::v4() 를 첫 번째 파라미터로 전달하고,
			
			두 번째 파라미터로 전달하는 숫자 13은
			'통신에 사용할 포트번호' 라고 보면 됨.
		*/
		tcp::endpoint endpoint(tcp::v4(), 13);

		// acceptor 생성
		tcp::acceptor acceptor(io_service, endpoint);

		// 서버가 시작되었음을 알림
		std::cout << "Server started" << std::endl;

		// 무한 loop 생성 (while(true) 와 같음)
		/*
			서버는 이 사람 접속했다가
			저 사람 접속했다가 하는 식으로

			끊임없이 접속이 발생하므로,
			기본적으로 무한 루프 내에서 작업을 처리하는 경우가 많음.

			-> 즉, 클라이언트가 서버에 접속을 성공할 때까지
			무한루프로 계속 접속 시도 작업을 돌리는 것!
		*/
		for (;;)
		{
			// 서버에 접속한 클라이언트에게 보낼 메시지 선언
			const std::string message_to_send = "Hello From Server";

			/*
				boost::asio 라이브러리를 사용하면,
				입출력 스트림인 IOStream 을 네트워크 프로그래밍에도 적용 가능!
			*/
			boost::asio::ip::tcp::iostream stream;

			// 디버깅 메시지 1
			std::cout << "check 1" << std::endl;

			// 나타날 에러 코드를 미리 선언
			boost::system::error_code ec;

			/*
				클라이언트가 서버로 접속하면,
				acceptor 를 통해 스트림 버퍼를 읽어내겠다는 뜻
			*/
			acceptor.accept(*stream.rdbuf(), ec);

			// 디버깅 메시지 2
			std::cout << "check 2" << std::endl;

			// 에러 코드가 없다? -> 클라이언트가 서버에 성공적으로 접속했을 때의 처리!
			if (!ec)
			{
				/*
					클라이언트가 보낸 메시지를 
					스트림 버퍼로부터 한 줄씩 읽어들여서 출력

					이때의 스트림 버퍼는
					콘솔 입출력용 IOStream 이 아니고,

					boost::asio::ip::tcp::iostream 이라는 점을 명심할 것!

					-> 즉, 스트림 버퍼의 타입이 네트워크 입출력용으로 완전 다르지만,
					다른 타입의 스트림 버퍼들처럼 std::getline() 같은 함수들을
					호환성있게 사용할 수 있다는 것임!
				*/
				std::string line;
				std::getline(stream, line);
				std::cout << line << std::endl;

				/*
					이번에는
					서버에서 클라이언트로 메시지를 전송해보자.

					boost::asio::ip::tcp::iostream 스트림 버퍼에
					문자열 메시지를 전송할 때에도,

					<< (입력 스트림 연산자) 를 호환성있게 사용할 수 있음.
				*/
				stream << message_to_send;
				stream << std::endl;
			}
		}
	}
	catch (std::exception& e)
	{
		// 던져진 에러의 내용을 출력함
		std::cerr << e.what() << std::endl;
	}
    return 0;
}