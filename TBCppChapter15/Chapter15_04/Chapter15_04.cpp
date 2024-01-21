#include <vector>
#include <string>
#include "AutoPtr.h"
#include "Resource.h"

using namespace std;

// 두 L-value 참조변수를 서로 바꿔주는 util 함수를 함수 템플릿으로 구현
// std::swap() 함수를 예제를 위해 직접 구현한 것
template<class T>
void MySwap(T& a, T& b)
{
    //// 복사 대입(deep copy)으로 L-value 참조변수 a 의 데이터를 임시 변수의 메모리에 복사
    //// (Resource 타입 인스턴스로 들어올 경우, Resource 에 정의된 대입 연산자 복사 오버로딩(copy assignment)이 실행될 테니까!)
    //T tmp = a;

    //// copy assignment 실행
    //a = b;

    //// copy assignment 실행
    //b = tmp;

    
    // 이번에는 'move semantics' 를 이용해서 swap 해보자!
    /*
        std::move() 를 통해
        L-value 참조변수인 a, b, tmp 를 
        R-value 참조변수로 변환해서 사용하기 때문에,

        아래 코드에서는 AutoPtr 에 구현된
        '이동 생성자'와 '이동 대입 오버로딩' 만 실행될 것임!
    */
    T tmp{ std::move(a) };
    a = std::move(b);
    b = std::move(tmp);
}

int main()
{
    /* std::move() 로 move semantics 사용 예제 */

    //{
    //    // AutoPtr<Resource> 타입의 인스턴스 생성
    //    AutoPtr<Resource> res1(new Resource(10000000));

    //    // 동적 할당된 메모리 주소값 출력
    //    cout << res1.m_ptr << endl;

    //    // 대입 연산 -> 이때, 복사 생성자가 실행되므로, 
    //    // deep copy, 즉, copy semantics 가 실행되고 있다고 볼 수 있겠지!
    //    //AutoPtr<Resource> res2 = res1;
    //    /*
    //        만약, 여기서 'move semantics' 로 작동하도록 하고 싶다면,
    //        std::move() 를 사용하면 됨.

    //        이거는 무슨 복잡한 기능을 담고 있는 함수가 아니고,

    //        현재 L-value 로 선언되어 있는 res1 을
    //        R-value 참조변수(&&)로 변환해서 return 해주는 역할을 함.

    //        즉, res2 에 R-value 가 '대입 연산' 됨으로써,
    //        AutoPtr 클래스에 '이동 대입'으로 오버로딩된 함수가 실행되어
    //        결과적으로 move semantics 로 작동하게 됨!
    //    */
    //    AutoPtr<Resource> res2 = std::move(res1);

    //    // 각 인스턴스의 메모리 주소값 출력
    //    /*
    //        copy semantics 상에서 작동한다면,
    //        deep copy 로 인해 아예 다른 메모리 공간을 할당받아서 값을 모두 복사할테니,
    //        두 인스턴스의 메모리 주소값은 다를 것이고,

    //        move semantics 상에서 작동한다면,
    //        주소값을 '이동'시킴으로써, 메모리 소유권을 이동하므로,
    //        res1 인스턴스의 주소값은 nullptr(x86 빌드 기준 00000000 이 출력) 이 출력될 것이고
    //        res2 인스턴스의 주소값은 이동된 주소값이 출력되겠지!
    //    */
    //    cout << res1.m_ptr << endl;
    //    cout << res2.m_ptr << endl;
    //}


    /* std::move() 로 두 L-value 를 R-value 로 변환 후, 교체(swap)하는 예제  */
    
    //{
    //    AutoPtr<Resource> res1(new Resource(3));

    //    // 포인터 멤버변수 참조 연산자(->) 오버로딩을 통해 Resource 클래스 내에 정의된 setAll() util 에 접근 가능!
    //    res1->setAll(3); 

    //    AutoPtr<Resource> res2(new Resource(5));
    //    res2->setAll(5);

    //    // 두 인스턴스 res1, res2 를 swap 전 출력
    //    res1->print();
    //    res2->print();

    //    // copy assignment 를 통해 두 L-value 참조변수를 교체(swap)
    //    MySwap(res1, res2);

    //    // 두 인스턴스 res1, res2 를 swap 후 출력
    //    res1->print();
    //    res2->print();
    //}


    /* 기존 std 자료구조에 이미 구현된 move semantics 작동 예제 */

    {
        std::vector<string> v;
        std::string str = "Hello";

        /*
            아래 std::vector.push_back() 부분에 마우스를 갖다대보면,
            std::vector.push_back(const std::string& _Val) 가 뜨게 됨.

            즉, std::vector 는 기본적으로 L-value 참조변수로 
            동적 배열 vector 에 push 할 매개변수를 받도록 되어 있음.

            즉, 기본적으로는
            'copy semantics(deep copy)'로
            데이터를 추가하게 되어있다는 의미.
        */
        v.push_back(str);

        // deep copy 의 원본인 std::string 타입의 참조변수가 가리키는 문자열 출력
        cout << str << endl;

        // copy semantics 로 vector 에 추가된 문자열 출력
        cout << v[0] << endl;

        /*
            이번에는 L-value 참조변수인 str 을
            std::move() 를 통해 R-value 로 변환하여 매개변수에 전달한 뒤,
            
            std::vector.push_back() 부분에 마우스를 갖다대보면,
            std::vector.push_back(std::string&& _Val) 가 뜨게 됨.

            즉, std::vector.push_back() 는 R-value 참조변수를 받아서
            처리할 수도 있도록 별도로 오버로딩 구현이 되어있다는 소리!

            즉, 이번에는
            'move semantics(shallow copy)'로
            데이터를 추가하게 될 것임!
        */
        v.push_back(std::move(str));

        // std::vector.push_back() 에서 'move semantics' 로 추가되어버린 참조변수 str 은
        // 말 그대로 메모리 소유권(주소값)이 std::vector 로 이동해버렸기 때문에, 
        // str 에는 문자열을 가리킬 주소값이 nullptr 로 초기화되어 버림.
        // 따라서, str 은 더 이상 가리키는 메모리가 존재하지 않아 문자열을 출력하지 못함!
        /*
            이처럼, R-value 에 대한 push_back(), 즉, move semantics 가 
            std::vector 내부에 구현되어 있기 때문에 이러한 결과가 나오게 된 것임.

            그냥 자연스럽게 나온 결과물이 아님!

            즉, std::vector 에 우리가 AutoPtr 클래스에 해줬던 것처럼
            move semantics 가 모두 구현되어 있기 때문에

            우리는 std::move() 를 사용하여
            L-value 를 R-value 로 전환하여 std::vector 에 넘겨주기만 하면
            알아서 move semantic 이 작동하도록 편하게 쓸 수 있는 것이라고 알면 됨!
        */
        cout << str << endl;

        // copy semantics 로 vector 에 추가된 문자열(deep copy)과
        // move semantics 로 vector 에 추가된 문자열(shallow copy)을 함께 출력
        cout << v[0] << " " << v[1] << endl;
    }
}
