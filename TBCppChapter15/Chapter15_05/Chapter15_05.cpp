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
		*/
		Resource* res = new Resource(10000000);

		// early return or throw

		 //delete res;
	}
}