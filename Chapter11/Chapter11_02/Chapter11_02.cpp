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

    return 0;
}