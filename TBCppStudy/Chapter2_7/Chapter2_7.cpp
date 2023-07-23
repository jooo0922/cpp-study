#include <iostream>
#include <limits> // 컴파일러에게 물어보는 함수가 담긴 라이브러리가 <limits>

int main()
{
	using namespace std;

	/*
		char 타입은 '한 글자'만 다룸.
		그래서 사이즈가 1 Byte 로 작음.

		그래서 여러 글자인 문자열을 표현할 때에는
		char 타입을 배열 형태로 사용하거나,
		std::string 을 사용하는 경우가 많음.
	*/
	char c1(65); // c1 = 65; c1{65}; 이렇게 초기화하는 것도 가능!
	char c2('A'); // 한 글자만 표현할 때에는 작은 따옴표 '' 를 사용하고, 문자열을 표현할 때에는 큰 따옴표 "" 를 사용함. ex> "Hello, World"

	// int(c1), int(c2) 는 캐스팅(형변환)으로, char 타입에 저장된 대문자 A 를 정수형 타입의 아스키코드로 형변환해서 출력 
	// 이런 식으로, 1 Byte 짜리 아주 작은 정수형을 저장할 때 char 타입을 사용하기도 함.
	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;

	// c-style casting (c언어에서 사용되는 캐스팅 문법)
	cout << (char)65 << endl; // A
	cout << (int)'A' << endl; // 65

	// c++ style casting 
	cout << char(65) << endl; // A
	cout << int('A') << endl; // 65

	// 위 방식들은 강제 형변환 느낌이 강하고, 
	// static_cast 는 컴파일러에게 기본 타입 간 변환에 문제가 없는지 체크를 먼저 해달라고 함.
	// 나중에 다이내믹 캐스팅 관련해서 다시 설명한다고 하니 지금은 이 정도로 알아둘 것.
	cout << static_cast<char>(65) << endl;
	cout << static_cast<int>('A') << endl;

	char ch(97);
	cout << ch << endl; // a
	cout << static_cast<int>(ch) << endl; // 97 (소문자 a 의 아스키코드가 97인가 보네.)
	cout << ch << endl; // a (static_cast를 해서 형변환 하더라도, 원래 변수에 저장된 값이 바뀌지는 않는군)

	//cin >> c1;
	//cout << c1 << " " << static_cast<int>(c1) << endl;

	/*
		char 타입은 1글자만 입력받을 수 있겠지?

		그런데 만약, abc 같이 여러 글자의 문자열을 입력하면 어떻게 될까?
		실제로 cout 으로 출력하면 첫 번째 글자인 a 에 대해서만 출력 및 형변환 출력됨.

		그렇다면 나머지 bc 는 날라간 것일까?

		No!
		>>, << 같은 steam operator 는
		입력받은 값을 버퍼에 저장해 둠.

		그래서 미처 처리하지 못한 값들을 버퍼에 저장해 뒀다가,
		처리가 끝나면 컴퓨터가 버퍼에 저장된 값들을 다시 받아서 쓰는 식으로 되어있음.

		즉, 버퍼 안에 bc, 가 남아있음.

		그래서 아래와 같이 두 번째 cin 출력에서 입력값을 받지 않고,
		버퍼에 저장된 b 를 가져다가 순차적으로 처리함.
	*/
	//cin >> c1;
	//cout << c1 << " " << static_cast<int>(c1) << endl;

	cout << sizeof(char) << endl;
	
	// 각 타입이 표현할 수 있는 가장 최대, 최소, 가장 작은 수(max(), min(), lowest())를
	// (즉, 아스키코드의 최대, 최솟값이겠지)
	// 컴파일러에게 물어보자 (std namespace 선언되어 있으니 생략)
	cout << (int)std::numeric_limits<char>::max() << endl; // 127
	cout << (int)std::numeric_limits<char>::lowest() << endl; // -128
	cout << (int)std::numeric_limits<unsigned char>::max() << endl; // 255
	cout << (int)std::numeric_limits<unsigned char>::lowest() << endl; // 0

	// 콘솔 출력 개행 문자인 \n 의 아스키코드는 뭘까?
	cout << int('\n') << endl; // \n 은 한글자로 인식되기 때문에 작은 따옴표 ''를 사용 > 아스키코드는 10으로 형변환되어 출력
	cout << "This is first line \nsecond line\n";
	cout << "This is first line " << endl;
	cout << "second line";

	/*
		\n 과 endl 의 차이점은 뭘까?

		\n 은 단지 줄바꿈.

		endl 은 줄바꿈과 동시에 cout 버퍼에 있는 내용을 일단 화면에 다 출력하라는 뜻!
		실제로, 버퍼에만 담기고 콘솔에는 출력이 안되는 경우가 있음.

		이러한 차이가 있다는 정도만 알아둘 것.

		참고로, std::flush 라는 것도 있는데,
		얘는 줄바꿈은 하지 않고, 버퍼에 있는 내용을 다 출력하라는 의미를 갖고 있음.
	*/

	// 문자열에 탭 넣어서 출력하기
	cout << int('\t') << endl;
	cout << "This is first line \tsecond line \""; // 만약 콘솔 출력에서 큰 따옴표 " 를 출력하고 싶다면, \" 으로 입력해야 컴파일러가 하나의 큰 따옴표 문자로 인식해서 문자열 따옴표 "" 와 구분해서 출력해 줌.
	cout << "This is first line \asecond line \""; // \a 는 소리를 내줌.

	// windows 에서 많이 사용하는 wchar_t
	// 그러나 많은 개발자들이 사용하는 데 좀 회의적이고 골치아픈 타입이라고 함.
	wchar_t c;
	
	// 아스키코드 외에, 이모티콘같이 종류가 훨씬 더 많은 유니코드를 저장할 때 사용하는 타입
	char16_t c3;
	char32_t c3;

	return 0;
}
