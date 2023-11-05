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


	/* 오버로딩한 비교 연산자를 사용해서 qsort 알고리즘의 비교 함수를 구현하는 예시 */

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

    return 0;
}