#include <iostream>
#include <memory> // std::unique_ptr<> 사용을 위해 포함
#include "Resource.h"

// unique_ptr 을 만들어서 반환하는 함수
auto doSomething()
{
	return std::unique_ptr<Resource>(new Resource(5));
}

// unique_ptr 스마트 포인터 변수를 L value 참조변수로 받아서
// 해당 스마트 포인터가 관리하는 Resource 클래스의 setAll() 멤버함수 실행
//void doSomething2(std::unique_ptr<Resource>& res)
/*
	만약, unique_ptr 을 참조변수가 아닌 
	매개변수로 선언하려고 한다면?
	
	외부에서 전달한 unique_ptr 의 주소값이 
	매개변수 res 로 '복사'하려고 하겠지!
	
	그러나, unique_ptr 은 '복사'가 불가능하고,
	오로지 '메모리 소유권 이동'만 가능하다고 했었지?

	따라서, 외부에서 L value 로 unique_ptr 의 매개변수를 
	전달하려고 할 경우, 컴파일 에러가 발생할 것임.

	이를 해결하려면 std::move() 로
	unique_ptr 을 R value 로 변환한 다음
	매개변수로 넘겨줘야 함!
*/
void doSomething2(std::unique_ptr<Resource> res)
{
	res->setAll(100);
	res->print();
}

