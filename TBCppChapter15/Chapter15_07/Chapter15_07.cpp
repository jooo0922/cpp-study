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
    // 각 Person 클래스를 shared_ptr 스마트 포인터로 관리
    auto lucy = std::make_shared<Person>("Lucy");
    auto ricky = std::make_shared<Person>("Ricky");

    // partnerUp 친구 함수를 실행해서 두 Person 클래스가 내부적으로
    // 서로의 메모리를 shared_ptr 포인터로 공유할 수 있도록 함
    /*
        이 때, 두 Person 클래스 인스턴스가 
        shared_ptr 로 공유되긴 하지만,
        
        main() block 이 종료가 되어도
        소멸자 함수가 호출되지 않음.

        즉, shared_ptr 이 사라지지 않아서
        memory leak 이 발생하고 있는 상황이겠지!

        왜 이런 일이 발생하는 걸까?

        각각의 Person 을 관리하는
        shared_ptr 인 lucy, ricky 를 지우려고 하더라도,
        
        이미 각 Person 내부에서 서로의 메모리 소유권을 공유하는
        또 다른 shared_ptr 인 m_partner 가 존재하기 때문에,

        모든 shared_ptr 이 사라질 수 없어서
        Partner 클래스 자체의 메모리가 지워지지 못하고 있는 상태인 것!

        -> 즉, 메모리 소유권이 '순환'되어서 꼬이게 된 것임!

        -> 이를 해결하기 위해 사용하는 또 다른 스마트 포인터가 std::weak_ptr 임!
    */
    partnerUp(lucy, ricky);

    return 0;
}