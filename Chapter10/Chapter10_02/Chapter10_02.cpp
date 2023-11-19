//#include <iostream> // Monster.h 에서 이미 include 하고 있으므로 중복 include 불필요
#include "Monster.h" // Monster 클래스 생성을 위해 포함

using namespace std;

int main()
{
    Monster mon1("Sanson", Position2D(0, 0));

    /*
        아래와 같이,

        Position2D 는 Monster 클래스의 다른 정보(몬스터 이름 등..)에 대해 알지 못하지만,
        Monster 는 이 Position2D 클래스를 가져다 쓰고 있고, 
        
        다른 클래스(ex> Warrior 클래스 등..)도 위치값을 나타내기 위해 
        Position2D 클래스를 사용할 수 있겠지!

        다만, Position2D 클래스로 만들어진 인스턴스 멤버인 m_location 자체는
        다른 클래스에 속하거나 사용될 수 없다!

        이런 의미에서 '다른 클래스에서 속할 수 있는가? No' 라고 강의에서 말했던 것임!

        또한, Monster 클래스의 인스턴스 mon1 이 사라지면,
        거기에 속해있던 Position2D 클래스 인스턴스 m_location 도 같이 사라지겠지?

        또한, Monster 클래스가 작업을 할 때에는,
        Position2D 클래스에 어떤 인터페이스가 있는지 알고 있는 상태이지만,
        Position2D 클래스는 Monster 클래스에 어떤 인터페이스가 있는지 모르는 상태이지?
        이러한 것을 '방향성이 단방향이다' 라고 함!

        이를 '멤버의 존재를 클래스가 관리하는가? Yes' 라고 강의에서 말했던 것임!

        이때, 두 클래스 Monster 와 Position2D 의 관계를
        '구성 관계(Composition)' 라고 함!

        즉, Position2D 가 Monster 의 일부가 되는 관계!
    */
    //mon1.m_location;

    cout << mon1 << endl;
    
    //while (1) // game loop
    {
        // event
        // 몬스터 위치 이동
        mon1.moveTo(Position2D(1, 1));

        // 몬스터 정보를 출력 스트림 오버로딩 함수를 통해 출력
        cout << mon1 << endl;
    }
    
    return 0;
}