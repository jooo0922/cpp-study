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

/*
    만약,
    템플릿 파라미터가 포인터 타입으로 입력될 경우,
    포인터 타입에 대한 template specialization 을 어떻게 할까?

    예를 들어,
    포인터 타입의 변수를 출력하면 항상 주소값만 나올테니,
    그 주소값을 de-referencing 하여 실제 저장된 값을 출력하는
    특수한 작업을 별도로 specialization 하고 싶을 수 있잖아!

    그럴 경우,
    아래와 같이 포인터 타입에 대해서만
    템플릿 특수화를 별도로 선언할 수 있음!
*/
template<class T> // 포인터 타입 템플릿 특수화의 경우, 기존 템플릿 매개변수를 제거하지 말고 그대로 냅둠!
class A<T*> // 포인터 타입의 클래스 템플릿에 대해서만 specialization 된 클래스임을 선언
{
private:
    T* m_value;

public:
    // 생성자 함수
    A(T* input)
        : m_value(input) // 멤버 초기화 리스트
    {}

    // m_value 멤버 출력 함수
    void print()
    {
        // 포인터 타입의 템플릿일 경우, 주소값을 de-referencing 하여 출력하는 작업을 수행하도록 함.
        cout << *m_value << endl;
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