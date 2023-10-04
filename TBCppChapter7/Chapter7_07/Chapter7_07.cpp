#include <iostream>
#include <string>

using namespace std;

/*
    함수 오버로딩

    들어오는 매개변수의 타입이 다르지만,
    내부에서 수행하는 기능이 비슷비슷할 경우,

    동일한 이름의 함수를 가지고서
    '함수 오버로딩' 을 수행할 수 있다!

    즉, 함수의 이름이 같더라도,
    매개변수 타입이 다르다면, 
    내부적으로 서로 다른 함수로 취급함!
*/
int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}

/*
    반환 타입이 다르고 매개변수 타입이 동일하더라도
    함수 오버로딩이 될까? X

    무조건 매개변수가 달라야 오버로딩이 됨!
    반환타입만 같으면 오버로딩이 안됨!

    반환타입만 다르게 해줄 경우, 
    동일한 이름의 두 함수는 에러가 발생함!
*/
//int getRandomValue() {}
//double getRandomValue() {}

// 두 함수 중 하나의 매개변수를 사용자 정의 타입으로 오버로딩을 시도해봤자,
// 어차피 내부적으로 동일한 int 타입이기 때문에 빌드 에러가 발생함! > 컴파일러를 눈속임할 수 없다!
typedef int my_int; // 사용자 정의 타입 별칭 선언
//void print (int x) {}
//void print (my_int x) {}


// 오버로딩된 두 함수 중 하나의 매개변수가 포인터 변수로 설정되었을 때
void print (char* value) {}
void print (int value) {}

void print2(unsigned int value) {}
void print2(float value) {}

int main()
{
    // 컴파일러가 매개변수에 전달된 리터럴 값의 타입에 따라
    // 알아서 오버로딩된 함수들을 찾아서 컴파일 해줌.
    // 즉, 어떤 add 함수를 사용할 지는, '컴파일 단계에서' 결정됨!
    add(1, 2);
    add(3.0, 4.0);

    print(0);

    // 문자 포인터 변수를 받는 함수는 있어도, 문자 리터럴을 받도록 오버로딩된 함수는 찾을 수 없음. 
    // -> 문자 리터럴을 받는 오버로딩된 함수를 찾지 못한 컴파일러는 결국 나머지 int 타입을 받는 함수로 컴파일함.
    // -> 인자로 들어온 타입 중에서 잘 맞는 게 없어서 나머지 오버로딩된 함수들 중에서 억지로 맞춘 케이스
    print("a");

    // 이번에는 인자로 들어온 타입들이 오버로딩된 함수들에 모두 어느 정도 맞아서
    // 그 중에서 어떤 함수로 컴파일해야 할 지 모호한(ambiquous) 해서 빌드 에러를 발생시키는 케이스!
    print2('a');
    print2(0);
    print2(3.14159);

    return 0;
}