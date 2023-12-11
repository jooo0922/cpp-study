#include <iostream>

using namespace std;

class A
{
public:
    /*
    * virtual 키워드
    * 
    * 부모 클래스에서 virtual 키워드로 정의된 가상함수가 있을 경우,
    * 자식 클래스에서 동일한 이름으로 
    * overriding 한 함수가 존재할 시,
    *
    * virtual 키워드가 붙은 가상함수가 아닌,
    * 상속받은 자식 클래스에서 overriding 된 함수가 실행됨!
    * 
    */
    virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
    // 최상위 부모 클래스 A 에 이미 print() 함수는 가상함수로 선언되어 있으므로, 
    // 자식클래스들에서 virtual 을 붙이는 게 문법적으로 큰 차이는 없음!
    // 그러나, 대부분의 프로그래머는 가독성 및 디버깅을 위해, virtual 이 존재하는 최상위 부모 클래스 밑에
    // 자식 클래스 들에도, 해당하는 멤버함수들에 모두 virtual 을 명시함으로써, 해당 멤버함수가
    // 부모 클래스로부터 overriding 하고 있음을 명확히 표시하는 경우가 많음!
    //virtual void print() { cout << "B" << endl; }
    void print() { cout << "B" << endl; }
};

class C : public B
{
public:
    //virtual void print() { cout << "C" << endl; }
    void print() { cout << "C" << endl; }
};

class D : public C
{
public:
    //virtual void print() { cout << "D" << endl; }
    void print() { cout << "D" << endl; }

    // 만약, overriding 하는 함수의 return type 이 다르면 어떡할 것인가? -> 일단 컴파일 안됨.
    // 항상 부모클래스의 함수를 overriding 할 때에는 return type 을 맞춰서 설계하도록!
    //virtual int print() { cout << "D" << endl; return 0; }
};

int main()
{
    A a;
    B b;
    C c;
    D d;

    // 이번에는 포인터 변수 말고, (물론 포인터 변수에 저장해도 똑같은 현상이 발생할 것임!)
    // 부모클래스 참조변수에 자식클래스 인스턴스를 저장해보자!
    A& ref = b;
    
    // 분명히 B 클래스의 인스턴스를 저장했는데,
    // 단지 부모클래스 A의 참조변수에 저장했다는 이유만으로, 
    // print() 멤버함수가 A 클래스의 멤버함수인 것처럼 작동하고 있음!
    //ref.print(); // A 출력

    // 그렇다면 이번에는, A 클래스의 print() 멤버함수에 virtual 키워드를 붙이면?
    // 이번에는 B 클래스의 print() 멤버함수가 제대로 실행됨!
    // -> 즉, B 클래스에서 'overriding 된' 함수를 그대로 사용할 수 있게 됨!
    ref.print(); // B 출력

    // 그렇다면, 이번에는 A 참조변수에 c 를 넣을 경우에도,
    // c 에서 overriding 된 print() 함수를 실행할까?
    // c 는 중간에 B 클래스를 거쳐서 상속받은 손자 클래스인데, 
    // A 클래스의 virtual 가상함수가 손자 클래스의 overriding 함수까지 실행할 수 있을까?
    // -> 정답은 실행 가능!
    A& ref2 = c;
    ref2.print(); // C 출력

    // 그렇다면, 이번에는 B 참조변수에 c 를 넣은 경우에도,
    // 즉, 부모클래스 B 에 명시적으로 virtual 이 선언된 가상함수가 없더라도,
    // c 에서 overriding 된 print() 함수를 실행할까?
    // -> 정답은 실행 가능!
    // 어째서? WHY?? 클래스 B 는 클래스 A 를 상속받는 구조이기 때문에,
    // 이런 식으로 상속 구조에서 최상위 부모 클래스를 타고 올라갔을 때, 
    // 최상위 부모 클래스에 virtual 로 정의된 멤버함수가 발견되었다면,
    // 그 밑에 있는 print() 들도 모두 virtual 처럼 행동한다고 이해하면 됨!
    B& ref3 = c;
    ref3.print(); // C 출력

    return 0;
}