int main()
{
	{
		/* std::unique_ptr<> 사용 예제 */

		///*
		//	new 키워드로 동적 할당된 메모리는
		//	block 을 벗어나기 전에 delete 로 메모리를 직접 반납하지 않으면,
		//	소멸자 함수가 호출되지 않기 때문에,

		//	block 을 벗어나는 순간
		//	res 포인터 변수의 주소값에 할당된 메모리에
		//	memory leak 이 발생하는 상황.

		//	그러나, std::unique_ptr<> 을 사용하면,
		//	이러한 동적 메모리 반납을 delete 키워드를 직접 사용하지 않고서도
		//	자동으로 처리를 해줌! -> 스마트 포인터의 한 종류!
		//*/
		////Resource* res = new Resource(10000000);

		///*
		//	아래와 같이 std::unique_ptr<> 을 사용해서
		//	Resource 타입의 동적 메모리를 할당받게 되면,

		//	delete 키워드로 메모리를 반납하는 매커니즘이
		//	생략되어 있더라도, 자동으로 메모리를 관리해 줌!

		//	-> 그래서 delete 키워드를 생략하더라도,
		//	현재 block 을 벗어날 시,
		//	Resource 클래스의 소멸자 함수가 호출됨!
		//*/
		//std::unique_ptr<Resource> res(new Resource(10000000));

		//// early return or throw

		// //delete res;
	}

	{
		/* unique_ptr 의 메모리 소유권 이동 */


		//std::unique_ptr<int> upi(new int);


		///* unique_ptr 초기화하는 3가지 방법 */

		//// 일반적인 unique_ptr 사용 방법
		////std::unique_ptr<Resource> res1(new Resource(5));

		//// std::make_unique<> 는 좀 더 권장되는 문법
		//// 마치 std::make_unique<Resource> 자체가 하나의 클래스 생성자 함수가 되어 5만 매개변수로 전달하는 식으로 사용 가능.
		//auto res1 = std::make_unique<Resource>(5);

		//// 함수로부터 받아서 초기화하는 방법
		////auto res1 = doSomething();

		//// std::unique_ptr<> 또한 우리가 직접 만들었던 AutoPtr 클래스와 마찬가지로,
		//// 내부에서 포인터 멤버 참조 연산자(->)를 오버로딩해서 
		//// Template 클래스(즉, 여기서는 Resource)의 주소값에 접근할 수 있도록 함.
		//res1->setAll(5);
		//res1->print();

		//// unique_ptr 을 하나 더 만듦.
		//std::unique_ptr<Resource> res2;


		//// 두 개의 unique_ptr 포인터 변수인 res1, res2 가 nullptr 인 지 여부를
		//// bool 타입으로 캐스팅해서 출력해 봄

		//// std::boolalpha 는 bool 값을 0 또는 1이 아닌, "true" 또는 "false" 형태의 문자열로 출력시키도록 함.
		//std::cout << std::boolalpha;

		//// res1 은 std::make_unique<> 로 확실하게 Resource 클래스를 초기화했으니, 포인터의 주소값이 존재함 -> true 출력
		//std::cout << static_cast<bool>(res1) << std::endl;

		//// res2 는 변수의 타입만 std::unique_ptr 로 선언했을 뿐, 실제 메모리를 할당받은 포인터가 아니므로, nullptr 이 담겨있음. -> false 출력
		//std::cout << static_cast<bool>(res2) << std::endl;

		///*
		//	unique_ptr<> 은 '복사가 불가능'하다!
		//
		//	why? unique_ptr 은 말 그대로 
		//	'메모리의 소유권'이 '고유한 포인터 변수 하나에만'
		//	unique 하게 존재해야 하는 스마트 포인터 변수임.

		//	따라서, 아래와 같이 '대입 연산자'를 통한
		//	'메모리 주소값 복사' 가 불가능함.

		//	-> 즉, copy semantics 는 사용이 불가하고,
		//	오로지 move semantics 만 사용 가능함!
		//*/
		////res2 = res1;

		///*
		//	대신 unique_ptr 은 아래 코드와 같이
		//	std::move() 로 R value 참조변수로 변환한 뒤,

		//	'메모리 소유권 이동'만 가능함.

		//	'해당 주소값을 갖고 있는 포인터 변수는
		//	오직 고유한(unique) 하나의 변수여야 함' 이
		//	unique_ptr 의 중요한 특징!
		//*/
		//res2 = std::move(res1);

		//// unique_ptr 의 메모리 소유권 이동 후, 다시 주소값 여부를 출력함
		//std::cout << std::boolalpha;

		//// res1 은 메모리 소유권(주소값)이 이동하여 메모리 소유권이 박탈되었으니, nullptr 만 남음. -> false 출력
		//std::cout << static_cast<bool>(res1) << std::endl;

		//// res2 는 res1 으로부터 메모리 소유권(주소값)이 이동하였으므로, 해당 주소값이 담겨있음. -> true 출력
		//std::cout << static_cast<bool>(res2) << std::endl;

		//// 각 unique_ptr 이 nullptr 이 아닐 경우에만 Resource 클래스 내부의 print() 멤버함수를 실행시킴.
		//if (res1 != nullptr) res1->print();
		//if (res2 != nullptr) res2->print();
	}

	{
		/* unique_ptr 를 다른 함수의 매개변수로 넘길 때의 용법 */

		
		// make_unique<>() 를 통해 Resource 클래스에 대한 unique_ptr 생성
		auto res1 = std::make_unique<Resource>(5);

		// res1 이 관리하는 Resource 클래스의 동적 배열의 메모리를 모두 1로 채우고 출력
		res1->setAll(1);
		res1->print();

		// unique_ptr 포인터 변수를 L value 참조변수로 전달하여 Resource 클래스의 setAll() 을 실행시킴
		//doSomething2(res1);

		/*
			std::unique_ptr<T>.get() 함수는

			unique_ptr 이 내부적으로 메모리를 자동 관리하고 있는
			T 타입의 일반적인 포인터 변수(== 주소값) 그 자체인 T* 를 반환해주는 함수!
		*/
		Resource* res2 = res1.get();

		// doSomething2() 함수의 매개변수가 std::unique_ptr<> res 로 선언되어 있다면,
		// 필시 '주소값 복사'가 발생하게 될 것인데, unique_ptr 은 복사가 불가능하고, '주소값 이동'만 가능하므로,
		// std::move() 를 통해 res1 을 R value 로 변환한 다음 전달해줘야 함!
		doSomething2(std::move(res1));

		// 위에서 std::move() 에 의해 메모리 소유권이 이동한 res1 에는 주소값이 nullptr 로 남게 될 것이므로,
		// bool casting 하여 출력하면 "false" 가 출력될 것임
		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		// doSomething2() 에서 초기화한 동적 배열의 값들인 
		// 10 10 10 10 10 이 출력되겠지
		//res1->print();
	}
}