#include <iostream>

using namespace std;

void breakOrReturn()
{
	while (true)
	{
		char ch;
		cin >> ch;

		if (ch == 'b')
		{
			break; // while 문만 탈출 > 아래 "Hello" 가 출력됨.
		}

		if (ch == 'r')
		{
			return; // 함수 전체를 탈출 > 아래 "Hello" 출력이 실행되지 않음.
		}
	}

	cout << "Hello" << endl;
}

int main()
{
	//breakOrReturn();

	//for (int i = 0; i < 10; i++)
	//{
	//	if (i % 2 == 0) continue; // i 가 짝수이면 현재의 for 문 순회를 건너뛴다! > continue 는 아랫부분을 실행시키지 않고, i++ 로 건너뜀!

	//	cout << i << endl;
	//	//if (i == 5) break; // for 문 안에서 break 사용하여 탈출
	//}

	int count(0);

	//do
	//{
	//	if (count == 5) 
	//		continue; // 아래줄 실행 안하고 다음 루프로 건너뜀.

	//	cout << count << endl;

	//	// count++; // continue 밑에서 count 를 증가시키면 continue 에 의해 무시되어서 count 가 계속 5로 남게 되어 무한루프에 빠짐.
	//} while (++count < 10); // do 블록이 아닌 while 조건문에 count 를 증가시킨 이유는, do 에서 증가시키면 continue 아랫줄을 실행 안시키므로, 무한 루프에 빠져버림.

	//bool escape_flag = false; // while 문 탈출 플래그 변수

	while (true /*!escape_flag*/)
	{
		char ch;
		cin >> ch;
	
		if (ch == 'x')
			//escape_flag = true; // 콘솔 입력으로 x 입력 시, 탈출 플래그를 true 로 전환하여 while 문 탈출
			break; // 탈출 플래그를 사용하지 않고 break 문으로도 동일한 기능 구현 가능

		cout << ch << " " << count++ << endl;
	}

    return 0;
}
