#include <iostream>
#include <string>

using namespace std;

// 사람에 대한 정보를 다룰 때, 이렇게 모든 정보들을 인자로 받아서 사용하기는 번거롭겠지
//void printPerson(double height, float weight, int age)
//{
//
//}

// '사람'에 대한 모든 정보들을 하나의 '구조체'에 담아서 다루기 용이하도록 함! > 이것이 struct(구조체)를 사용하는 이유!
// '사용자 정의 자료형'이라고도 함
struct Person {
    // 구조체 멤버변수를 정의하는 시점에 각 멤버변수의 값을 초기화하는 것도 가능!
    // > 즉, 기본값을 넣어주는 개념!!
    double height = 3.0;
    float weight = 200.0f;
    int age = 100;
    string name = "Mr.Incredible";

    // 그런데, Person 과 관련된 함수인데, 얘도 구조체 안에서 관리할 수는 없을까? 있다!
    // 구조체 안의 여러 '데이터'들을 가지고 어떠한 '기능'을 하는 함수들도 구조체 안에서 관리 가능! > '데이터'와 '기능'이 묶이게 됨!
    void print()
    {
        // 구조체 안에서 관리되는 함수는 구조체 데이터를 . (멤버 선택 연산자) 없이 접근 가능!
        cout << height << " " << weight << " " << age << " " << name;
        cout << endl;
    }
};

struct Family
{
    // 구조체 안의 데이터 타입을 또 다른 구조체로 정의할 수 있음!
    Person me, mom, dad;
};

// 구조체를 반환 타입으로 지정하는 함수를 만들수도 있음!
Person getMe()
{
    Person me{ 2.0, 100.0f, 20, "Jack Jack" };

    return me;
}

void printPerson(Person ps)
{
    // 구조체 내의 멤버들에 접근할 때에는 . 을 찍게 되어있음. > 이 연산자를 member selection operator (멤버 선택 연산자) 라고 함. 
    cout << ps.height << " " << ps.weight << " " << ps.age << " " << ps.name;
    cout << endl;
}

// 구조체 데이터 크기 측정
// Employee 구조체의 메모리 크기는 구조체의 각 멤버변수를 더한 값이겠지?
// > 2 + 4 + 8 = 14 bytes > 이 값이 Employee 를 저장하기 위해 필요한 최소 메모리여야겠지?
struct Employee
{
    short   id; // 2 bytes
    int     age; // 4 bytes
    double  wage; // 8 bytes
};

int main()
{
    // '사람' 에 대한 정보를 정의하는 변수들
    // 이 정보들을 각각의 사람마다 따로 height1, height2 이렇게 정의하기도 번거로움
    //double height;
    //float weight;
    //int age;
    //string name;

    Person me{2.0, 100.0f, 20, "Jack Jack"}; // Uniform Initialization 을 활용한 구조체 초기화! (최신 방식)
    //printPerson(me); // 맨 윗쪽에 주석처리해놓은 함수와 달리 구조체 인자 하나만 통째로 전달하면 되니 더 편리함!
    me.print(); // 구조체 안에 정의한 함수를 호출하는 방식!

    // 구조체를 구조체 변수에 대입하는 것도 가능!
    Person me2;
    me2 = me;
    me2.print();

    Person me_from_func = getMe();
    me_from_func.print();

    Person me3;
    cout << me3.name << endl;

    // 옛날에 구조체를 초기화했던 방식
    //me.age = 20;
    //me.height = 2.0;
    //me.weight = 100.0f;
    //me.name = "Jack Jack";

    Employee emp1;

    // sizeof() 함수는 구조체의 메모리 크기를 측정할 때도 사용 가능
    cout << sizeof(Employee) << endl; // 16. -> ??? 14 bytes 로 나와야하지 않나?

    // 구조체의 경우, 데이터를 더 잘 처리할 수 있는 형태로 저장해야 해서
    // 2 bytes 로 저장이 잘 안되고, 2 bytes 옆에 빈칸으로 2 bytes 가 더 저장됨.
    // 따라서, 2 + (2) + 4 + 8 = 16 bytes 로 나왔던 것!
    // 이런 + (2) 추가되는 개념을 'padding' 이라고 함!

    return 0;
}