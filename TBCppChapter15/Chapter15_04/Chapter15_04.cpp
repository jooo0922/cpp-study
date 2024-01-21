#include "AutoPtr.h"
#include "Resource.h"

using namespace std;

int main()
{
    {
        // AutoPtr<Resource> 타입의 인스턴스 생성
        AutoPtr<Resource> res1(new Resource(10000000));

        // 동적 할당된 메모리 주소값 출력
        cout << res1.m_ptr << endl;

        // 대입 연산
        AutoPtr<Resource> res2 = res1;

        // 각 인스턴스의 메모리 주소값 출력
        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
    }
}
