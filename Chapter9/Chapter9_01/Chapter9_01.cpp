#include <iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; };
	int getCents() const { return m_cents; }

	// 연산자 오버로딩 프로토타입을 friend 멤버로 등록해놓으면, 해당 연산자 오버로딩 내에서 private 멤버에도 접근 가능!
	// getCents() 같은 getter 를 사용할 필요가 없어져서 더 편함
	//friend Cents operator + (const Cents& c1, const Cents& c2)
	//{
	//	// 또한, 이왕 friend 멤버로 등록해놓은 김에 구현부까지 클래스 블록 안으로 옮겨놓으면 더 보기 좋겠지
	//	return Cents(c1.m_cents + c2.m_cents);
	//};

	// friend 로 등록할 게 아니라, 아예 연산자 오버로딩 자체를 멤버 함수로 등록하는 것은 안되나? 당연히 됨!
	// 참고로, 아예 '멤버함수의 형태로만' 오버로딩이 가능한 연산자들은 =, [], (), -> 등이 존재...
	Cents operator + (const Cents& c2)
	{
		// 단, 조건이 있음! 산술연산자 오버로딩 시, 매개변수는 1개로 제한됨.
		// 엥? + 는 이항 연산자니까 더하려면 2개의 값이 필요할텐데?
		// 그렇기 한데, 연산자 오버로딩이 멤버함수로 들어왔다면, 그 2개 중 하나는 '자기 자신(this)' 으로 표현할 수 있잖아!
		return Cents(this->m_cents + c2.m_cents);
	}
};

// 이것이 Cents 인스턴스 간 + 연산자를 사용할 때 어떤 기능을 수행할 것인지 오버로딩한 '연산자 오버로딩'
//Cents operator + (const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.getCents() + c2.getCents());
//}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	// 두 개의 Cents 클래스 인스턴스를 더하고 싶다면 어떻게 할까?
	// 즉, 내가 만든 자료형(user defined data type)을 원시 자료형처럼 연산하고 싶다면?
	// 방법이야 여러 가지가 있겠지만, 여기에 가장 적합한 방법은 '산술 연산자 오버로딩'을 활용하는 것!
	cout << (cents1 + cents2 + Cents(6) + Cents(10) + Cents(10)).getCents() << endl;

	return 0;
}

/*
	참고로, 오버로딩이 안되는 연산자들
	
	- ? : (삼항 연산자)
	- :: (scope 연산자)
	- sizeof (sizeof 연산자)
	- . (member selection 연산자)
	- .* (member pointer selection 연산자)

	또한, 연산자 자체를 오버로딩하여 변경할 수는 있지만.
	'연산자 우선순위' 는 개발자가 멋대로 바꿀 수 없다!

	즉, 개발자가 아무리 오버로딩으로 연산자를 재정의 했더라도,
	연산자 우선순위는 기존 순서를 따름. 
*/