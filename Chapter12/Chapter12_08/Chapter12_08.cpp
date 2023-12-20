#include <iostream>

using namespace std;

/* 가상 기본 클래스를 통한 다이아몬드 상속 문제 해결 */

class PoweredDevice
{
public:
    int m_i;

    PoweredDevice(int power)
    {
        cout << "PoweredDevice: " << power << '\n';
    }
};

// 올바른 다이아몬드 상속 구조 구현을 위해 PoweredDevice 를 '가상 기본 클래스' 형태로 상속받음.
class Scanner : virtual public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power)
    {
        cout << "Scanner: " << scanner << '\n';
    }
};

// 올바른 다이아몬드 상속 구조 구현을 위해 PoweredDevice 를 '가상 기본 클래스' 형태로 상속받음.
class Printer : virtual public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power)
    {
        cout << "Printer: " << printer << '\n';
    }
};

// 이 손자클래스에서 자식클래스인 Scanner, Printer 를 둘 다 상속받는 과정에서
// '다이아몬드 상속 구조' 의 문제가 발생함!
class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power),
        PoweredDevice(power) // 가상 기본 클래스 구조로 상속받을 경우, 손자클래스에서 최상위 클래스 생성자를 별도로 호출해줘야 함!
    {
    }
};

int main()
{
    // 일단, 다이아몬드 상속 구조에서는
    // 아래와 같이 손자 클래스의 인스턴스를 생성하면,
    // PoweredDevice 생성자 함수가 각각 따로 호출됨.
    Copier cop(1, 2, 3);

    // 또한, 다이아몬드 상속 구조에서는
    // 아래와 같이, Scanner 클래스를 통해 접근한 PoweredDevice 의 m_i 멤버변수의 주소값과
    // Printer 클래스를 통해 접근한 PoweredDevice 의 m_i 멤버변수의 주소값이 서로 다름!
    // -> 즉, 서로 다른 PoweredDevice 클래스를 개별적으로 생성하고 있다는 뜻!
    // -> 이것은 우리가 원하는 다이아몬드 상속 구조가 아님!
    // -> 오로지 하나의 PoweredDevice 로부터 상속을 받고 싶다면 어떻게 하면 좋을까?
    // -> 이럴 때 중간 클래스인 Scanner 와 Printer 에서 PoweredDevice 클래스를 '가상 기본 클래스'로 상속받아야 함!
    // -> 이렇게 하면, PoweredDevice 의 생성자 함수도 1번만 호출되고, m_i 의 주소값도 모두 동일하게 출력됨!
    cout << &cop.Scanner::PoweredDevice::m_i << endl;
    cout << &cop.Printer::PoweredDevice::m_i << endl;

    return 0;
}