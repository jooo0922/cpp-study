#include <iostream>
#include "Storage.h"

using namespace std;

template<typename T>

// 이제 아래 함수 getMax() 의 반환값과 매개변수 타입은 어떤 것이든 올 수 있음!
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

/*
    템플릿 특수화 (Specialization)


    만약, 위에서 일반화한 템플릿 함수 getMax() 에서
    템플릿 파라미터 T 에 char 타입이 들어온다면,

    '문자 리터럴을 비교하니 주의하세요!' 라는 문구를
    출력하는 특수한 작업을 예외적으로 처리할 수는 없을까?

    템플릿은 컴파일 타임에 타입이 결정되어야 하므로,
    런타임에 사용 가능한 if 같은 조건문은 적합하지 않은 것 같고,
    이럴 경우 사용하는 게 '템플릿 특수화'

    템플릿 특수화란,
    컴파일러가 각 타입들을 자동으로 구현하려고 할 때,
    예외적으로 특정 타입에 대해서는
    프로그래머가 직접 정의한 함수를 사용하도록 하는 기법!

    그러니까, 템플릿이 '일반화' 라면,
    템플릿 특수화는 거꾸로 특정 템플릿 파라미터에 대해서만
    예외적으로 프로그래머가 함수를 직접 '특수화, 구체화'하여 선언하는 것으로 보면 됨!

    특정 템플릿 파라미터 타입에 대해서만
    예외적으로 다른 작업을 추가로 처리하고 싶을 때가 있으니까!
*/
template<> // 템플릿을 일반화하려는 게 아니므로, typename T 를 빼줘야 함.
char getMax(char x, char y)
{
    // char 타입에 대해서는 경고를 출력하는 작업 추가
    cout << "Warning : comparing chars" << endl;

    return (x > y) ? x : y;
}

int main()
{
    // 함수 템플릿을 사용할 때에는, 아래와 같이 '꺽쇠 안에 템플릿 파라미터 전달' 라는 부분이 '생략'된 것으로 보면 됨! 
    //cout << getMax<int>(1, 2) << endl; // int

    // 따라서, 함수에 전달되는 실제 리터럴 값을 템플릿 파라미터에 전달하는 타입으로 강제 형변환하는 것도 가능함!
    cout << getMax<double>(1, 2) << endl; // double
    cout << getMax('a', 'b') << endl; // 템플릿 특수화가 적용된 함수가 실행됨

    // 템플릿 파라미터를 서로 다른 타입으로 전달하여 Storage 클래스의 인스턴스 생성
    Storage<int> nValue(5);
    Storage<double> dValue(6.7);

    nValue.print();
    dValue.print();

    return 0;
}