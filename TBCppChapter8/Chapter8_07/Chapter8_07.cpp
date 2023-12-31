#include <iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		// 생성자에서 생성된 인스턴스 자신의 주소값을 직접 찍어보기
		// 이 때 사용되는 것이 this!
		// 이처럼, this 를 사용하면 인스턴스 자신의 주소가 뭔지 클래스 내부에서 확인할 수 있음!
		cout << this << endl;
		
		// 그래서 아래와 같은 클래스 메서드를 호출할 때에는,
		// 모든 인스턴스들이 Simple 이라는 클래스에 정의된 setID() 함수를 가리키지만,
		// 이를 구분하기 위해, 정확히는 this->setID(), 
		// 즉, this 에 정의된 setID() 함수를 사용하는 것이라고 볼 수 있음.
		// 왜냐하면, 인스턴스가 생길 때마다 setID() 같은 함수들을 새로 메모리에 올려두고 쓰는 건 낭비잖아.
		// 그러니까 이미 Simple 클래스에 정의된 setID() 를 사용하되,
		// 내부적으로 그 클래스로부터 생성된 인스턴스의 주소값(this)를 넘겨주면서 setID() 를 호출하도록 작동하고 있음!
		setID(id);
		//this->setID(id); // 위 메서드를 호출하는 것은 결국 this-> 가 숨겨진 것과 같다!
		//(*this).setID(id); // 또는, de-referencing 을 통해서 직접적인 멤버 접근자 . 을 사용할수도 있음
		
		this->m_id; // 마찬가지로 this를 통해 멤버 변수에도 접근 가능!
	}

	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}

	// 이 메서드들은 반환타입이 클래스 자신의 '참조변수'로 선언됨. (포인터 변수 아님 주의!)
	// (참조변수 관련 https://github.com/jooo0922/cpp-study/blob/main/TBCppStudy/Chapter6_14/Chapter6_14.cpp 참고)
	// 즉, 실제 값(인스턴스)이 저장된 변수를 반환해야 하므로, 
	// 인스턴스 자신의 주소값이 담긴 this 를 de-referencing 하여 실제 인스턴스 자신을 반환함.
	// 이처럼, 메서드 마지막에 인스턴스 자신(*this)을 반환하면, 해당 함수를 멤버함수 체이닝에 사용할 수 있음!
	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }

	void print()
	{
		cout << m_value << endl;
	}
};

int main()
{
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);

	// 두 인스턴스 s1, s2 를 어떻게 구분할까?
	// 가장 간단한 방법은 두 인스턴스의 주소를 찍어보는 것
	cout << &s1 << " " << &s2 << endl;


	/* 인스턴스 자신(*this)를 반환하는 메서드를 활용한 멤버함수 연쇄 호출(member function chaining) */
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print();

    return 0;
}
