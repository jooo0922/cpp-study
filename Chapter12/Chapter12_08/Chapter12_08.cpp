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

class Scanner : public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power)
    {
        cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power)
    {
        cout << "Printer: " << printer << '\n';
    }
};

// 여기서 자식클래스인 Scanner, Printer 를 둘 다 상속받다보니
// '다이아몬드 상속' 문제가 발생함!
class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power)
    {
    }
};

int main()
{
    Copier cop(1, 2, 3);

    cout << &cop.Scanner::PoweredDevice::m_i << endl;
    cout << &cop.Printer::PoweredDevice::m_i << endl;

    return 0;
}