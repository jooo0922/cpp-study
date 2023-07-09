#include <iostream>

using namespace std;

// 함수를 3개씩이나 만들었더니 main 함수가 아래로 내려가서 잘 안보임 > 불편하지?
// 그리고 함수를 이것보다 더 만들다보면 눈에 잘 안들어오기도 함.
// 그렇다고, main 함수들을 이 함수들보다 위로 가져오면 컴파일에 실패함 > why? js 와 달리 컴파일러가 함수 호이스팅을 지원하지 않음!

// 그렇다면, 그냥 main 함수를 선언하기 전에 add 라는 함수가 있다 라는 것만 알려주면 되는 거 아닌가? 
// add 라는 함수가 있다는 걸 알려주려면, 최소한으로 입력이 뭐고 출력이 뭐다 정도만 알려주면 되겠지?
// 그렇게 된다면, 그 함수가 정확히 어떤 기능을 할지는 몰라도, 입력과 출력이 뭔지 최소한의 정보만 있으면 컴파일러가 알 수 있음!
// 이런 식으로 함수의 최소한의 정보만 포함해서 선언해두는 걸 "프로토타입" 이라고 함!

// 아래와 같이 함수의 프로토타입만 앞에 선언해놓는 걸 전방선언(forward declaration) 이라고 함.
int add(int a, int b); 
int multiply(int a, int b);
int subtract(int a, int b);

int main()
{
	cout << add(1, 2) << endl;
	cout << subtract(1, 2) << endl;

	return 0;
}

// 실제 기능을 수행하는 함수 전체가 함수의 정의(definition) 이라고 함.
int add(int a, int b)
{
	return a + b;
}

int multiply(int a, int b)
{
	return a * b;
}

int subtract(int a, int b)
{
	return a - b;
}

