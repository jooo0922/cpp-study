#pragma once

#include <vector>
#include "Student.h" // Student 클래스를 멤버로 사용하기 위해 포함
#include "Teacher.h" // Teacher 클래스를 멤버로 사용하기 위해 포함

class Lecture
{
private:
	std::string m_name; // 강의명 멤버

	// 멤버변수가 완전히 해당 객체를 갖고있는 형태이므로, Lecture 클래스가 사라지면 하위 클래스들도 사라짐 -> 구성 관계(Composition Relationship)
	//Teacher teacher; // 강의에 등록된 Teacher 클래스 멤버
	//std::vector<Student> students; // 강의에 등록된 Student 클래스 인스턴스 동적 배열 멤버

	// 반면, 멤버변수가 각 객체가 저장된 메모리 '주소값'만 갖고 있는 포인터 변수로 선언되면, 
	// Lecture 클래스가 사라지더라도 하위 클래스는 사라지지 않음.
	// 또한, 동적 배열 students 에 하위 클래스 Student 객체를 추가할 때, '주소값'을 추가하는 방식으로 변경하면
	// push_back() 에 의해 객체가 복사되어 추가되는 이슈를 해결할 수 있음!
	// 이러한 이유로, 클래스들 간의 관계를 '집합관계'로 만들 때에는 하위 클래스를 '주소값'으로 관리하는 게 좋음!
	Teacher* teacher;
	std::vector<Student*> students;

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
	//void assignTeacher(const Teacher& teacher_input)
	/*
		클래스들 간 관계를 '집합관계' 로 만들기 위해, 
		하위 클래스 Teacher 의 '주소값'을 매개변수로 받도록 수정

		이때, const Teacher* 와 Teacher* const 의 차이점은, 
		Teacher* const 는 실제로 해당 포인터 변수의 '주소값'을 불변으로 만들어버리는 것이고, (진정한 의미의 const 포인터 변수)
		const Teacher* 는 해당 변수를 'de-referencing 한 객체'를 불변으로 만들어 버림!

		두 타입의 차이점 관련
		https://github.com/jooo0922/cpp-study/blob/main/TBCppStudy/Chapter6_13/Chapter6_13.cpp 참고!
	*/
	void assignTeacher(Teacher* const teacher_input)
	{
		teacher = teacher_input;
	}

	// Lecture 클래스에 학생을 추가하는 멤버 함수
	//void registerStudent(const Student& student_input)
	/*
		클래스들 간 관계를 '집합관계' 로 만들기 위해,
		하위 클래스 Student 의 '주소값'을 매개변수로 받도록 수정
	*/
	void registerStudent(Student* const student_input)
	{
		/*
			이때, 
			
			std::vector 는 .push_back() 멤버함수로
			컨테이너에 동적으로 요소를 추가하는 시점에,
			
			해당 요소가 '복사'되어 추가되기 때문에
			student_input 매개변수가 참조변수로 입력된다고 하더라도,

			실제로 students 동적 배열에 추가된 요소와 '다른 객체'가 된다!

			즉, &student_input != &students[0] 이라는 것!

			-> 구성관계를 집합관계로 바꾸는 과정에서 이러한 오류를 피하려면,
			하위클래스(Student, Teacher)의 '주소값'을 동적 배열에 저장해두면 되겠지!
		*/
		students.push_back(student_input);
	}

	// 공부를 실행하면 강의에 등록된 학생들의 intel 점수가 1씩 추가되는 멤버함수
	void study()
	{
		std::cout << m_name << " Study " << std::endl << std::endl;

		// for-each 문을 students 동적 배열에 돌려서 각 학생들의 intel 점수를 1씩 증가
		// for-each 문 사용 시 주의점: 각각의 element 를 참조변수로 받아야(auto&) 각 Student 인스턴스의 실제 멤버변수인 m_intel 값이 변경됨.
		/*for (auto& element : students)
		{
			element.setIntel(element.getIntel() + 1);
		}*/

		// 이제 students 는 포인터(주소값)들의 동적 배열이므로, 그에 맞게 for-each 문도 변경!
		for (auto element : students)
		{
			// 각 element 는 포인터 변수이므로, de-referencing 또는 포인터 멤버변수 참조 연산자 -> 를 사용할 것 
			(*element).setIntel((*element).getIntel() + 1);
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
			//out << element << std::endl;
			
			// 여기서도 각 element 가 포인터 변수이므로, de-referencing 으로 실제 Student 객체에 접근해야,
			// 해당 Student 객체에 정의된 << 오버로딩 함수가 실행되겠지!
			out << *element << std::endl;
		}

		return out;
	}
};
