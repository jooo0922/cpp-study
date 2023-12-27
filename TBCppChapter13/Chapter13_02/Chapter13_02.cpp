#include "MyArray.h"

int main()
{
	/*
		클래스 템플릿을 사용할 경우,
		해당 클래스 타입의 변수 및 인스턴스를 선언할 때,

		꺽쇠 <> 안에
		'template argument list(== template parameter)'
		라고 하는, 
		
		이 클래스가 Template Instantiation 할
		구체적인 타입을 지정해줘야 함!
	*/
    MyArray<double> my_array(10);

	// MyArray 클래스의 배열 요소들 할당
	for (int i = 0; i < my_array.getLength(); i++)
	{
		my_array[i] = i * 0.5;
	}

	// MyArray 인스턴스의 각 요소들 출력
	my_array.print();

    return 0;
}