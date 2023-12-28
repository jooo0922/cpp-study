#pragma once

#include <assert.h> // for assert()
#include <iostream>

using namespace std;

/*
	Non-type Template Parameters
	(자료형이 아닌 템플릿 매개변수)

	아래 클래스 템플릿에서
	두 번째 매개변수인 T_SIZE 가 바로
	Non-type Template Parameters 라고 보면 됨.

	이는 built-in 자료형이나 class, struct 등의
	user-defined 자료형을 일반화한 템플릿 매개변수가 아닌,
	
	특정 타입으로 지정됨에 따라, 
	그 타입에 해당하는 모든 literal 값을
	받을 수 있도록 '리터럴을 일반화한' 템플릿 매개변수라고 보면 됨.

	ex> std::array<double, 100> 에서 두 번째 템플릿 매개변수 100 이
	배열의 크기를 지정하는 Non-type Template Parameters 로 보면 되겠지!
*/
template<typename T, unsigned int T_SIZE>

class MyArray
{
private:
	//int m_length; // 배열 크기 > non-type template parameter 로 대체

	// 배열 첫 번째 요소 포인터 멤버변수
	/*
		이렇게 템플릿으로 타입을 지정하면,

		'이 정적 배열은 int, float, class 등 어떤 타입이라도 가능하다'
		라고 선언한 것으로 보면 됨!
	*/
	T* m_data;

public:
	// 생성자 함수
	MyArray()
	{
		// 배열 힙 메모리 동적 할당
		m_data = new T[T_SIZE];
	}

	// 소멸자 함수
	~MyArray()
	{
		// 소멸자 함수에서 배열에 동적 할당된 메모리 반납
		delete[] m_data;
	}

	// [] 연산자 오버로딩
	T& operator[](int index)
	{
		// assert() 함수로 입력받은 index 가 유효한 지 검사
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	// 배열 크기 getter
	int getLength()
	{
		return T_SIZE;
	}

	// 배열 요소 출력 멤버함수
	/*
		non-type template parameter 를 사용할 경우,
		멤버함수 구현부를 explicit instantiation 으로 .cpp 파일에 분리시킬 수 없음!

		why? 

		위에 T_SIZE 는
		말 그대로 unsigned int 타입이면 뭐든 들어올 수 있는거기 때문에,
		
		explicit instantiation 을 처리할 거라면
		모든 unsigned int (ex> 1, 2, 3, 4, 5, ...) 에 대해
		전부 explicit instantiation 선언을 해줘야 함.

		이거는 현실적으로 불가능하겠지?

		그렇기 때문에,
		non-type template parameter 를 사용하는 멤버함수가 있다면,
		그냥 클래스 내부에 구현부를 정의해두는 것이 맞겠지!
	*/
	void print()
	{
		for (int i = 0; i < T_SIZE; i++)
		{
			cout << m_data[i] << " ";
		}
		cout << endl;
	}
};
