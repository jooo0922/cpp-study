#include <iostream>

using namespace std;

class Something
{
public:
	int m_value = 0;

	// 그렇다고 해서, 실제 멤버변수를 수정하는 함수에다가 const 를 붙이면
	// 애초에 그 멤버함수 내에서 멤버변수를 수정하는 부분에서 컴파일 에러가 발생하기 때문에,
	// const 를 붙이는 게 다가 아니라 실제로도 멤버변수를 바꾸는 코드를 작성하면 안됨!
	//void setValue(int value) const
	void setValue(int value)
	{ 
		m_value = value; 
	}
	
	// 이렇게 멤버함수 선언부 맨 오른쪽에 const 를 붙이면,
	// 이 멤버함수가 'const' 라고 선언하는 것임.
	// 이것의 의미는, '이 멤버함수 안에서는 클래스 멤버변수를 바꾸지 않아요' 를 확실하게 보장하는 보증수표임!
	// -> 이렇게 const 를 붙여 클래스의 불변성을 보장하는 멤버함수를 '상수 멤버함수' 라고 함
	int getValue() const
	{ 
		return m_value; 
	}
};

int main()
{
	const Something something;

	// 클래스 인스턴스에 const 를 붙이면 .setValue() 같은 멤버 함수 사용 시 에러가 발생함.
	// why? 이 클래스로부터 만들어진 인스턴스는 const, 즉, 상수여서 바꿀 수 없는데,
	// setValue() 는 Something 클래스 내부의 멤버변수를 바꿔주는 함수니까!
	// 아, 결국 클래스에 const 를 붙이는 건 클래스 내부의 멤버변수들을 const 로 만드는 것과 동일한 효과구나!
	//something.setValue(3);

	// 엥? 그런데 getValue() 같은 멤버함수는 내부의 멤버변수를 바꾸지 않는데도 컴파일 에러가 나네?
	// why? const 가 붙은 클래스 인스턴스에서 에러가 나냐 안나냐는 멤버변수를 변경하느냐 아니냐로 따지는 게 아닌,
	// 멤버 함수에 const 가 붙냐 안붙냐로 판단하기 때문임! 
	// 나중에 복잡한 클래스를 짤 때, const 를 붙여줄 수 있는 멤버함수들은 모두 붙여줘야 디버깅하기 용이함.
	cout << something.getValue() << endl;

    return 0;
}