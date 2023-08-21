#include <iostream>

using namespace std;

/*
    실제로 컴퓨터는 임의의 랜덤한 난수를 생성할 수 있는 능력이 없음.

    그래서 '실제' 랜덤 넘버가 아닌,
    가짜(모의, 유사, 의사, pseudo) 랜덤 넘버를 만들어 냄.

    아래 함수는 난수 생성 원리를 설명하는 코드일 뿐,
    실제 코딩할 때에는 random number 생성하는 라이브러리를 사용할 것임!
*/
unsigned int PRNG() // Pseudo Random Number Generator (모의 난수 생성기)의 약자
{
    // seed number 는 시작하는 숫자.
    static unsigned int seed = 5523; // seed number

    seed = 8253729 * seed + 2396403;

    return seed % 32768;
}

int main()
{
    for (int count = 0; count <= 100; ++count)
    {
        cout << PRNG() << "\t";

        if (count % 5 == 0) cout << endl;
    }

    return 0;
}