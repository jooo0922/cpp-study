#include <iostream>

// 클래스 템플릿 선언 
// 두 번째 template parameter 는 StaticArray 클래스의 배열 크기를 결정하는 non-type parameter
// 관련 내용 https://github.com/jooo0922/cpp-study/blob/main/TBCppChapter13/Chapter13_03/MyArray.h 참고
template<class T, int size>
class StaticArray
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
};

// 함수 템플릿 선언
// StaticArray 클래스에 저장된 정적 배열 출력해주는 함수
template <typename T, int size>
void print(StaticArray<T, size>& array)
{
    for (int count = 0; count < size; count++)
    {
        cout << array[count] << ' ';
    }
    cout << endl;
}

int main()
{
    return 0;
}