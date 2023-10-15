#include <cassert> // 컴파일러를 활용한 디버깅에 assert() 사용을 위해 포함

int main()
{
    // 프로그램 빌드 후 실행, 또는 디버기 실행 시, 이 부분에서 assertion failed 에러가 발생했다고 표시해 줌.
    // 참고로 assert() 는 Debug 로 빌드한 실행파일에서만 사용 가능하고, Release 빌드는 실행 x
    assert(false);

    return 0;
}