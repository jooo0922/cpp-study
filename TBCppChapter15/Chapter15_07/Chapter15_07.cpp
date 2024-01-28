#include <iostream>
#include <memory>
#include <string>

class Person
{
    std::string m_name;
    std::shared_ptr<Person> m_partner; // shared_ptr 로 파트너 인스턴스의 주소값을 공유할 수 있겠군.

public:
    // 생성자 함수
    Person(const std::string& name) : m_name(name)
    {
        std::cout << m_name << " created\n";
    }

    // 소멸자 함수
    ~Person()
    {
        std::cout << m_name << " destroyed\n";
    }

    // 두 Person 인스턴스를 관리하는 shared_ptr 스마트 포인터 변수를 L value 참조변수로 받아서 
    // 서로 파트너 관계를 맺도록 해주는 함수를 친구 함수로 등록
    friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
    {
        // 두 shared_ptr 중 하나라도 nullptr 일 경우, 함수 중단
        if (!p1 || !p2)
        {
            return false;
        }

        /*
            두 shared_ptr 인 p1, p2 가 관리하는 
            각각의 Person 클래스 인스턴스 내부의 shared_ptr 인
            m_partner 를 통해

            서로가 관리하는 Person 클래스의 메모리를
            공유할 수 있도록 함!
        */
        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout << p1->m_name << " is partnered with " << p2->m_name << "\n";

        return true;
    }

    // 이름 문자열을 반환하는 상수 멤버함수 구현
    const std::string& getName() const
    {
        return m_name;
    }
};

int main()
{
    return 0;
}