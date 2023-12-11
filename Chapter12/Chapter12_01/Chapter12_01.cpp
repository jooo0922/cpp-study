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

    // 각 클래스의 speak() 멤버함수 실행
    animal.speak();
    cat.speak();
    dog.speak();

    // 이번에는 Animal* (부모클래스)타입의 포인터 변수에 Cat, Dog (자식클래스) 인스턴스 주소값을 저장해보자
    Animal* ptr_animal1 = &cat;
    Animal* ptr_animal2 = &dog;

    // 그 다음, 각 부모클래스 타입 포인터 변수로부터 speak() 를 실행해보면?
    // 자식클래스 인스턴스의 주소값을 부모클래스 타입의 주소값으로 casting 한 다음, 
    // casting 된 주소값이 담긴 포인터 변수를 통해 호출시키면, 자기가 부모클래스인 줄 알고 작동을 함!
    ptr_animal1->speak();
    ptr_animal2->speak();


    return 0;
}