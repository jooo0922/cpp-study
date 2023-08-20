#include <iostream>

using namespace std;

int main()
{
	int selection; // do-while 문 바깥에 선언되어야 함. > do 블록 안에 선언해두면, 해당 블록이 끝날 시, while 조건문에서 selection 변수에 접근이 불가하기 때문!

	// 1, 2, 3, 4 중에 하나를 입력받을 때까지 계속 입력 요청을 하는 프로그램
	// 그래서 일단 한 번은 무조건 입력 요청을 받아야 하기 때문에, 
	// 일단 무조건 실행을 하고 나서 반복문 조건을 따지는 do-while 문 사용이 적합!
	do
	{
		cout << "1. add" << endl;
		cout << "2. sub" << endl;
		cout << "3. mult" << endl;
		cout << "4. div" << endl;
		cin >> selection;
	} while (selection <= 0 || selection >= 5); // do-while 에서는 while 문 끝에 무조건 세미콜론을 붙여야 됨.

	cout << "You selected " << selection << endl;

	return 0;
}

