#include <iostream>

using namespace std;

// 클래스 템플릿 구현
template<class T>
class A
{
private:
    T m_value;

public:
    // 생성자 함수
    A(const T& input)
        : m_value(input) // 멤버 초기화 리스트
    {}

    // m_value 멤버 출력 함수
    void print()
    {
        cout << m_value << endl;
    }
};

int main()
{
    return 0;
}