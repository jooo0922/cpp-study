#include <iostream>
#include "Resource.h"
#include "AutoPtr.h" // 동적 할당된 메모리를 자동으로 관리해주는 클래스를 추상화해서 include

using namespace std;

// RAII : resource acquisition is initialization

void doSomething()
{
    /*
        new 키워드로 메모리를 동적 할당을 했으면,
        delete 키워드로 반드시 메모리를 반납해야 한다.

        -> 이러한 개념을 'RAII' 라고 함!

        -> 이를 클래스 형태로 추상화하여
        메모리를 똑똑하게 자동으로 관리할 수 있도록 한 
        패러다임이 '스마트 포인터(smart pointer)' 라고 보면 됨!
    */

    try
    {
        // 아래와 같이 자기가 동적 할당 했으면서 끝까지 메모리를 반납하는 책임을 지지 않는
        // 멍청한 포인터 변수들을 dull pointer 라고도 부름
        //Resource* res = new Resource;

        // 반면, 아래와 같이 메모리 동적 할당 및 반납을 클래스로 추상화하여
        // 메모리를 자동으로 관리해주는 똑똑한 포인터 변수를 'smart pointer(스마트 포인터)' 라고 함!
        AutoPtr<Resource> res(new Resource);

        // work with res
        
        // exception
        /*
            아래와 같이,
            try 문에서 에러를 throw 함으로써,
            메모리 반납하는 코드를 실행하지 못하게 된다면?

            -> 이런 상황이 발생할 때마다
            매번 메모리 반납를 프로그래머가 직접 신경 쓰기에는
            작성해야 할 코드도 많고 너무 번거롭겠지.

            그래서 이러한 번거로운 메모리 반납을
            자동으로 관리해 줄 수 있는 클래스를 하나 만드는 것!

            이를 추상화한 클래스가 'AutoPtr' 
            (std::auto_ptr<> 과 동일하게 만든 것. 현재는 deprecated 됨.)
        */
        if (true)
        {
            throw - 1;
        }

        // 스마트 포인터를 사용한다면, 더 이상 메모리 반납을 프로그래머가 직접 하지 않아도 됨!
        //delete res;
    }
    catch (...)
    {

    }

    return;
}

int main()
{
    doSomething();

    return 0;
}