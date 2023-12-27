#include "MyArray.h"

int main()
{
    MyArray my_array(10);

	// MyArray 클래스의 배열 요소들 할당
	for (int i = 0; i < my_array.getLength(); i++)
	{
		my_array[i] = i * 10;
	}

	// MyArray 인스턴스의 각 요소들 출력
	my_array.print();

    return 0;
}