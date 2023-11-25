#include "Student.h"
#include "Teacher.h"

int main()
{
    Student std("Jack Jack");

    // Student 클래스 자체에는 getter, setter 가 존재하지 않지만,
    // getter, setter 가 정의된 Person 클래스로부터 derived 되었기 때문에 사용 가능!
    std.setName("Jack Jack 2");
    std::cout << std.getName() << std::endl;

    Teacher teacher1("Dr. H");
    teacher1.setName("Dr. K");

    std::cout << teacher1.getName() << std::endl;

    // 각 클래스에 친구함수로 등록된 << 연산자 오버로딩 실행
    std::cout << std << std::endl;
    std::cout << teacher1 << std::endl;

    // 부모 클래스 Person 에 추가한 멤버함수인데
    // 자식 클래스인 Student, Teacher 모두에서 실행 가능! -> 이것이 상속의 장점!
    std.doNothing();
    teacher1.doNothing();

    // 각 자식 클래스에 각자에게 필요한 기능을 나눠서 구현
    std.study();
    teacher1.teach();

    Person person;
    person.setName("Mr. Incredible");
    person.getName();

    // 그러나, 자식 클래스에만 구현된 기능은 부모 클래스에서 사용 불가! 당연한 거지!
    //person.study(); 
    //person.teach();

    return 0;
}