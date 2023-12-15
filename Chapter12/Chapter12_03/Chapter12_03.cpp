#include <iostream>

using namespace std;

class A
{
public:
    virtual void print(int x) { cout << "A" << endl; }
};

class B : public A
{
public:
    //virtual void print() { cout << "B" << endl; }
    /*
        print() 멤버함수를 overriding 할 때, 
        실수로 매개변수 타입을 다르게 지정하면 어떻게 될까?

        안타깝게도 overriding 이 정상 작동하지 않음.

        why? 컴파일러는 멤버함수의 매개변수나 반환값의 타입이 다르면
        'overriding' 이 아니라 '오버로딩'을 한 것으로 인식하므로,
        부모 클래스의 virtual void print(int x) 멤버함수를 overriding 하지 못함!


        -> 이러한 문제들을 사전에 방지해주는 문법이 'override' 키워드!

        이 키워드를 붙이면,
        "이 멤버함수는 부모 클래스에 존재하는 virtual 멤버함수를 override 하려는 겁니다!"
        라고 명시하는 것과 동일함.

        그렇기 때문에, 컴파일러가 이를 'overriding' 시도하려는 것으로 인지해서
        만약 매개변수나 반환값 타입을 실수로 다르게 작성하면
        '그렇게 하면 overriding 못해!' 라고 미리 에러를 발생시킴! 
    */
    //void print(short x) { cout << "B" << endl; }
    //void print(int x) override { cout << "B" << endl; }

    /*
        한 편, final 키워드의 역할은 뭘까?

        이 키워드가 붙은 멤버함수는
        이 클래스를 상속받는 자식 클래스들이
        더 이상 해당 멤버함수를 override 하지 못하게 막아버리는 역할!
    */
    void print(int x) final { cout << "B" << endl; }
};

class C : public B
{
public:
    //virtual void print(int x) { cout << "C" << endl; }
};

class AA
{
public:
    void print() { cout << "AA" << endl; }
    virtual AA* getThis() 
    {
        cout << "AA::getThis()" << endl;
        return this; 
    }
};

class BB : public AA
{
public:
    void print() { cout << "BB" << endl; }

    /*
        공변 반환값 (covariant)

        위에서 반환값 타입이 다르면 멤버함수는
        overriding 이 안된다고 했었지?

        그런데, 반환값 타입으로 지정된 두 클래스 AA 와 BB 가
        서로 '부모 - 자식' 관계라면, 예외적으로 overriding 가능!
    */
    virtual BB* getThis() 
    { 
        cout << "BB::getThis()" << endl;
        return this; 
    }
};

int main()
{
    A a;
    B b;
    //C c;

    A& ref = b;
    ref.print(1);

    /* 공변 반환값(covariant) 테스트 */ 
    AA aa;
    BB bb;

    AA& ref2 = bb;

    // BB::getThis() 실행 후, BB 출력
    bb.getThis()->print(); 

    // BB:getThis() 실행 후, AA 출력
    /*
        왜 이런 결과가 나올까?

        getThis() 멤버함수는 virtual 키워드에 의해
        자식클래스 BB 에서 overriding 되었기 때문에,

        자식클래스 인스턴스 bb 를 저장한 참조변수 ref2 를 통해
        getThis() 멤버함수를 실행하면, 
        당연히 BB::getThis() 가 실행되는 것은 지극히 정상!

        그러나, 한편으로는
        ref2 는 AA 클래스 타입의 참조변수이기 때문에,
        BB::getThis() 가 실행되더라도, 
        
        반환값을 중간에 AA* 타입의 주소값으로 
        바꿔치기해서 반환해주므로,
        AA*->print() 형태로 실행되었던 것이고,

        그로 인해 마지막으로는 AA 가 출력되었던 것임!
    */
    ref2.getThis()->print(); 

    return 0;
}