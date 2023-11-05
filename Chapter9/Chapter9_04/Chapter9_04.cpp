#include <iostream>
#include <random> // vector 동적 배열을 랜덤하게 섞는 기능 사용을 위해 포함
#include <vector> // vector 동적 배열 사용을 위해 포함
#include <algorithm> // sort() 정렬 알고리즘 사용을 위해 포함

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; };
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out;
	}

	/* 비교 연산자 오버로딩 */
	// 친구함수로 등록해서 오버로딩
	friend bool operator == (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}

	// std::sort() 내의 비교함수에서 사용하기 위한 크기 비교 연산자 오버로딩
	// 이때, sort() 내의 비교함수에서는 '>' 가 아닌 '<' 를 사용하므로,
	// '<' 비교 연산자를 오버로딩 해줘야 정상 작동함!
	friend bool operator < (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents < c2.m_cents;
	}
};

int main()
{
	Cents cents1(6);
	Cents cents2(6);

	/* 비교 연산자 오버로딩 테스트 */

	if (cents1 == cents2)
	{
		cout << "Equal " << endl;
	}


	/* 오버로딩한 비교 연산자를 사용해서 sort 알고리즘의 비교 함수에 적용하는 예시 */

	vector<Cents> arr(20);
	for (unsigned int i = 0; i < 20; ++i)
	{
		// 여기서의 getCents() 는 m_cents 멤버를 참조변수로 반환하므로, 
		// 할당한 값 i 가 멤버변수 m_cents 를 실제로 변경시킴.
		arr[i].getCents() = i; 
	}

	// 동적 배열 랜덤하게 섞어주기
	std::random_device rd; // 난수 생성에 필요한 seed 값 생성
	std::mt19937 g(rd()); // mt19937 알고리즘 기반의 32 bits 난수 생성기에 seed 값 넘겨주면서 생성
	std::shuffle(begin(arr), end(arr), g); // 난수 생성기를 기반으로 동적 배열을 섞어줌

	// for-each 문으로 섞인 동적 배열 출력
	for (auto& e : arr)
	{
		cout << e << " ";
	}
	cout << endl;

	// sort() 알고리즘을 그대로 사용하면 에러가 발생함.
	// why? arr 동적 배열은 Cents 클래스의 인스턴스들이 담긴 동적 배열이기 때문!
	// sort() 알고리즘은 기본적으로 정수형 요소 간 크기 비교를 통해 정렬을 수행함!
	// 따라서, Cents 클래스 인스턴스 간 크기 비교에 대한 연산자 오버로딩을 정의해주면,
	// 이를 비교함수에서도 적용하여 정상작동 할 수 있겠지!
	std::sort(begin(arr), end(arr));

	// for-each 문으로 std::sort() 정렬 알고리즘으로 정렬된 동적 배열 출력
	// 참고로, c++ 의 std::sort() 는 c 언어의 qsort() 와 달리 퀵 정렬 알고리즘에만 의존하지는 않고,
	// 다양한 정렬 알고리즘을 기반으로 구현되어 있음!
	for (auto& e : arr)
	{
		cout << e << " ";
	}
	cout << endl;

    return 0;
}