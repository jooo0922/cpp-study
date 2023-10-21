#include <iostream>

using namespace std;

// 분수를 나타내는 클래스
class Fraction
{
private:
    int m_numerator; // 분자
    int m_denominator; // 분모

public:
    void print()
    {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};

int main()
{
    return 0;
}