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


    return 0;
}