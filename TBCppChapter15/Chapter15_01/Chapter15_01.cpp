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
    //doSomething();

    /* Auto pointer 의 한계 */
    {
        AutoPtr<Resource> res1(new Resource); // 메모리가 동적 할당된 auto pointer
        AutoPtr<Resource> res2; // 메모리를 할당하지 않은 auto pointer

        cout << std::boolalpha;

        // 각 auto pointer 의 포인터 주소값 출력
        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;

        // auto pointer 를 '대입'
        // res1 이 갖고 있는 멤버변수(즉, m_ptr)들을 '복사'해줄 것임!
        res2 = res1;

        /*
            이 때,
            현재 block 의 코드를 실행시키면
            runtime error 가 발생함.

            왜일까?

            현재 block 을 벗어날 경우, 스택 메모리에 할당되어 있는
            AutoPtr 타입의 변수들은 res1 과 res2 가 모두
            '자동 메모리 반납'을 시도할 것임.

            즉, res1 과 res2 의
            소멸자 함수(destructor)가 모두 실행되는데,

            이미 res1 에서 소멸자 함수가 실행되어서
            m_ptr 이 가리키는 동적 메모리 (즉, new Resource)가
            메모리 해제되어버린 상태에서,

            res2 에서도 소멸자 함수가 실행되다보니
            res2.m_ptr 로 'auto pointer 대입' 에 의해
            동일한 동적 메모리인 new Resource 를 가리키게 되어 있음.

            그러나, res1 에서의 소멸자 함수 실행에 의해
            이미 메모리가 반납되어 버린 Resource 를
            중복으로 메모리 반납하려고 하니 에러가 발생한 것!

            -> 즉, new Resource 라는 동적 할당된 힙 메모리의 소유권을
            res1 도 갖게 되고, res2 도 갖게 되다보니 생기는 문제!

            -> 가장 좋은 해결법은,
            오직 한 명만 해당 메모리의 소유권을 갖도록 유지하는 것임!

            그렇게 하려면,
            res2 = res1 처럼 포인터 멤버변수를 '복사'할 경우,
            복사 target 인 res2 에만 포인터 주소값을 갖게 되고,
            복사 source 인 res1 에서는 해당 포인터 주소값의 소유권을 박탈해버리는 것이 가장 좋겠지!

            -> 이러한 개념을 '메모리 소유권의 이동' 이라고 함!

            -> 이를 구현한 것이 AutoPtr 클래스의 복사 생성자와 대입 연산자(=) 오버로딩 함수임!

            -> 이처럼 메모리 소유권을 이전하는 것을 'move semantics' 라고도 부름.
        */

        // auto pointer '대입' 후, 포인터 주소값 재출력
        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
    }

    return 0;
}