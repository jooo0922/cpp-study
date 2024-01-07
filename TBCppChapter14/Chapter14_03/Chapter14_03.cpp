#include <iostream>

using namespace std;

class MyArray
{
private:
	int m_data[5]; // 5개의 int 타입의 정적 배열을 멤버로 관리하는 클래스

public:
	// [] 연산자 오버로딩
	int& operator [] (const int& index)
	{
		// 멤버함수 내에서도 error throw 를 할 수 있다는 걸 보여줌.
		if (index < 0 || index >= 5)
		{
			// 멤버변수에서 관리하는 정적 배열의 크기를 넘어서는 범위의 index 값이 들어오면,
			// int 타입 에러를 던지도록 함 
			throw - 1;
		}

		return m_data[index];
	}
};

void doSomething()
{
    MyArray my_array;

	try
	{
		// MyArray 클래스에서 관리하는 정적 배열의 크기 5 를 넘어서는 index(100)을 전달 
		// -> [] 연산자 오버로딩 멤버함수에서 에러를 throw 하겠군
		my_array[100];
	}
	catch (const int& x)
	{
		// MyArray 클래스의 멤버함수에서 throw 된 int 타입 에러를 여기서 catch 하여 처리할 것임. 
		cerr << "Exception " << x << endl;
	}
}

int main()
{
	doSomething();

    return 0;
}