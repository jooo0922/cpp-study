#include "MyArray.h"

int main()
{
	/*
		클래스 템플릿에
		template parameter (템플릿 매개변수) 전달
	*/
	MyArray<double, 100> my_array;

	// MyArray 클래스의 배열 요소들 할당
	for (int i = 0; i < my_array.getLength(); i++)
	{
		my_array[i] = i * 0.5;
	}

	// MyArray 인스턴스의 각 요소들 출력
	my_array.print();

	return 0;
}