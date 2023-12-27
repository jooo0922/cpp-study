#include <iostream>

using namespace std;

// 부모 클래스
class Base
{
public:
    // 생성자 함수
    Base() {}

    // 출력 스트림 연산자 오버로딩 (친구함수로 등록해서 오버로딩)
    // -> 친구함수는 '클래스의 멤버가 아니기' 때문에 자식 클래스에서 '직접적으로' override 할 수는 없음!
    friend ostream& operator << (ostream& out, const Base& b)
    {
        // 자식 클래스에서 오버로딩할 출력 멤버함수 호출
        // -> 친구함수를 직접 오버로딩할 수는 없기 때문에, '간접적으로' override 하기 위해,
        // 임의의 가상 멤버함수를 만들고 난 뒤, 얘한테 override 하고 싶은 작업들을 다 떠넘긴 것!
        return b.print(out);
    }

    // 출력 스트림을 반환하는 가상함수 구현 (상수함수로 구현 > 클래스 멤버의 불변성 보장)
    virtual ostream& print(ostream& out) const
    {
        out << "Base";

        // 등록된 친구함수에서 호출하기 때문에, 출력 스트림을 반환해줘야 함.
        return out;
    }
};

int main()
{
    return 0;
}