#include <iostream>

using namespace std;

// 클래스 A 에게 클래스 B 의 존재를 알리기 위한 클래스 전방선언! (forward declaration)
class B;

class A
{
private:
    int m_value = 1;

    // 이렇게 friend 키워드를 붙인 뒤,
    // private 멤버에 접근하는 함수의 프로토타입을 갖다 붙이기만 하면 됨!
    // 이제부터 doSomething 함수는 클래스 A 의 '친구 함수' 가 된 것임! 
    // 친구가 되었기 때문에, 캡슐화된 private 한 멤버에도 특별히 접근을 허용해 준다는 것이지!
    //friend void doSomething(A& a);

    // doSomething() 함수를 클래스 A, B 모두에 대해 친구 함수로 등록하는 것은 간단함.
    // 그러나, 클래스 A 가 클래스 B 보다 위에 정의되어 있으므로, 클래스 A 는 클래스 B 의 존재를 모름.
    // 그런 상황에서, 친구 함수로 등록해 놓은 doSomething() 의 매개변수를 선언할 때 클래스 B 를 사용한다면?
    // 클래스 A 는 클래스 B 를 모르므로 컴파일 에러를 발생시킴!
    // -> 이럴 때 사용하는 것이 바로 전방선언! 즉, 클래스 B 의 전방선언을 클래스 A 위에 추가함으로써, 
    // 클래스 A 에게 클래스 B 의 존재를 일단 알려두는 것!
    friend void doSomething(A& a, B& b);
};

class B
{
private:
    int m_value = 2;

    friend void doSomething(A& a, B& b);
};

// 이렇게 특정 함수에서 클래스 인스턴스를 참조변수로 입력받은 뒤,
// private 으로 캡슐화된 멤버에 접근해야 할 경우가 생긴다면?
// 특히, 연산자 오버로딩 구현할 때, 이런 형태의 코드를 많이 작성하게 됨.
// 이럴 때, private 을 public 으로 풀어버릴까? 그건 객체지향 원칙에 위배됨!
// 이럴 때 사용하는 것이, doSomething 함수를 클래스 A 의 'friend(친구 함수)' 로 만들어버리는 것임! 
void doSomething(A& a, B& b)
{
    cout << a.m_value << endl;
    cout << b.m_value << endl; // 만약, doSomething 함수를 두 클래스 A, B 모두의 친구 함수로 등록해야 하는 상황이라면? 
}

int main()
{
    A a;
    doSomething(a);

    return 0;
} 