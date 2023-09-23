#include <iostream>

using namespace std;

struct Person
{
    int age;
    double weight;
};

int main()
{
    Person person;
    
    // 구조체나 클래스의 멤버에 접근할 때 사용하는 연산자 . 은 멤버 선택 연산자(Member Selection Operator) 라고 함.
    person.age = 5;
    person.weight = 30;

    // 참조변수를 통해 구조체나 클래스의 멤버에 접근하는 방법
    Person& ref = person;
    ref.age = 15; // 참조변수를 통해 접근하더라도, 멤버 선택 연산자를 사용해야 함은 변함이 없음

    // 포인터 변수를 통해 구조체나 클래스의 멤버에 접근하는 방법
    Person* ptr = &person;
    ptr->age = 30; // 포인터 변수를 통해 접근하면, . 이 아닌, ->(화살표) 로 접근해야 함!
    (*ptr).age = 20; // 물론, 포인터 변수를 de-referencing 해서 직접 원본변수 person 을 통해 접근한다면, 당연히 . 으로 접근 가능!

    Person& ref2 = *ptr; // 이는 결국 Person& ref2 = person; 과 동일함. (ptr 포인터 변수의 de-referencing 이 결국 person 이니까!)
    ref2.age = 45;

    // 아래 두 변수는 동일한 주소가 출력됨
    cout << &person << endl;
    cout << &ref2 << endl; // 결국 ref2 는 원본변수 person 에 대한 참조변수구나! 

    return 0;
}