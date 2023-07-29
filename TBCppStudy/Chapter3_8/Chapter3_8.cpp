#include <iostream>
#include <bitset> // 비트 단위 연산자는 이진수 계산을 주로 하기 때문에, 이진수로 바꿔서 출력해주는 라이브러리를 사용하면 편함.

int main()
{
    using namespace std;

    // 비트 단위 연산자 (bitwise operator) (6가지)
    // <<   leftshift
    // >>   rightshift
    // ~    not
    // &    and
    // |    or
    // ^    xor
    /*
        <<, >> 등 cout, cin 등에서 사용하는 것과 연산자가 동일하지?

        이거는 iostream 라이브러리 안에서 해당 연산자는 비트 단위 연산자가 아닌, 
        cout, cin 에 필요한 기능으로 정의하도록 덮어써 줌.

        이러한 개념을 '연산자 오버로딩' 이라고 함.
    */

    unsigned int a = 3;

    // int 타입은 4 byte(32 bits) 이지만, 
    // 굳이 32 비트를 다 출력할 필요가 없으니,  
    // 정수 a 를 8 bits 이진수로 표현해서 출력
    cout << std::bitset<8>(a) << endl; // 00000011

    // 가장 많이 사용하는 shift 연산자
    // 비트 단위 연산자는 unsigned(부호x) 를 기준으로 사용함.
    // 0000 0011 에서 각 bit 단위 숫자를 왼쪽으로 n 칸씩 shift(이동) 후, 비어있는 자릿수는 0으로 채움
    // shift 된 이진수들을 십진수로 나타내면, n 칸씩 왼쪽으로 shift 할 경우, 십진수에 2^n 제곱만큼 곱해주는 규칙성 발견!
    // 그래서 unsigned 정수에 2^n 제곱을 곱해줘야 할 경우, pow() 같은 걸 사용하기 보다, shift 를 사용하는 게 훨씬 빠르다!
    cout << std::bitset<8>(a << 1) << " " << (a << 1) << endl; // 00000110 6
    cout << std::bitset<8>(a << 2) << " " << (a << 2) << endl; // 00001100 12
    cout << std::bitset<8>(a << 3) << " " << (a << 3) << endl; // 00011000 24
    cout << std::bitset<8>(a << 4) << " " << (a << 4) << endl; // 00110000 48

    // 이번엔 rightshift 를 연습해보자
    unsigned int b = 1024;

    cout << std::bitset<16>(b) << endl; // 0000010000000000 = 2^10
    
    // 이번에도 n 칸씩 오른쪽으로 shift 할 경우, 십진수에 1 / 2^n 제곱만큼 나눠주는 규칙성 발견!
    cout << std::bitset<16>(b >> 1) << " " << (b >> 1) << endl; // 0000001000000000 512
    cout << std::bitset<16>(b >> 2) << " " << (b >> 2) << endl; // 0000000100000000 256
    cout << std::bitset<16>(b >> 3) << " " << (b >> 3) << endl; // 0000000010000000 128
    cout << std::bitset<16>(b >> 4) << " " << (b >> 4) << endl; // 0000000001000000 64

    // bitwise not
    // 이진수의 0과 1이 뒤집어져서 보수를 취하게 됨.
    cout << std::bitset<16>(~b) << " " << (~b) << endl; // 1111110111111111 4294966271

    unsigned int c = 0b1100; // 이진수 직접 표현 시, 이진수 앞에 0b 를 붙임.
    unsigned int d = 0b0110;

    cout << c << " " << d << endl; // 12 6


    // bitwise and, or, xor
    cout << std::bitset<4>(c & d) << endl; // bitwise AND (각 이진수의 동일한 자릿수끼리 모두 1일 때 1, 아니면 0)
    cout << std::bitset<4>(c | d) << endl; // bitwise OR (각 이진수의 동일한 자릿수끼리 둘 중 하나만 1이여도 1, 아니면 0)
    cout << std::bitset<4>(c ^ d) << endl; // bitwise XOR (각 이진수의 동일한 자릿수끼리 둘 중 하나만 1이면 1, 둘 다 1이거나 둘 다 0이면 0 -> 즉, 다르면 1, 같으면 0)

    a &= b; // assignment operator 와 결합된 형태로도 사용 가능

    // Quiz
    // 0110 >> 2 -> decimal ? 1
    // 5 | 12 -> decimal ? 13
    // 5 & 12 -> decimal ? 4
    // 5 ^ 12 -> decimal ? 9

    // 1번 문제 풀이
    unsigned int bit = 0b0110;
    cout << std::bitset<8>(bit >> 2) << " " << (bit >> 2) << endl;

    int intA = 5;
    int intB = 12;
    cout << "IntA : " << std::bitset<8>(intA) << endl;
    cout << "IntB : " << std::bitset<8>(intB) << endl;

    // 2번 문제 풀이
    cout << std::bitset<8>(intA | intB) << " " << (intA | intB) << endl;
    
    // 3번 문제 풀이
    cout << std::bitset<8>(intA & intB) << " " << (intA & intB) << endl;
    
    // 4번 문제 풀이
    cout << std::bitset<8>(intA ^ intB) << " " << (intA ^ intB) << endl;


    return 0;
}