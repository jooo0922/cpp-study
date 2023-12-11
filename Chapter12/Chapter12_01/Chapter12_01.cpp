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

    // 상수 멤버함수로 선언 -> 클래스 인스턴스 데이터 불변을 보장
    // const 인스턴스에서 사용 가능
    void speak() const
    {
        cout << m_name << " ??? " << endl;
    }
};

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
    Animal animal("my animal");
    Cat cat("my cat");
    Dog dog("my dog");

    return 0;
}