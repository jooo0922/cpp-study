// Chapter8_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Something
{
public:
	/* Inner Class (클래스 안의 클래스) 를 사용해서 클래스 내부에서 정적 멤버변수 초기화하기 */
	class _init
	{
	public:
		_init()
		{
			s_value = 9876;
		}
	};

private:
	static int s_value; // 정적 멤버 변수
	int m_value;

	static _init s_initializer; // 클래스 안에 또 다른 클래스(Inner Class) 타입 멤버를 정적 멤버로 정의

public:
	// 또한, 인스턴스 종속성이 없는 정적 멤버변수는
	// 인스턴스 생성과 별개로 초기화되어야 하므로,
	// 인스턴스가 생성되는 시점에 호출되는 생성자 함수에서 초기화하는 것도 불가능함!
	Something()
		: m_value(123) //, s_value(1024) 
	{}

	// 정적 멤버 함수로 getter 정의
	static int getValue()
	{
		// 아래 temp() 같은 일반적인 멤버함수에서 처럼
		// 정적 멤버 함수에서도 this 를 사용하면 컴파일 에러가 발생함!
		// 왜냐? this 자체가 해당 클래스로부터 생성된 특정 인스턴스의 주소값이 담긴 포인터 변수니까!
		// 정적 멤버함수는 인스턴스가 생성되기 이전에도 사용할 수 있어야 하므로, 
		// 인스턴스가 생성되지 않은 상황에서 특정 인스턴스의 주소값이 담긴 this 는 사용하지 못하겠지!
		//return this->s_value;

		// 같은 맥락에서 정적 멤버변수가 아닌 일반 멤버변수도 접근이 불가능함
		// 왜냐? 일반 멤버변수 또한 this 포인터를 통해서만 접근이 가능한 것이기 때문!
		//return m_value;
		//return this->m_value;

		return s_value;
	}

	int temp()
	{
		return this->s_value;
	}
};

int Something::s_value = 1024;

// 클래스 안의 정적 멤버변수인 Inner Class 를 생성함과 동시에,
// 정적 멤버인 Inner Class 의 생성자가 호출되어 Something 의 정적 멤버변수 s_value 가 자동으로 초기화 됨!
// 그래서 맨 위에서 1024 로 초기화 되었지만, Inner Class 생성자에서 정적 멤버변수 s_value 값이 9876 으로 다시 변경됨!
// -> 이 방식이 바로 c++ 클래스 내부에서 간접적으로 정적 멤버변수를 초기화하는 방법! > 조금 번거롭지만 가능은 하다!
Something::_init Something::s_initializer; 

int main()
{
	// 인스턴스를 생성하지 않고도 정적 멤버변수에 접근 가능! 
	// -> 이미 정적 메모리 레이아웃에 올라와있는 변수이기 때문!
	// 이게 아주 유용한 기능인데, 해당 멤버변수가 private 으로 캡슐화되어 있다면 무용지물..
	//cout << Something::s_value << endl;

	// 너무 아까운 기능인데, private 정적 멤버변수도 인스턴스 없이 바로 접근할 수는 없을까?
	// getValue() 같은 함수를 인스턴스 없이도 사용할 수 있다면 가능하지 않을까?
	// 이럴 때 사용할 수 있는 게 바로 '정적 멤버 함수'
	cout << Something::getValue() << endl;

	Something s1, s2;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl;


	/* 인스턴스 종속성 측면에서 정적 멤버함수 vs 일반 멤버함수 비교 */

	// 일반 멤버함수의 주소값 저장하기 (함수 포인터)
	// 
	// https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter8/Chapter8_07/Chapter8_07.cpp 에서,
	// 클래스 각 인스턴스의 멤버변수는 별도의 주소값에 할당되어 있지만,
	// 클래스의 멤버 함수는 하나의 메모리 공간 안에 할당되어 있고,
	// 여기에 각 인스턴스 주소값(this)을 넘겨받아서, 
	// '이 인스턴스에 있는 멤버변수들을 가지고 해당 함수를 작동시켜!' 라는 원리로 작동한댔었지?
	// 그래서 멤버함수의 주소값은 클래스로부터만 가져올 수 있는 것임!
	int (Something:: * fptr1)() = &Something::temp;

	// 일반 멤버함수 주소값을 de-referencing 하여 특정 인스턴스를 통해 해당 멤버함수를 호출하는 것이 가능함!
	// 이때, 특정 인스턴스 s2 를 통하지 않으면 일반 멤버함수는 호출이 불가능함.
	// why? 일반 멤버함수는 인스턴스 주소값(this)에 종속되는 형태로 구현되기 때문!
	cout << (s2.*fptr1)() << endl;

	// 이번에는 정적 멤버함수의 주소값을 저장해서 호출해보자
	// 정적 멤버함수 getValue() 는 Something 클래스 내에 정의되어 있기는 하지만,
	// 특정 인스턴스와 상관없이 실행할 수 있기 때문에, 특정 인스턴스와 상관없이 실행할 수 있는 함수 포인터로 저장하려면
	// 함수 포인터 타입 정의 시, 'Something::' 을 제거해야 함!
	int (* fptr2)() = &Something::getValue;

	// 정적 멤버함수 주소값을 de-referencing 하여 실행시켜보자
	// 이때, 위의 fptr1 일반 멤버함수 포인터와 달리 특정 인스턴스를 통하지 않고서도 실행 가능함!
	cout << fptr2() << endl;


	return 0;
}