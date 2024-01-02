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
    // int 타입으로 template instantiation
    A<int> a_int(123);
    a_int.print();

    // int* (포인터 타입)으로 template instantiation
    int temp = 456;
    A<int*> a_int_ptr(&temp);
    a_int_ptr.print();

    // double* (포인터 타입)으로 template instantiation
    double temp_d = 3.141592;
    A<double*> a_double_ptr(&temp_d);
    a_double_ptr.print();

    return 0;
}