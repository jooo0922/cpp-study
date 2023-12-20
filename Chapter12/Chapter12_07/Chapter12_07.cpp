#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string m_name;

public:
    Animal(string name)
        : m_name(name)
    {}

    string getName() { return m_name; }

    // 상수 멤버함수로 가상함수 선언
    /*
        그런데, 
        아래 가상함수의 구현부처럼
        추상클래스 Animal 의 기본 작업을 꼭 채워넣어야만 하나?

        그냥 상속받는 Dog, Cat 에서만
        각 동물들의 고유한 울음소리를 반드시 구현하도록 하고,
        
        부모클래스인 Animal 에서는
        그냥 가상함수를 "선언만" 할 수는 없을까?

        이런 니즈에서 만들어진 것이
        아래와 같은 "순수 가상함수"
    */
    /*virtual void speak() const
    {
        cout << m_name << " ??? " << endl;
    }*/

    // 아래와 같이, virtual 키워드를 추가하고, 구현부는 생략한 채,
    // 함수 선언부 뒤에 '= 0' 을 붙이면, 이것을 '순수 가상함수(pure virtual function)' 라고 함!
    // 추상 클래스의 설계자가 아래와 같이 순수 가상함수를 선언했다는 것은,
    // "나는 이 가상함수를 어떻게 구현해야 할 지 모르겠으니 그냥 비워두겠다. 
    // 그러나, 이 클래스를 상속받는 자식클래스에서는 반드시 override 해서 구현하라!" 이런 의미로 선언했다고 보면 됨!
    virtual void speak() const = 0;
};

// 물론, 아래와 같이 클래스 namespace 바깥에서
// 순수 가상함수의 구현부를 직접 정의하는 것도 가능하기는 함! 
// -> 그러나, 아래 구현부는 사실상 호출이 불가능하므로, 쓸모가 없는 것이나 마찬가지임!
// 왜 호출이 불가능할까? 애초에 순수 가상함수가 하나라도 포함된 "추상 클래스"는 인스턴스 생성이 불가능함!
// 따라서, 그 인스턴스를 통한 가상함수 호출 자체가 막혀버리는 셈!
//void Animal::speak() const
//{
//    cout << m_name << " ??? " << endl;
//}

// 부모 클래스 Animal 을 상속받는 자식 클래스들
class Cat : public Animal
{
public:
    Cat(string name)
        : Animal(name)
    {}

    void speak() const
    {
        cout << m_name << " Meow " << endl;
    }
};

class Cow : public Animal
{
public:
    Cow(string name)
        : Animal(name)
    {}

    // 자식클래스에서 순수 가상함수를 override 하지 않는다면? -> 컴파일 에러 발생!

    // 컴파일 에러 해결을 위해 순수 가상함수 speak() override
    virtual void speak() const
    {
        cout << m_name << " Moooo " << endl;
    }
};


/* 인터페이스 클래스 */
/*
    인터페이스 클래스란,

    클래스 내부에 선언한 멤버함수들이
    "모두 순수 가상함수일 때"

    해당 클래스를 "인터페이스 클래스" 라고 함!

    즉, 자기가 실제로 뭘 할 지는 아무것도 정의하지 않고 있고,
    "이 클래스를 상속받는 자식클래스들은 ~~ 를 반드시 구현해야 한다"
    는 '인터페이스, 명세'만 갖고 있는 구조!

    참고로, 인터페이스 클래스 이름을 지을 때에는,
    맨 앞에 'I' 를 반드시 붙여주는 convention 을 지켜줄 것!
*/
class IErrorLog
{
public:
    // 순수 가상함수
    virtual bool reportError(const char* errorMessage) = 0;

    // 가상 소멸자
    virtual ~IErrorLog() {}
};

/* 인터페이스 클래스를 상속받은 자식클래스 */
class FileErrorLog : public IErrorLog
{
public:
    // 인터페이스 클래스의 순수 가상함수 override
    bool reportError(const char* errorMessage) override
    {
        cout << "Writing error to a file" << endl;
        return true;
    }
};

class ConsoleErrorLog : public IErrorLog
{
public:
    // 인터페이스 클래스의 순수 가상함수 override
    bool reportError(const char* errorMessage) override
    {
        cout << "Printing error to a console" << endl;
        return true;
    }
};

/*
    매개변수가 IErrorLog 라는 인터페이스 클래스 타입의
    참조변수로 정의되어 있음.

    그런데, IErrorLog 에는
    reportError() 라는 '순수 가상함수만' 구현되어 있어서,
    실제로 무슨 작업을 해야 하는지 구현되어 있지는 않는 상태임!

    그럼에도 불구하고,
    IErrorLog 를 상속받는 자식 클래스들인
    FileErrorLog, ConsoleErrorLog 타입의 인스턴스들을
    매개변수로 입력받을 수 있고,

    그들이 override 한
    reportError() 함수를 출력할 수 있도록 해주기 때문에
    여러 자식클래스들의 '인터페이스로써의 역할'을 충실히 하고 있음!
*/
void doSomething(IErrorLog& log)
{
    log.reportError("Runtime error!!");
}

int main()
{
    /*
        순수 가상함수가 하나 이상 포함된 클래스를
        '추상 클래스(Abstract Class)' 라고 함!

        이러한 추상 클래스는
        "인스턴스를 생성하는 게 불가능" 하다!!
    */
    //Animal ani("Hi");

    // 순수 가상함수를 override 하지 않은 자식클래스의 인스턴스를 생성하려고 하면,
    // "pure virtual function "Animal::speak" has no overrider" 라고 뜸!
    // 즉, 순수 가상함수는 자식클래스에서 반드시 override 해줘야 한다는 뜻!
    Cow cow("hello");
    cow.speak();


    /* 인터페이스 클래스가 필요한 이유 */

    FileErrorLog file_log;
    ConsoleErrorLog console_log;

    doSomething(file_log);
    doSomething(console_log);

    return 0;
}