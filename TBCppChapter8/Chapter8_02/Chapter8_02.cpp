#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    access specifier (접근 지정자) 

    클래스 외부에서 해당 멤버들에 접근할 수 있게 해줄 것인지 결정. 
    c++ 은 기본값이 private

    이때, 클래스 멤버들은 private 으로 감춰놓고,
    "내가 지정한 방법을 통해서만 이 멤버들에 접근하도록 해!"
    라고 선언하는 함수들이 access function (접근 함수)

    -> 이런 식으로,
    접근 지정자와 접근 함수를 사용해서
    클래스 멤버에 대해 안전하게 접근할 수 있도록 만드는 과정을
    Encapsulation (캡슐화) 라고 함!
*/
class Date
{
private: 
    int m_month;
    int m_day;
    int m_year;

public:
    // set 함수의 매개변수는 내부에서 수정할 일이 없으므로, 입력 매개변수(const 참조변수)로 선언
    void setDate(const int& month_input, const int& day_input, const int& year_input)
    {
        m_month = month_input;
        m_day = day_input;
        m_year = year_input;
    }

    void setMonth(const int& month_input)
    {
        m_month = month_input;
    }

    void setDay(const int& day_input)
    {
        m_day = day_input;
    }

    void setYear(const int& year_input)
    {
        m_year = year_input;
    }

    // 멤버를 읽을 때에도, 직접 멤버에 접근하는 게 아니라, get 함수를 통해서만 접근하도록 함.
    // 그냥 int 타입으로 반환하면 멤버의 값이 복사가 되기 때문에, 복사로 인한 메모리 낭비를 방지하기 위해,
    // 참조형으로 int& 와 같이 반환 타입을 지정하는 경우가 있는데, 이럴 경우, 외부에서 반환된 멤버를 수정하지 못하도록,
    // const int& 처럼 const 참조형으로 반환 타입을 지정해줘야 함.
    //int getDay()
    const int& getDay() 
    {
        return m_day;
    }

    // copy 함수는 이미 생성된 인스턴스를 넘겨받은 후, 해당 인스턴스의 멤버의 값들을 복사해서
    // 현재 인스턴스에 할당하고자 할 때 구현해서 사용함
    void copyFrom(const Date& original)
    {
        // 입력 매개변수 original 이 다른 인스턴스(즉, 저장된 메모리 공간이 다른...)가 전달되었음에도 불구하고,
        // private 멤버에 직접 접근할 수 있는 이유는,
        // 현재 인스턴스와 매개변수로부터 전달받은 인스턴스가 '같은 class 로부터 나왔기 때문에' 접근이 가능한 것!
        m_month = original.m_month;
        m_day = original.m_day;
        m_year = original.m_year;
    }
};

int main()
{
    /*
        클래스에 의해 묶인 변수들은
        외부에서 접근해서 변경하거나 건드리려고 하면
        컴파일러가 에러를 발생시킴.

        -> 마치 클래스가
        "이거는 클래스 안에 묶여있는 거니까 밖에서 건들지 마!"
        라고 말하는 것과 같음.

        왜냐하면, c++ 클래스는
        접근 지정자가 기본값으로 private 이기 때문에,
        별도로 멤버들의 접근 지정자를 지정해주지 않으면,
        외부에서 해당 멤버들에 접근이 막혀버림.

        이 말은 즉,
        멤버들의 접근 지정자를 public 으로 지정하면,
        컴파일 에러 없이 멤버에 접근 가능!
    */
    Date today;
    /*today.m_month = 8;
    today.m_day = 4;
    today.m_year = 2025;*/

    today.setDate(8, 4, 2025);
    today.setMonth(8);

    cout << today.getDay() << endl;

    Date copy;
    copy.copyFrom(today);

    return 0;
}