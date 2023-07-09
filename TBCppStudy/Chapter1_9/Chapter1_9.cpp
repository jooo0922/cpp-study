#include <iostream>

using namespace std;

// 피연산자 간 공백을 한칸씩 띄워주기
// 함수 블록 중괄호 작성 시, 중괄호를 열고 닫을 때마다 개행을 해주기
int add(int x, int y) 
{ 
    return x + y; // indenting 도 반드시 탭 1칸(스페이스 4칸) 만큼을 띄워줘야
}

int main()
{
    // 줄이 길어져서 개행을 해야 할 경우,
    // 아래와 같이 << 연산자를 남겨놓고 개행을 하면,
    // 다른 개발자가 볼때, "아, 여기 다음 줄에 뭔가를 또 출력하는 게 이어서 나오겠구나" 라고 무의식적으로 확인할 수 있음!
    cout << "Hello, World!" << "abcdef" << 
        "Hello Home" << endl;

    // 하드코딩 : 프로그래머가 변수의 값을 코드에서 직접 대입하는 방식
    // 소프트코딩 : 런타임에 사용자 입력, 외부 파일, 네트워트 통신 등으로 데이터를 가져오는 방식
    // 당연히 소프트코딩 방식이 더 좋겠지?
    // 또, 변수에 값을 할당하는 코드를 탭 키로 아래와 같이 줄맞춤 해줄 수 있음. 
    int my_v            = 1;
    int x               = 4;
    int num_apples      = 123;

    // this is important > 주석이 길어질 경우 코드 오른쪽보다는 코드 위쪽에 달 것!
    int x = 1 + 2; 

    // this is important, too
    int y = 3 + 4; 

    return 0;
}