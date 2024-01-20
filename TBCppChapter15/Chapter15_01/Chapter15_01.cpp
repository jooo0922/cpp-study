#include <iostream>
#include "Resource.h"

using namespace std;

// RAII : resource acquisition is initialization

void doSomething()
{
    /*
        new 키워드로 메모리를 동적 할당을 했으면,
        delete 키워드로 반드시 메모리를 반납해야 한다.

        -> 이러한 개념을 'RAII' 라고 함!
    */
    Resource* res = new Resource;

    // work with res

    delete res;

    return;
}

int main()
{
    doSomething();

    return 0;
}