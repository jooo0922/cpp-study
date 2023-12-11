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
    // 'virtual' 키워드를 붙임으로써, 이 멤버함수는 '가상함수'가 됨.
    virtual void speak() const
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


    /* 위 성질을 활용할 수 있는 케이스 */

    // 각각의 자식클래스 정적 배열 초기화
    Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
    Dog dogs[] = { Dog("dog1"), Dog("dog2") };

    // 여기서, 두 배열에 대해서 반복문을 순회하고 싶다면?
    // 일반적으로는 각 배열에 대해서 for 문을 별도로 구현하고 싶겠지만,
    // Cat, Dog 모두 Animal 클래스로부터 상속받은 자식클래스니까, Animal 클래스 포인터로 한번에 묶어버려서
    // 반복문을 한 번에 돌리도록 처리할 수도 있지 않을까?
    Animal* my_animals[] = { &cats[0], &cats[1], &cats[2], &cats[3], &cats[4],
                             &dogs[0], &dogs[1] };

    // Animal 클래스 포인터로 묶어버린 정적 배열에 대해서 반복문을 한꺼번에 순회
    for (int i = 0; i < 7; i++)
    {
        // 그런데, Animal 클래스 포인터로 묶은 다음 speak() 를 실행하면 어차피 " ??? " 만 호출될텐데
        // 배열 하나로 묶어봤자 뭔 소용일까? -> 이럴 때, 부모클래스의 멤버함수 speak() 를 virtual(가상함수)로 만들어주면 됨!
        // -> 이렇게 함으로써, 부모클래스 타입의 포인터로 casting 된 자식클래스 인스턴스들이
        // 실제로도 '자식클래스인 것 처럼' 작동할 수 있게 됨! 
        // -> 이러한 성질을 '다형성' 이라고 함! 
        my_animals[i]->speak();
    }

    return 0;
}