#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Patient
{
private:
	string m_name;

public:
	Patient(string name_in)
		: m_name(name_in)
	{}
};

class Doctor
{
private:
	string m_name;

public:
	Doctor(string name_in)
		: m_name(name_in)
	{}
};

int main()
{
	// 환자 클래스 동적 할당으로 힙 메모리에 생성
	Patient* p1 = new Patient("Jack Jack");
	Patient* p2 = new Patient("Dash");
	Patient* p3 = new Patient("Violet");

	// 의사 클래스 동적 할당으로 힙 메모리에 생성
	Doctor* d1 = new Doctor("Doctor K");
	Doctor* d2 = new Doctor("Doctor L");

	// patient meet doctors

	// doctors meet patients

	// 동적 할당으로 생성된 클래스들을 scope 종료 직전에 메모리 해제
	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;

    return 0;
}