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
    USBNetworkDevice my_device(3.14, 6.022);

    // 다중상속을 받은 자식클래스는 부모클래스의 모든 기능을 동시에 사용할 수 있다는 장점이 있음.
    my_device.networking();
    my_device.plugAndPlay();

    // 반면, 부모클래스 간 서로 겹치는 기능을 실행할 때 문제가 발생함!
    //my_device.getID(); // ambiguous access of 'getID' 에러 발생 -> 즉, 어느 부모클래스의 getID() 를 실행해야 할 지 모르겠다는 뜻!

    // 이럴 때 해결 방법은 의외로 간단함.
    // 특정 부모클래스의 getID() 를 영역표시 연산자(::)로 명시하는 것!
    my_device.USBDevice::getID();
    my_device.NetworkDevice::getID();

    return 0;
}