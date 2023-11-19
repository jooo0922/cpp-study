#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

using namespace std;

int main()
{
    // 집합관계(Aggregation Relationship)로 변경하기 위해, 각 하위 클래스를 별개의 인스턴스로 우선 생성함
    //Student std1("Jack Jack", 0);
    //Student std2("Dash", 1);
    //Student std3("Violet", 2);

    //Teacher teacher1("Prof. Hong");
    //Teacher teacher2("Prof. Good");

    // 위와 같이 local variable 로 하위 클래스를 생성하면, main 함수 scope 종료 시 메모리가 자동으로 반환되도록 할 수도 있지만,
    // 만약 현재 scope 가 main 함수가 아니거나, 함수가 종료되더라도 해당 인스턴스들이 필요할 경우, 
    // 아래와 같이 new 키워드로 힙 메모리에 동적 할당할 수도 있음!
    Student* std1 = new Student("Jack Jack", 0);
    Student* std2 = new Student("Dash", 1);
    Student* std3 = new Student("Violet", 2);

    Teacher* teacher1 = new Teacher("Prof. Hong");
    Teacher* teacher2 = new Teacher("Prof. Good");


    // Composition Relationship (기존에 구성관계로 구현된 각 클래스 사이의 관계)
    //Lecture lec1("Introduction to Computer Programming");
    //lec1.assignTeacher(&teacher1);
    //lec1.registerStudent(&std1);
    //lec1.registerStudent(&std2);
    //lec1.registerStudent(&std3);

    //Lecture lec2("Computational Thinking");
    //lec2.assignTeacher(&teacher2);
    //lec2.registerStudent(&std1);

    // 동적 할당으로 하위 클래스를 생성했다면, 위 변수들 자체가 포인터 변수, 즉 주소값이므로,
    // &(앰퍼샌드. 주소연산자) 없이 바로 매개변수로 넘겨줘도 됨.
    Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(teacher1);
    lec1.registerStudent(std1);
    lec1.registerStudent(std2);
    lec1.registerStudent(std3);

    Lecture lec2("Computational Thinking");
    lec2.assignTeacher(teacher2);
    lec2.registerStudent(std1);

    // test
    {
        // 현재 두 Lecture 에 등록된 선생님과 학생들 정보 출력
        cout << lec1 << endl;
        cout << lec2 << endl;

        // lec2 에서 study 실행 -> lec2 에 등록된 학생들의 intel 지수 증가
        lec2.study();

        // lec2.study() 실행 후 두 Lecture 에 등록된 선생님과 학생 정보 재출력
        // Student("Jack Jack", 0) 은 한 명의 동일한 학생이지만, lec1 과 lec2 에 추가될 때, 각각 인스턴스가 따로 생성되서 추가되었기 때문에,
        // lec2 에 등록된 Jack Jack 의 intel 지수는 1로 증가되었지만, lec1 에 등록된 Jack Jack 의 intel 지수는 0 으로 그대로임!
        // -> 이것이 하위 클래스가 상위 클래스에 일부분으로 포함되어 있는 '구성 관계'의 한계점! -> 즉, 하위 클래스가 '동기화(sync)'되지 못함!
        // -> 이를 해결하려면 '구성 관계' 를 좀 더 느슨한 클래스간 관계를 지향하는 '집합 관계'로 바꿔줘야 한다!
        // 이렇게 하려면, 각각의 Student, Teacher 하위 클래스를 상위 클래스에서 '주소값'으로 관리해야 각 클래스 간 관계가 더 느슨해진다!
        cout << lec1 << endl;
        cout << lec2 << endl;
    }

    // 만약, 하위 클래스를 new 키워드로 동적 할당 해줬다면, 
    // scope 종료 직전에는 항상 delete 키워드로 메모리 반납을 해줘야지!
    delete std1;
    delete std2;
    delete std3;

    delete teacher1;
    delete teacher2;

    return 0;
}