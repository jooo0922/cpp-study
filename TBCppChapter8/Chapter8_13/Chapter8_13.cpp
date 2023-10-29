#include <iostream>

using namespace std;

class A
{
public:
	void print()
	{
		cout << "Hello" << endl;
	}

};

int main()
{
	// 이렇게 print() 멤버함수를 실행하려면 A 클래스 인스턴스를 매번 특정 변수에 선언하기 귀찮지?
	//A a;
	//a.print();

	// 그래서, 특정 변수에 저장되지 않는 객체를 곧바로 생성해서 print() 멤버 함수를 호출할 수도 있음
	// 이 때, 'A()' 와 같은 것을 '익명 객체' 라고 함. 
	// 물론, 익명 객체는 한 번 사용하고 나면, 특정 변수에 저장된 것이 아니기 때문에 재사용 불가!
	A().print();

    return 0;
}