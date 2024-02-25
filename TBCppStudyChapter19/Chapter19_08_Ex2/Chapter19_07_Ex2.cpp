#include <iostream>
#include <vector>
#include <cstdio>
#include <utility> // std::forward 사용을 위해 포함

using namespace std;

// std::vector 를 커스텀 구현한 클래스
class CustomVector
{
public:
    unsigned n_data = 0;
    int* ptr = nullptr;

    // default 생성자
    CustomVector(const unsigned& _n_data, const int& _init = 0)
    {
        cout << "Constructor" << endl;

        /*
            객체 지향 프로그래밍을 하다보면, 
            생성자에서 직접 초기화하기 보다는, 아래 init() 과 같이
            초기화하는 멤버 함수를 별도로 추출해서 사용하는 게 더 편리함.
        */
        init(_n_data, _init);
    }

    // copy constructor (매개변수는 l-value reference 로 선언)
    CustomVector(CustomVector& l_input)
    {
        cout << "Copy constructor" << endl;

        // 별도로 동적 배열 메모리 할당 및 초기화
        init(l_input.n_data);

        // 전달받은 다른 CustomVector 인스턴스를 깊은 복사
        for (unsigned i = 0; i < n_data; i++)
        {
            ptr[i] = l_input.ptr[i];
        }
    }

    // move constructor (매개변수는 r-value reference 로 선언)
    CustomVector(CustomVector&& r_input)
    {
        cout << "Move constructor" << endl;

        // 전달받은 r-value reference 인 CustomVector 인스턴스의 메모리 소유권(= 포인터 주소값)만 '이동'
        n_data = r_input.n_data;
        ptr = r_input.ptr; 

        // 전달받은 CustomVector 는 r-value reference 이므로, 메모리 소유권을 없애버려도 아무 상관 없음.
        // 어차피 r-value reference 는 메모리에 저장되어 있는 변수가 아니므로, 이 생성자 함수가 끝나면 사라져 버릴 것임.
        r_input.n_data = 0;
        r_input.ptr = nullptr;
    }

    // 소멸자 함수에서 할당된 동적 메모리 반납
    ~CustomVector()
    {
        delete[] ptr;
    }

    // 초기화 함수
    void init(const unsigned& _n_data, const int& _init = 0)
    {
        n_data = _n_data;
        ptr = new int[n_data]; // n_data 개수만큼 힙 메모리에 동적 배열 할당
        for (unsigned i = 0; i < n_data; i++)
        {
            // 할당된 동적 배열의 값들을 _init 으로 초기화
            ptr[i] = _init;
        }
    }
};

int main()
{
    CustomVector my_vec(10, 1024);

    cout << my_vec.n_data << endl;

    return 0;
}