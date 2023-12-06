#include <iostream>

using namespace std;

class USBDevice
{
private:
    long m_id;

public:
    USBDevice(long id) : m_id(id) {}

    long getID() { return m_id; }

    void plugAndPlay() {}
};

class NetworkDevice
{
private:
    long m_id;

public:
    NetworkDevice(long id) : m_id(id) {}

    long getID() { return m_id; }

    void networking() {}
};

// 여러 부모 클래스로부터 '다중 상속'
class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
    // 다중 상속받은 자식클래스에서는
    // 생성자 함수가 상속받은 각각의 부모클래스 생성자 함수로 전달할 매개변수를 따로 받아야할 수도 있고, 
    // 아니면 하나의 매개변수만 받아서 두 생성자 함수에 동일하게 전달할 수도 있음!
    USBNetworkDevice(long usb_id, long net_id)
        : USBDevice(usb_id), NetworkDevice(net_id)
    {}
};

int main()
{
    return 0;
}