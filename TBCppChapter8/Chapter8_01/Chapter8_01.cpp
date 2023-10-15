#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Object : 객체의 특성과 기능들을 묶여있는 것들을 개념적으로 생각하는 것이 '객체(Object)'
// 이러한 객체를 프로그래밍 문법으로 구현할 때 사용하는 키워드가 'Class'
// Friend : name, address, age, height, weight, ...
//          print()

/*
    Class 와 Struct

    Frient 객체에 대한 정보를 묶어주고자 한다면,
    Struct 로 묶어주는 것도 충분함.

    그러나, 더 많은 객체지향 기능을 지원하면서,
    멤버 변수 외에 함수까지 묶어버리고자 한다면,
    클래스를 쓰는 것이 적합함.

    참고로, C 에서는 Struct 에 함수를 추가하는 게 불가능함.
    반면, C++ 에서는 추가할 수는 있음.

    그럼에도 불구하고,
    일반적으로 멤버변수들만 묶을 때에는 Struct,
    함수들까지 추가할 때에는 Class 로 갈아타는 것이 일반적임!
*/
class Friend
{
public: // access specifier (접근 지정자. public, private, protected)
    string m_name; // 멤버변수라는 의미로 m_ 이라는 prefix 를 붙이기도 함.
    string address;
    int age;
    double height;
    double weight;

    void print()
    {
        cout << m_name << " " << address << " " << age << " " << height << " "
            << weight << endl;
    }
};

int main()
{
    // 클래스가 실제적으로 메모리를 점유하는 데이터로 생성되는 작업이 Instanciation
    // 이때 생성되는 객체 형태의 데이터 jj 를 Instance 라고 함.
    // 클래스 자체를 선언해도 메모리에 할당되는 것이 아님. 추상적인 객체의 구조만 정의해 둔 것이기 때문에!
    // 반면, 인스턴스는 해당 클래스의 구조를 갖춘 데이터가 실제로 메모리에 할당되는 게 차이점!
    Friend jj{ "Jack Jack", "Uptown", 2, 30, 10 };

    jj.print();

    // Frient 클래스 타입의 데이터를 담는 동적 배열을 vector 로 생성
    vector<Friend> my_friends;

    // Friend 타입의 데이터를 2개 넣을 수 있는 힙 메모리 공간을 할당 
    my_friends.resize(2);

    // for-each 문으로 동적 배열에 추가된 Friend 데이터들을 순회하며 어떤 처리를 할 수 있음.
    // Friend 데이터가 100개가 넘는 동적 배열이라면 이 방식이 아주 효과적이겠지!
    for (auto &ele : my_friends)
    {
        ele.print();
    }

    return 0;
}