#include <iostream>
#include <memory> // std::unique_ptr<> 사용을 위해 포함
#include "Resource.h"

int main()
{
	{
		/*
			new 키워드로 동적 할당된 메모리는
			block 을 벗어나기 전에 delete 로 메모리를 직접 반납하지 않으면,
			소멸자 함수가 호출되지 않기 때문에,

			block 을 벗어나는 순간
			res 포인터 변수의 주소값에 할당된 메모리에
			memory leak 이 발생하는 상황.

			그러나, std::unique_ptr<> 을 사용하면,
			이러한 동적 메모리 반납을 delete 키워드를 직접 사용하지 않고서도
			자동으로 처리를 해줌! -> 스마트 포인터의 한 종류!
		*/
		//Resource* res = new Resource(10000000);

		/*
			아래와 같이 std::unique_ptr<> 을 사용해서
			Resource 타입의 동적 메모리를 할당받게 되면,

			delete 키워드로 메모리를 반납하는 매커니즘이
			생략되어 있더라도, 자동으로 메모리를 관리해 줌!

			-> 그래서 delete 키워드를 생략하더라도,
			현재 block 을 벗어날 시,
			Resource 클래스의 소멸자 함수가 호출됨!
		*/
		std::unique_ptr<Resource> res(new Resource(10000000));

		// early return or throw

		 //delete res;
	}
}