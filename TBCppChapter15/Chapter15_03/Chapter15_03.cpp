#include "Timer.h"
#include "AutoPtr.h"
#include "Resource.h"

// Resource 클래스의 인스턴스 생성 시, AutoPtr 로 메모리 관리하도록 등록하는 함수
AutoPtr<Resource> generateResource()
{
    // 1000,0000 개의 int 타입이 저장될 수 있는 동적 배열 메모리를 할당하여 Resource 클래스 인스턴스를 생성하고,
    // 그것을 AutoPtr 클래스 인스턴스 생성 시, 매개변수로 전달하여 메모리를 자동관리할 수 있도록 함.
    AutoPtr<Resource> res(new Resource(10000000));

    // AutoPtr<Resource> 타입 인스턴스를 return 할 경우,
    // return 받아서 특정 외부 변수에 대입(=) 시, AutoPtr 클래스에 정의된 대입 연산자 오버로딩이 실행되겠지?
    // -> 이는 결국, Resource 클래스에 정의된 대입 연산자 오버로딩 실행으로 이어져 deep copy 가 발생하게 될 것임!
    // -> 결과적으로, return 시점에 deep copy 로 인해 실행 시간이 오래 걸리겠지!
    return res;
}

int main()
{
    using namespace std;

    // 이전까지의 cout 실행을 통해 출력할 내용들이 담긴 스트림 읽기 버퍼를
    // 다른 스트림 버퍼에 임시로 캐싱해 둠.
    streambuf* orig_buf = cout.rdbuf();

    /*
        cout 으로 출력할 때의 실행 시간이 더 오래 걸리는 경우가 있음.

        따라서 기존 AutoPtr 과 Resource 클래스에서의 출력을 일시 중단하기 위해,
        cout 출력을 담아둘 스트림 읽기 버퍼와의 연결을 끊어냄.

        이렇게 하면, 이후에 cout 출력을 실행하더라도,
        출력할 내용을 담을 버퍼를 참조할 수 없는 상태이기 때문에,
        출력할 내용을 스트림 버퍼에 저장해둘 수 없게 됨.

        그 결과, 콘솔 출력으로 인해
        실행시간이 늘어나는 것을 방지할 수 있게 됨으로써,
        순수한 deep copy 에 걸리는 실행시간을 측정할 수 있게 됨!
    */
    cout.rdbuf(NULL);

    // Timer 인스턴스가 생성되는 시점부터 경과시간을 측정함.
    Timer timer;

    {
        // 안쪽 block 에서 AutoPtr<Resource> 타입의 인스턴스를 생성 및 '대입' 함으로써,
        // deep copy 가 실행되고 실행 시간이 오래 걸리게 될 것임!
        AutoPtr<Resource> main_res;

        // 이때, R-value 인 표현식 generateResource() 는 대입 연산 이후 곧장 사라지므로, 
        // R-value 에서의 AutoPtr destructor 와 Resource destructor 가 실행되는 것이고,
        // 현재 local block 을 벗어나는 시점에 main_res 에 저장되어 있던 AutoPtr destructor 와 Resource destructor 가
        // 다시 한 번 실행되어 총 2번 씩 소멸자가 실행되는 것임!
        main_res = generateResource(); 
    }

    // 스트림 읽기 버퍼를 끊어내기 이전까지의 출력할 내용을 담아뒀던 스트림 버퍼를 복원하여,
    // 이전까지의 출력은 정상적으로 출력시킬 수 있도록 함.
    cout.rdbuf(orig_buf);

    // deep copy 에 걸린 경괴시간 측정
    cout << timer.elapsed() << endl;

    return 0;
}

/*
    주!

    cout 에 의한 콘솔 출력은
    Release 모드로 빌드하느냐
    Debug 모드로 빌드하느냐에 따라

    출력 결과가 달라지는 문제가 있음.

    일반적으로, Debug 모드로 실행파일을 빌드할 때,
    콘솔 출력을 더 많이 자세히 보여주는 편.

    따라서, 강의내용과 동일한 결과를 얻기 위해
    빌드 모드를 Release 로 설정할 것을 권장함!
*/