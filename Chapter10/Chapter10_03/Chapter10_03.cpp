#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

using namespace std;

int main()
{
    // Composition Relationship (기존에 구성관계로 구현된 각 클래스 사이의 관계)
    Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(Teacher("Prof. Hong"));
    lec1.registerStudent(Student("Jack Jack", 0));
    lec1.registerStudent(Student("Dash", 1));
    lec1.registerStudent(Student("Violet", 2));

    Lecture lec2("Computational Thinking");
    lec2.assignTeacher(Teacher("Prof. Good"));
    lec2.registerStudent(Student("Jack Jack", 0));

    // TODO : implement Aggregation Relationship (기존 구성관계를 '집합관계'로 수정!)

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
        cout << lec1 << endl;
        cout << lec2 << endl;
    }

    return 0;
}