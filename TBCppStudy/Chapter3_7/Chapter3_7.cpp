#include <iostream>

int main()
{
    using namespace std;

    /*
        십진수
        
        0
        1
        2
        3
        4
        5
        6
        7
        8
        9
        10 = 10^1 + 0
        11 = 10^1 + 1
        12
        13
        ...
        337 = 300 + 30 + 7 = 10^2 * 3 + 10^1 * 3 + 10^0 * 7


        이진수

        0
        1
        10 = 2^1 * 1 + 2^0 * 0 = 2
        11 = 2^1 * 1 + 2^0 * 1 = 3
        
        1
        11
       + 1
       ------
       100


       이진수 > 십진수
       
       7654 3210 (이진수의 자릿수)
       0101 1110 (1 byte = 8 bits)

       위 이진수를 십진수로 바꿔서 계산
       2^7*0 + 2^6*1 + 2^5*0 + 2^4*1 + 2^3*1 + 2^2*1 + 2^1*1 + 2^0*0
       = 128*0 + 64*1 + 32*0 + 16*1 + 8*1 + 4*1 + 2*1 + 1*0
       = 0 + 64 + 0 + 16 + 8 + 4 + 2 + 0
       = 94


       십진수 > 이진수
       148 (decimal to binary)

       148 / 2 = 74 r0 (r = remainder, 나머지)
       74 / 2 = 37  r0
       37 / 2 = 18  r1
       18 / 2 = 9   r0
       9 / 2 = 4    r1
       4 / 2 = 2    r0
       2 / 2 = 1    r0
       1 / 2 = 0    r1
       
       위의 나머지를 아래서부터 위에 순서대로 기입하면,
       148의 이진수가 나옴.

       1001 0100


       십진수 > 이진수 2번째 방법
       
       // 2의 제곱수들 중에서 148보다 작은 숫자를 찾기
       1 2 4 8 16 32 64 128 256 512 1024 ...
       
       148

       148 >= 128                   Yes -> 128 = 2^7, 8번째 자리가 1
       148 - 128 = 20, 20 >= 64     No -> 64 = 2^6, 7번째 자리가 0
                       20 >= 32     No -> 32 = 2^5, 6번째 자리가 0
                       20 >= 16     Yes -> 16 = 2^4, 5번째 자리가 1
       20 - 16 = 4,     4 >= 8       No -> 8 = 2^3, 4번째 자리가 0
                        4 >= 4      Yes -> 4 = 2^2, 3번째 자리가 1
       4 - 4 = 0,

       1001 0100


       이진수 간 덧셈
       
       11
       0110 (6 in decimal)
       0111 (7 in decimal)
       -------
       1101 (13 in decimal)


       음의 정수인 십진수 > 이진수

       -5
       
       0000 0101 (부호 생각하지 않고 숫자 5만 이진수로 바꾸기)
       1111 1010 (보수 complement 를 취한다. 즉, 0과 1을 뒤집는다.)
       1111 1011 (마지막에 1을 더하면, 이 값이 -5의 이진수이다.)

       위 이진수에서 맨 첫번째 자릿수는 숫자가 아닌 '부호'에 대한 표현이다.
       즉, 0이면 양수, 1이면 음수라는 의미.

       음의 정수를 이진수로 표현할 때, 마지막 자릿수에 1을 더하는 이유?
       
       0000 0000 (양의 0)
       1111 1111 (음의 0)
       
       -> 0을 표현하는 이진수가 2개가 생겨버리기 때문에,
       이를 하나로 통일하기 위해 음의 0 이진수 마지막 자릿수에 1을 더한다면?
       
       0000 0000 (다시 양의 0으로 돌아옴.)

       이런 식으로, 동일한 정수를 표현하는 이진수가 2개가 발생하는 상황을 막기 위해,
       음의 정수를 이진수로 표현할 때에는 마지막 자릿수에 1을 더해줘야 함.


       이진수 > 음의 정수인 십진수

       1001 1110 (signed int. 첫번째 자릿수가 1이면 음수지?)
       0110 0001 (보수를 취함.)
       0110 0010 (마지막 자릿수에 1을 더함) -> 98 (십진수로 변환)
       
       그런데, 처음 시작할 때 첫번째 자릿수가 1인 음의 이진수였지?
       따라서, -98 이 정답!


       // signed vs unsigned
       
       // 아래 이진수가 unsigned 라면, 첫번째 자릿수 1은 십진수 변환 시, 계산에 포함
       1001 1110 -> 2^7*1 + 2^4*1 + 2^3*1 + 2^2*1 + 2^1*1 = 128 + 16 + 8 + 4 + 2

       위에서 동일한 이진수를 signed 로 계산했을 때 -98이 나왔던 것과 결과가 다르지? 

       따라서, 
       signed 와 unsigned 는 
       첫번째 자릿수 포함여부로 인해 십진수 변환 시, 
       결과값 차이가 크게 남.


       // test
       - 0100 1101 > 십진수로 ? 77
       - 93 > 8 bits unsigned 정수로 ? 0101 1101
       - -93 > 8 bits signed 정수로 ? 1010 0011
       - 1010 0010 > unsigned 십진수로 ? 162
       - 1010 0010 > signed 십진수로 ? -94

    */
    return 0;
}
