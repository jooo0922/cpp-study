#include <iostream>

using namespace std;

/*
    매개변수 기본값(default parameter. optional parameter. optional argument)

    매개변수 자리에 별도로 인자가 전달되지 않을 경우,
    이 값을 기본값으로 하여 넣어달라는 의미!

    매개변수가 여러 개 일 때에도 사용 가능
*/
void print(int x = 1024)
{
    cout << x << endl;
}

// 만약에 객체지향 프로그래밍에서 아래와 같이 함수의 선언과 구현부를 분리할 경우,
// 헤더파일에 선언부를 구현해놓고 매개변수 기본값을 설정해뒀다면, 
// 다른 파일에 존재하는 구현부에서는 기본값 설정을 빼줘야 함.
// 매개변수 기본값은 선언부와 구현부 중 한 곳에서만 설정해줘야 함!
// 일반적인 컨벤션에 따르면, 헤더파일에 정의해 둔 선언부에서 매개변수 기본값을 설정해 둠!
// 프로그래머들이 헤더파일을 보면서 함수의 대략적인 구조를 파악하기 때문에,
// 매개변수 기본값이 뭔지 한 눈에 바로 들어와야 빠르게 함수 구조를 파악하기 수월함!
void print2(int x = 10, int y = 20, int z = 30); // in header

// 매개변수 리스트들 중에서 가운데 값부터 기본값을 설정하려고 하면 컴파일 에러 발생
// 항상 매개변수 기본값은 매개변수 리스트의 오른쪽 끝에서부터 설정 가능! 
//void print2(int x, int y = 20, int z)
void print2(int x, int y, int z)
{
    cout << x << " " << y << " " << z << endl;
}

int main()
{
    print(10); // 10
    print(); // 1024

    print2();
    print2(100);
    print2(100, 200);
    print2(100, 200, 300);

    return 0;
}