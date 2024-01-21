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

        // 대입 연산 -> 이때, 복사 생성자가 실행되므로, 
        // deep copy, 즉, copy semantics 가 실행되고 있다고 볼 수 있겠지!
        //AutoPtr<Resource> res2 = res1;
        /*
            만약, 여기서 'move semantics' 로 작동하도록 하고 싶다면,
            std::move() 를 사용하면 됨.

            이거는 무슨 복잡한 기능을 담고 있는 함수가 아니고,

            현재 L-value 로 선언되어 있는 res1 을
            R-value 참조변수(&&)로 변환해서 return 해주는 역할을 함.

            즉, res2 에 R-value 가 '대입 연산' 됨으로써,
            AutoPtr 클래스에 '이동 대입'으로 오버로딩된 함수가 실행되어
            결과적으로 move semantics 로 작동하게 됨!
        */
        AutoPtr<Resource> res2 = std::move(res1);

        // 각 인스턴스의 메모리 주소값 출력
        /*
            copy semantics 상에서 작동한다면,
            deep copy 로 인해 아예 다른 메모리 공간을 할당받아서 값을 모두 복사할테니,
            두 인스턴스의 메모리 주소값은 다를 것이고,

            move semantics 상에서 작동한다면,
            주소값을 '이동'시킴으로써, 메모리 소유권을 이동하므로,
            res1 인스턴스의 주소값은 nullptr(x86 빌드 기준 00000000 이 출력) 이 출력될 것이고
            res2 인스턴스의 주소값은 이동된 주소값이 출력되겠지!
        */
        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
    }
}
