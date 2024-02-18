#include <iostream>
#include <string>
#include <regex> // c++ 11 부터 도입된 정규 표현식(regular expression)

using namespace std;

int main()
{
	/*
		입력값이 원하는 형식에 맞게 들어왔는지 검증하려면,
		c++ 11 부터 도입된 '정규 표현식'을 사용하면 됨!

		ex> 이메일 주소, 전화번호, 암호 등의 입력값이
		의도한 포맷에 맞게 입력되었는지 확인할 때 등...
	*/


	/* 검증할 포맷을 정의하기 위해 std::regex 변수를 선언 */ 
	
	// "\d" 는 'digit', 즉, 한 자릿수의 숫자인 지 검증하는 정규 표현식 (여러 자릿수의 숫자는 match 에 실패하겠지?)
	// (참고로, 첫 번째 백슬래쉬 "\" 는, 뒤에 나오는 두 번째 백슬래쉬 "\" 가 '진짜 백슬래쉬로 쓰임'을 표시하기 위한 것이라고 함.)
	//regex re("\\d");

	// 1개 이상의 digit 인지 검증하는 정규 표현식
	//regex re("\\d+");

	// 대괄호 안에 들어있는 문자들만 개별적으로 match 시키는 정규 표현식
	//regex re("[ab]");

	// 3자릿수의 digit 만 match 시키는 정규 표현식 ([:digit:] 은 "\\d" 과 같은 표현!)
	//regex re("[[:digit:]]{3}");

	// 1개 이상의 A-Z 까지의 대문자 알파벳을 검증하는 정규 표현식
	//regex re("[A-Z]+");

	// A-Z 까지의 대문자 알파벳이 최소 1개, 최대 5개까지 입력되었는 지 검증하는 정규 표현식
	regex re("[A-Z]{1,5}");


	// 입력 스트림 cin 으로 흘러들어간 문자열을 한 줄씩 저장할 std::string 문자열 변수
	string str;

	while (true)
	{
		/*
			std::getline(std::istream, std::string)

			std::cin 같은 입력 스트림으로 흘러들어온 문자열을
			개행문자 '\n' 를 기준으로 한 줄씩 읽어들여서
			
			두 번째 매개변수로 전달된 
			std::string 타입의 문자열 변수에
			저장하는 함수
		*/
		getline(cin, str);

		/*
			std::regex_match(std::string, std::regex)

			첫 번째 매개변수로 입력받은 
			std::string 타입의 문자열이
			
			두 번째 매개변수로 입력받은
			std::regex 타입의 정규표현식에 정의된 포맷에
			일치하는지 검사하는 함수

			-> 이처럼 정규표현식을 사용하면
			입력값의 유효성, 포맷을 검사하는 게 훨씬 수월함.

			오히려, 검증하고자 하는 포맷을
			정규표현식으로 어떻게 정의할 것인지가
			좀 더 까다로운 부분이라고 볼 수 있음.
		*/
		if (std::regex_match(str, re))
		{
			cout << "Match" << endl;
		}
		else
		{
			cout << "No match" << endl;
		}

		/*
			std::sregex_iterator 반복자를 통해,
			
			검사한 std::string 문자열 안에서도
			정규 표현식에 부합하는 문자들만 
			별도로 출력해주는 예제 코드
		*/
		{
			auto begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto end = std::sregex_iterator();
			for (auto itr = begin; itr != end; ++itr)
			{
				std::smatch match = *itr;
				cout << match.str() << " ";
			}
			cout << endl;
		}

		cout << endl;
	}

	return 0;
}