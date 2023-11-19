#pragma once

#include <vector>
#include "Student.h" // Student 클래스를 멤버로 사용하기 위해 포함
#include "Teacher.h" // Teacher 클래스를 멤버로 사용하기 위해 포함

class Lecture
{
private:
	std::string m_name; // 강의명 멤버

	// 멤버변수가 완전히 해당 객체를 갖고있는 형태이므로, Lecture 클래스가 사라지면 하위 클래스들도 사라짐 -> 구성 관계(Composition Relationship)
	Teacher teacher; // 강의에 등록된 Teacher 클래스 멤버
	std::vector<Student> students; // 강의에 등록된 Student 클래스 인스턴스 동적 배열 멤버

	// 반면, 멤버변수가 각 객체가 저장된 메모리 '주소값'만 갖고 있는 포인터 변수로 선언되면, 
	// Lecture 클래스가 사라지더라도 하위 클래스는 사라지지 않음.
	// Teature* teature;
	// std::vector<Student*> students;

public:
	Lecture(const std::string& name_in)
		: m_name(name_in)
	{}

	~Lecture()
	{
		// do NOT delete teacher
		// do NOT delete students
	}

	// Lecture 클래스에 선생님을 등록하는 멤버 함수
	void assignTeacher(const Teacher& teacher_input)
	{
		teacher = teacher_input;
	}

	// Lecture 클래스에 학생을 추가하는 멤버 함수
	void registerStudent(const Student& student_input)
	{
		students.push_back(student_input);
	}

	// 공부를 실행하면 강의에 등록된 학생들의 intel 점수가 1씩 추가되는 멤버함수
	void study()
	{
		std::cout << m_name << " Study " << std::endl << std::endl;

		// for-each 문을 students 동적 배열에 돌려서 각 학생들의 intel 점수를 1씩 증가
		// for-each 문 사용 시 주의점: 각각의 element 를 참조변수로 받아야(auto&) 각 Student 인스턴스의 실제 멤버변수인 m_intel 값이 변경됨.
		for (auto& element : students)
		{
			element.setIntel(element.getIntel() + 1);
		}
	}

	// 출력 스트림 연산자 오버로딩을 친구 함수로 등록
	friend std::ostream& operator << (std::ostream& out, const Lecture& lecture)
	{
		out << "Lecture name : " << lecture.m_name << std::endl;

		// 강의에 등록된 Teacture 클래스 내부의 출력 스트림 오버로딩 실행
		out << lecture.teacher << std::endl; 

		// 강의에 추가된 Students 클래스 인스턴스들 내부의 출력 스트림 오버로딩 실행
		// 여기서는 멤버변수 값을 변경하지 않아도 되므로, 참조변수가 아닌 그냥 auto(자동 형변환) 타입으로 받음.
		for (auto element : lecture.students)
		{
			out << element << std::endl;
		}

		return out;
	}
};
