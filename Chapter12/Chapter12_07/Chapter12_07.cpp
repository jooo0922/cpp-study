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

    virtual void speak() const = 0;

    // 상수 멤버함수로 선언 -> 클래스 인스턴스 데이터 불변을 보장
    /*virtual void speak() const
    {
        cout << m_name << " ??? " << endl;
    }*/
};

void Animal::speak() const
{
    cout << m_name << " ??? " << endl;
}

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