#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string m_name;

public:
    Animal(string name)
        : m_name(name)
    {}

    string getName() { return m_name; }

    // 상수 멤버함수로 가상함수 선언
    /*
        그런데, 
        아래 가상함수의 구현부처럼
        추상클래스 Animal 의 기본 작업을 꼭 채워넣어야만 하나?

        그냥 상속받는 Dog, Cat 에서만
        각 동물들의 고유한 울음소리를 반드시 구현하도록 하고,
        
        부모클래스인 Animal 에서는
        그냥 가상함수를 "선언만" 할 수는 없을까?

        이런 니즈에서 만들어진 것이
        아래와 같은 "순수 가상함수"
    */
    /*virtual void speak() const
    {
        cout << m_name << " ??? " << endl;
    }*/

    // 아래와 같이, virtual 키워드를 추가하고, 구현부는 생략한 채,
    // 함수 선언부 뒤에 '= 0' 을 붙이면, 이것을 '순수 가상함수(pure virtual function)' 라고 함!
    virtual void speak() const = 0;
};

// 물론, 아래와 같이 클래스 namespace 바깥에서
// 순수 가상함수의 구현부를 직접 정의하는 것도 가능하기는 함! 
// -> 그러나, 아래 구현부는 사실상 호출이 불가능하므로, 쓸모가 없는 것이나 마찬가지임!
//void Animal::speak() const
//{
//    cout << m_name << " ??? " << endl;
//}

// 부모 클래스 Animal 을 상속받는 자식 클래스들
class Cat : public Animal
{
public:
    Cat(string name)
        : Animal(name)
    {}

    void speak() const
    {
        cout << m_name << " Meow " << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string name)
        : Animal(name)
    {}

    void speak() const
    {
        cout << m_name << " Woof " << endl;
    }
};

int main()
{
    return 0;
}