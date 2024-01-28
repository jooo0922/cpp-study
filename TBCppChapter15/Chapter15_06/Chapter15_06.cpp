#include <iostream>
#include "Resource.h"

int main()
{
    // Resource 클래스를 동적으로 메모리 할당 및 내부 동적배열 초기화
    //Resource* res = new Resource(3);
    //res->setAll(1);

    {
        /*
            std::shared_ptr<> 스마트 포인터를 사용하여
            Resource 클래스의 메모리를 자동 관리

            unique_ptr 이 하나의 메모리 주소값을
            하나의 포인터 변수만 자동으로 관리할 수 있도록 하는 것이라면,

            shared_ptr 은 반대로,
            하나의 메모리 주소값을
            여러 개의 스마트 포인터 변수들이 '공유'할 수 있도록 한 것!

            즉, '메모리 소유권을 공유' 하기 위해
            만든 스마트 포인터라고 보면 됨.
        */
        //std::shared_ptr<Resource> ptr1(res);

        /*
            shared_ptr 로 공유하고자 하는 메모리 주소값 res 를
            직접 매개변수로 넘겨줘서 발생하는 불상사를 막기 위해,

            애초부터 공유하고자 하는 메모리인 res 자체를 
            L value 로 만들어서 캐싱해두는 방식을 사용하지 않고,

            아래 코드와 같이 std::make_shared<>() 를 사용하여
            shared_ptr 을 만드는 것이 훨씬 더 안전하게
            shared_ptr 을 사용할 수 있는 방법임! 

            unique_ptr 에서와 마찬가지로,
            shared_ptr 에서도 std::make_shared<>() 문법이
            훨씬 더 권장되는 문법이라고 볼 수 있겠지!
        */
        auto ptr1 = std::make_shared<Resource>(3);
        ptr1->setAll(1);

        ptr1->print();

        {
            /*
                shared_ptr 의 중요한 특성


                shared_ptr 은 여러 개의 스마트 포인터가
                하나의 메모리 주소값을 공유하기 때문에,

                shared_ptr 내부에 자체적으로
                몇 개의 스마트 포인터가 서로 같은 메모리 주소값을
                공유하고 있는지 counting 하는 데이터가 존재함.

                그래서 아래와 같이 새로운 shared_ptr 을 생성할 때,
                기존 shared_ptr 인 ptr1 을 매개변수로 넘겨주면,

                ptr1 과 ptr2 는 모두
                Resource 클래스에 대해 동적 할당된 메모리의 주소값인
                res 를 가리키게 될 것임.
            */
            std::shared_ptr<Resource> ptr2(ptr1);

            /*
                shared_ptr 을 추가로 더 만들 때,

                아래 코드와 같이 공유할 메모리 주소값인 res 를
                직접 전달하여 만들려고 한다면,

                기존의 shared_ptr 인 ptr1 입장에서는
                자기 자신 외에 다른 shared_ptr 인 ptr2 가
                res 에 대한 소유권을 공유하고 있다는 것을
                알 방법이 없음.

                shared_ptr 을 이런 식으로 사용하는 순간
                믄제가 발생하게 되므로,

                항상 기존 shared_ptr 자체를 매개변수로 넘겨줘야
                기존 shared_ptr 내부에서 어떤 shared_ptr 들이
                동일한 메모리 주소값을 공유하고 있는지 내부적으로 관리할 수 있음!
            */
            //std::shared_ptr<Resource> ptr2(res);

            ptr2->setAll(3);
            ptr2->print();

            /*
                inner block 을 벗어나서
                ptr2 가 사라진다고 하더라도,
                ptr1 은 여전히 살아있기 때문에,

                Resource 클래스의 메모리는
                아직 ptr1 스마트 포인터를 통해 접근할 수 있으므로,

                outer block 에서 ptr1->print() 를 통해
                Resource 클래스의 메모리에 저장된 값을 출력할 수 있음.
            */
            std::cout << "Going out of the inner block" << std::endl;
        }

        ptr1->print();

        /*
            outer block 을 벗어나게 되면
            비로소 ptr1 까지도 사라지게 되므로,

            더이상 Resource 클래스를 가리키는
            shared_ptr 이 존재하지 않게 됨.

            따라서, 더 이상 메모리 주소값을 공유하는
            shared_ptr 스마트 포인터가 존재하지 않을 때

            비로소 Resource 클래스의 메모리도 
            마지막으로 남아있는 shared_ptr 인 ptr1 내부에서 
            자동으로 메모리를 반납시켜 버림!
        */
        std::cout << "Going out of the outer block" << std::endl;
    }

    return 0;
}