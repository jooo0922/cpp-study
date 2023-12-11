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
    void print() { cout << "B" << endl; }
};

class C : public B
{
public:
    void print() { cout << "C" << endl; }
};

class D : public C
{
public:
    void print() { cout << "D" << endl; }
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
    ref2.print();

    return 0;
}