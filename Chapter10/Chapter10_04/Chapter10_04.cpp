#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 컴파일러가 빌드할 때, Patient 클래스 하위에 정의한 Doctor 클래스를 읽지 못해서
// vector<Doctor*> 타입 멤버변수를 읽을 때 'undeclared identifier' 에러를 출력함 -> 각 클래스를 전방선언 해줘야 함!
// c++ 은 자바스크립트와 달리 '호이스팅' 을 지원하지 않음!

// forward declaration
/*
	앞서 구성관계와 집합관계는
	'상위 클래스 - 하위 클래스' 관계였기 때문에
	전방선언 자체가 불필요 했음.

	그러나, '제휴관계'는
	두 클래스 간의 관계가 상하 위계가 불분명하고,
	동등한 관계이기 때문에, 클래스들이 서로의 존재를 알고 있어야 하므로,
	'전방선언'이 필수!

	-> 지금 예제에서는 하나의 .cpp 파일 안에 구현되어 있지만,
	각 클래스를 헤더파일로 나누기 시작하면 전방선언 구현이 더 까다롭고 복잡해 짐.

	그래서, 사실 이러한 선언 구조의 복잡성 때문에
	제휴관계는 앞서 배운 두 관계보다 쓰임이 덜한 편!
*/
class Doctor;

class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors; // 환자가 만나야 하는 의사 목록을 동적 배열 멤버로 선언 (의사 클래스의 '주소값' 저장)

public:
	Patient(string name_in)
		: m_name(name_in)
	{}

	// 등록할 Doctor 주소값을 추가하는 멤버함수
	void addDoctor(Doctor* new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}
};

class Doctor
{
private:
	string m_name;
	vector<Patient*> m_patients; // 의사가 만나야 하는 환자 목록을 동적 배열 멤버로 선언

public:
	Doctor(string name_in)
		: m_name(name_in)
	{}

	// 등록할 Patient 주소값을 추가하는 멤버함수
	void addPatient(Patient* new_patient)
	{
		m_patients.push_back(new_patient);
	}
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