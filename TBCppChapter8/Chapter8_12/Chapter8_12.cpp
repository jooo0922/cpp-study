#include <iostream>

using namespace std;

class A
{
private:
    int m_value = 1;

    // 이렇게 friend 키워드를 붙인 뒤,
    // private 멤버에 접근하는 함수의 프로토타입을 갖다 붙이기만 하면 됨!
    // 이제부터 doSomething 함수는 클래스 A 의 '친구 함수' 가 된 것임! 
    // 친구가 되었기 때문에, 캡슐화된 private 한 멤버에도 특별히 접근을 허용해 준다는 것이지!
    friend void doSomething(A& a);
};

// 이렇게 특정 함수에서 클래스 인스턴스를 참조변수로 입력받은 뒤,
// private 으로 캡슐화된 멤버에 접근해야 할 경우가 생긴다면?
// 특히, 연산자 오버로딩 구현할 때, 이런 형태의 코드를 많이 작성하게 됨.
// 이럴 때, private 을 public 으로 풀어버릴까? 그건 객체지향 원칙에 위배됨!
// 이럴 때 사용하는 것이, doSomething 함수를 클래스 A 의 'friend(친구 함수)' 로 만들어버리는 것임! 
void doSomething(A& a)
{
    cout << a.m_value << endl;
}

int main()
{
    A a;
    doSomething(a);

    return 0;
} 