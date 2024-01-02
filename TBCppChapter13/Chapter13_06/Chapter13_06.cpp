#include <iostream>

using namespace std;

// 클래스 템플릿 선언 
// 두 번째 template parameter 는 StaticArray 클래스의 배열 크기를 결정하는 non-type parameter
// 관련 내용 https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter13/Chapter13_03/MyArray.h 참고
template<class T, int size>
class StaticArray_BASE
{
private:
    T m_array[size];

public:
    // getter
    T* getArray() { return m_array; }

    // [] 연산자 오버로딩
    T& operator[](int index)
    {
        return m_array[index];
    }

    // StaticArray 클래스에 저장된 정적 배열 출력해주는 함수 템플릿 -> 멤버함수로 편입
    void printArray()
    {
        for (int count = 0; count < size; count++)
        {
            // 현재 클래스로부터 생성된 인스턴스를 가리키는 포인터 변수 this 를 de-referencing 하여
            // 현재 클래스의 [] 연산자 오버로딩을 사용해 정적배열의 요소를 출력하려는 것!
            cout << (*this)[count] << ' ';
        }
        cout << endl;
    }
};

/*
    char 타입에 대해서만 예외적으로
    ' ' 띄어쓰기 출력을 생략하도록 template specialization 해보자!

    이때, printArray 함수 템플릿은
    template parameter 가 2개 잖아?
    그 중에서 typename T 에 대해서만 specialization 하고 싶은 거니까,
    
    아래와 같이 '템플릿을 부분적으로 특수화' 해줘야 함!

    이럴 경우,
    특수화하지 않을 template parameter 는 그대로 남겨두면 됨!
*/
//template <int size>
//void printArray(StaticArray<char, size>& array)
//{
//    for (int count = 0; count < size; count++)
//    {
//        // char 타입에 한해서는 띄어쓰기 출력을 생략하도록 템플릿 특수화 구현
//        cout << array[count];
//    }
//    cout << endl;
//}

/*
    함수 템플릿을 클래스의 멤버함수로 편입한 것 까지는 좋다.

    그런데, '멤버함수의 템플릿 특수화'가 생각보다 까다롭다!

    그래서 기존 char 타입에 대한 함수 템플릿 특수화를
    멤버함수에서도 유지할 수 있도록 하려면, 좀 더 쉬운 방법을 생각해야 함.

    그것이 바로 '상속'을
    사용하는 방법!

    상속을 사용하는 이유는, 템플릿을 통째로 specialization 하는 것보다는,
    상속을 활용하는 방법이 훨씬 편하기 때문임!

    -> why? 직접 템플릿을 통째로 specialization 하면, 
    해당 클래스의 다른 부분들도 중복해서 구현해야 하기 때문에
    코드의 양이 많아지고 번거로운 작업을 해줘야 함.

    아래 과정을 따르면 
    상속을 활용한 멤버함수 템플릿 특수화를 구현할 수 있음
*/
// 1. 우선, 기존 클래스 이름에 _BASE 라는 접미어를 붙여서 부모 클래스로 만들어두고, 
// 기존 클래스 이름으로 자식 클래스를 선언한다.
template<class T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{};

// 2. 그 다음, 선언된 자식 클래스에 대해서
// char 타입에 대해 template specialization 을 다시 선언한다
template<int size>
class StaticArray<char, size> : public StaticArray_BASE<char, size>
{
public:
    // 3. template specialization 된 자식 클래스에
    // 특수화하고 싶은 멤버함수를 override 한다!
    // template specialization 된 자식 클래스는 부모 클래스로부터 '상속'을 받았기 때문에,
    // [] 연산자 오버로딩, getter 함수 등 특수화하지 않아도 되는 기존 함수들을 
    // 번거롭게 중복해서 specialization 에 다시 구현할 필요가 없어서 훨씬 편함!
    void printArray()
    {
        for (int count = 0; count < size; count++)
        {
            // 현재 클래스로부터 생성된 인스턴스를 가리키는 포인터 변수 this 를 de-referencing 하여
            // 현재 클래스의 [] 연산자 오버로딩을 사용해 정적배열의 요소를 출력하려는 것!
            cout << (*this)[count];
        }
        cout << endl;
    }
};


int main()
{
    StaticArray<int, 4> int4;
    int4[0] = 1;
    int4[1] = 2;
    int4[2] = 3;
    int4[3] = 4;

    int4.printArray();

    StaticArray<char, 14> char14;

    // int4 처럼 일일이 문자열의 각 요소를 [] 오버로딩으로 set 하기 귀찮아서 
    // strcpy_s() 함수로 문자열 복사 처리함.
    strcpy_s(char14.getArray(), 14, "Hello, World");
    
    // printArray 함수 템플릿에서, char 타입에 대해서만 예외적으로
    // ' ' 띄어쓰기 출력을 생략하도록 template specialization 할 수는 없을까? 
    char14.printArray();
    
    return 0;
}