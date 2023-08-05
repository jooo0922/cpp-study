#include <iostream>

/*
    같은 영역 내에
    반환값, 파라미터, 이름이 동일한 두 함수 doSomething 은 공존할 수 없다!

    따라서, block 과 namespace 로 영역을 나눠줘야 함!
    즉, 두 영역은 서로 다른 영역임을 명시하기 위해
    사용하는 키워드가 namespace 라고 보면 됨!
*/
//namespace work1
//{
//    // c++ 17 에 추가된 기능 > nested namespace
//    // namespace 안에를 또 namespace 를 사용하여 구분지을 수 있음.
//    namespace work11 {
//        namespace work111 {
//            int a = 1;
//            void doSomething()
//            {
//                a += 3;
//            }
//        }
//    }
//}

// 위와 같은 중첩 namespace 의 가독성 개선을 위해 아래와 같은 문법으로 namespace 를 선언할 수 있음.
// 단, 이 경우 프로젝트 > Properties > C/C++ > Language > C++ Language Standard 를 C++ 17 표준으로 바꿔줘야 컴파일러가 정상 문법으로 인식함!
namespace work1::work11::work111
{
    int a = 1;
    void doSomething()
    {
        a += 3;
    }
}

namespace work2
{
    int a = 1;
    void doSomething()
    {
        a += 5;
    }
}

int main()
{
    using namespace std;

    //apple = 3; // 변수 선언 전에 할당 x

    int apple = 5;

    cout << apple << endl;

    if (true)
    {
        //apple = 1; // 내부 중괄호(nested block)에서는 외부에서 선언한 변수 사용 가능
        //int apple = 1; // 내부에서 동일한 변수명을 새롭게 선언하면, 해당 블록 안에서만 사용 가능 > 이때, 외부에서 선언된 동일한 변수 apple 은 '숨겨짐'!!
        int apple2 = 1; // 그래서, 가급적 내부 스코프 변수는 이름을 다르게 선언해줘야 함.
        cout << apple2 << endl;
    }

    cout << apple << endl;

    // :: 연산자는 '영역(범위)결정 연산자' 라고 함
    // 이름이 같은 두 개 이상의 변수와 함수의 영역을 구분하여 '충돌을 해결한다(결정)'는 의미.
    //work1::a;
    //work1::doSomething();
    work1::work11::work111::doSomething(); // 중첩 namespace 접근방식 > 문법이 편해졌다고는 하나, 가독성이 여전히 안좋아서 depth 를 가급적 깊게 들어가지 않는 걸 권장!

    work2::a;
    work2::doSomething();

    return 0;
}

//apple = 3; // 중괄호 스코프를 벗어남 > apple 에 할당한 메모리는 블록이 끝나면 OS 에 반환하기 때문!