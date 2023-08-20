#include <iostream>

using namespace std;

int main()
{
	cout << "While-loop test" << endl;

	//int count = 0; // while 문은 몇 번 반복하는지 세어 줄 count 정수형 변수가 필요

	//while (1)
	//{
	//	//static int count = 0; // 만약, 반복문 안에 count 변수를 정 넣어야 겠으면, static 변수로 선언하면 됨. > 반복문의 최초 루프에서만 메모리 공간이 할당 및 초기화됨. (Chapter4_2.cpp)
	//	cout << count << endl;

	//	++count;

	//	if (count == 10) break; // while 의 조건문을 사용하지 않고 반복문을 탈출하고 싶을 경우, break 사용!
	//}

	// 이런 식으로, unsigned int 가 그냥 int 보다 계산이 빠르기는 하지만,
	// count 를 반복문에서 차감시키는 식으로 사용할 경우, 음수값 표현이 안되다보니
	// 반복문에서 예기치 못한 무한 루프가 생성되어 버림.
	//unsigned int count = 10;

	//while (count >= 0)
	//{
	//	if (count == 0) cout << "zero";
	//	else cout << count << " ";

	//	count--; // 반대로 count 변수를 1씩 차감시키는 반복문
	//}

	//int count = 1;

	//while (count < 100)
	//{
	//	// 반복문에서 5번에 한 번씩 뭔가를 하고 싶을 경우, 나머지 연산자 사용!
	//	if (count % 5 == 0) cout << "Hello" << count << endl;

	//	count++;
	//}

	// 중첩 while 문
	int outer_count = 1;

	while (outer_count <= 5)
	{
		int inner_count = 1;
		while (inner_count <= outer_count)
		{
			cout << inner_count++ << " ";
		}

		cout << endl;

		++outer_count;
	}

    return 0;
}