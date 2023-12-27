#include "MyArray.h"

// 클래스 밖으로 빼낸 멤버함수를 헤더파일 -> .cpp 파일로 이동
/*
	이때, 이 상태 그대로 빌드하면 'linking error' 가 발생함.

	왜냐?

	헤더파일에 정의된 MyArray 클래스의
	print() 멤버함수의 구현부가 
	MyArray.cpp 에 존재하기 때문에

	Chapter13_02.cpp > main() 함수에서
	template parameter 를 꺽쇠 안에다가
	'MyArray<double>' 이런 식으로 전달을 하더라도,

	Chapter13_02.cpp 에는 MyArray.h 헤더파일만 
	include 되어있기 때문에,

	MyArray.cpp 파일 내에서는
	어떤 template parameter 타입으로
	template instantiation 을 하려는 지 알 수가 없음!

	그래서 이 print() 멤버함수의 구현부를 컴파일할 때,
	template parameter 를 알 수 없어
	linking error 가 발생했던 것임!
*/

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; i++)
	{
		cout << m_data[i] << " ";
	}
	cout << endl;
}

/*
	그럼, 위와 같은 상황에서는 어떻게 해결해야 하는데?

	MyArray.cpp 에 있는
	멤버함수의 구현부 코드들을 컴파일할 때,

	아래와 같이
	특정한 자료형으로 template parameter 를
	컴파일해야 한다고 알려줘야 함.

	이를 explicit instantiation 이라고 함!

	원래대로 라면, 이러한 instantiation 작업들을
	컴파일러가 알아서 처리해줬는데,

	지금과 같이 멤버함수의 구현부가
	다른 파일에 분리되어 있는 경우에는
	프로그래머가 직접 instantiation 타입을 '명시'해줘야 함!
*/
//template void MyArray<double>::print();

/*
	그러나,
	
	위와 같이 할 경우,
	다른 멤버함수들도 일일이 
	explicit instantiation 해주기 귀찮으니,
	
	그냥 클래스 자체를 explicit instantiation
	처리해주는 게 낫겠지!
*/
template class MyArray<double>;