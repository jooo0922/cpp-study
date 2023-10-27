#include <iostream>

using namespace std;

// 클래스 A 에게 클래스 B 의 존재를 알리기 위한 클래스 전방선언! (forward declaration)
//class B;

// 이번에는 클래스 A 와 클래스 B 의 위치를 바꾼 뒤, 클래스 B 에게 클래스 A 의 존재를 알리는 전방선언 추가
class A;

class B
{
private:
    int m_value = 2;

    friend void doSomething(A& a, B& b);

public:
    // 이번에는 클래스 B 의 멤버함수에서 클래스 A 의 private 멤버에 접근하고 싶다면??
    // 이럴 경우, 클래스 B 를 클래스 A 의 '친구 클래스' 로 등록해버리면 됨!
    void doSomething2(A& a);
    // 클래스 A 와 B 의 위치를 바꾸고, 클래스 A 를 전방선언함으로써,
    // 클래스 B 의 doSomething2() 멤버함수는 클래스 A 의 존재는 인지하게 되었으나,
    // 클래스 A 의 private 멤버인 m_value 의 존재에 대해서는 아직 모르는 상태임.
    // 이럴 경우, doSomething2() 멤버함수의 프로토타입만 남겨둔 뒤, 
    // 클래스 A 정의 이후에 doSomething2() 의 구현부를 정의하면,
    // doSomething2() 는 이제 클래스 A 의 private 멤버 m_value 의 존재도 알 수 있으므로,
    // a.m_value 로 접근하는 코드에서 더 이상 컴파일 에러가 나지 않게 됨!
    //{
    //    cout << a.m_value << endl;
    //}
};

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

    // 클래스 B 를 클래스 A 의 친구 클래스로 등록!
    // 이제 클래스 B 는 클래스 A 의 private 멤버에도 접근이 가능함. why? 둘이 친구가 되었으니까!
    //friend class B;

    // 근데, class B 의 모든 멤버함수들이 내 사적인 private 멤버에 접근하는 건 부담스러우니,
    // class B 의 특정 멤버함수만 친구로 등록해서 접근을 허용하는 것도 가능함!
    friend void B::doSomething2(A& a);
};

// 클래스 A 가 정의된 이후 클래스 B 의 멤버함수 doSomething2() 를 구현함으로써,
// 클래스 A 의 private 멤버인 m_value 의 존재를 인지해서 접근할 수 있게 됨! 
void B::doSomething2(A& a)
{
    cout << a.m_value << endl;
}


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
    B b;
    doSomething(a, b);

    b.doSomething2(a);

    return 0;
} 