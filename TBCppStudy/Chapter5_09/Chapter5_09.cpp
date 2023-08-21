#include <iostream>
#include <cstdlib> // std::rand(), std::srand() 등의 랜덤값 생성 함수 사용 가능
#include <ctime> // std::time() 시간 관련 함수 사용
#include <random> // c++ 11 부터 들어온 랜덤 라이브러리

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
    // 정적변수로 선언되어 있으므로, 함수 최초 실행 시에만 메모리 할당 및 값이 대입되고,
    // 그 이후 실행에서는 기존 seed 변수가 할당되어 있는 Data(데이터) 메모리 레이아웃(정적변수와 전역변수 저장하는 곳)을 찾아가서 값을 참조함.
    static unsigned int seed = 5523; // seed number

    seed = 8253729 * seed + 2396403; // seed 와는 최대한 먼 숫자를 다시 만들어 냄.

    return seed % 32768; // 나머지 연산자로 랜덤값의 범위 조정 > 최대 32768 까지 나올 것임.
}

// 일정 범위 내의 랜덤값 반환 함수
int getRandomNumber(int min, int max)
{
    // std::rand() 의 반환값에 최댓값을 나눗셈하고 싶은데, 나눗셈 연산은 비용이 많이 들기 때문에
    // 값을 반환할 때마다 나눗셈하기 보다, 정적변수에 역수로 취해서 만들어놓고, 
    // 실제 값을 반환할 때에는 비용이 적은 곱셈 연산 (* fraction) 으로 처리한 것!
    // 결론적으로, std::rand() 는 0 ~ RAND_MAX 사이의 값을 반환하므로, 
    // 0 ~ RAND_MAX / RAND_MAX + 1.0 = 0 ~ 0.999... 사이의 값이 나오겠지
    static const double fraction = 1.0 / (RAND_MAX + 1.0); // 참고로 RAND_MAX 는 std::rand() 함수가 반환할 수 있는 최대 랜덤값을 매크로로 정의해둔 것!

    // 최솟값 + static_cast<int>((최댓값 ~ 최솟값 사이의 간격 + 1) * (0 ~ 0.9999...)) 을 계산한 값을 더해준 것이므로,
    // 예를 들어, 최솟값이 5, 최댓값이 8로 들어온다면,
    // 5 + static_cast<int>((3 + 1) * (0 ~ 0.999...)),
    // 5 + static_cast<int>(4 * (0 ~ 0.999...)),
    // 5 + static_cast<int>((0 ~ 3.999...)),
    // 5 + (0 ~ 3), > static_cast 는 소수형을 정수형으로 캐스팅 시, 소수점 이하를 버림함.
    // 5 ~ 8 사이의 값이 나오겠군! > 3.9999... 까지 계산해서 캐스팅한 것은, 최댓값 8이 나올 확률을 그보다 작은 수가 나올 확률과 비슷하게 맞추기 위함이겠지!
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main()
{
    // 고정된 seed 넘버의 값이 동일하다면 생성되는 모의 랜덤값은 모두 동일하다!
    // 그러나, 고정된 seed 넘버가 무조건 나쁜 건 아니고, 디버깅 할 때는 문제 현상 재현을 위해 일부러 고정 seed 를 사용하는 경우가 있음!
    //std::srand(5323); // PRNG() 함수에서 보이는 것처럼 seed 정적변수에 들어갈 값을 설정해주는 함수

    // 그렇다면, seed 넘버의 값도 계속 바꿔준다면 더 랜덤같은 값을 얻을 수 있지 않을까?
    // 그래서 seed 넘버로 ctime() (시간값)을 사용함.
    // std::time() 은 cpu clock 으로 측정한 시간값을 반환함. 그래서 시간값 time_t 타입을 unsigned int 타입의 seed값으로 형변환함.
    // 참고로, static_cast 는 컴파일러에게 기본 타입 간 변환에 문제가 없는지 체크를 먼저 해달라고 요청하는 형변환 함수이며, 캐스팅 문법 중 가장 최신 문법이고 많이 사용하는 방법!
    // Chapter2_7, Chapter4_5 참고
    //std::srand(static_cast<unsigned int>(std::time(0)));

    //for (int count = 1; count <= 100; ++count)
    //{
    //    //cout << PRNG() << "\t"; // 각 난수 사이는 탭으로 띄워줌.
    //    //cout << std::rand() << "\t"; // srand() 로 설정한 seed 값을 기반으로 랜덤값을 생성하는 함수

    //    cout << getRandomNumber(5, 8) << "\t"; // 5 ~ 8 사이의 랜덤값 출력

    //    if (count % 5 == 0) cout << endl; // 5개의 난수가 출력되면 줄바꿈.
    //}

    // random 라이브러리 사용법
    std::random_device rd; // 랜덤값을 진짜 랜덤처럼 만들려고 std::time() 쓴 것과 유사한 기능
    
    // 랜덤값 생성 알고리즘 mt19937 은 32 bits 난수 생성기, mt19937_64 는 64 bits 난수 생성기 
    // random device 를 인자로 넘겨서 seed 가 고정되지 않도록 해줌. > std::time() 으로 seed 값을 계속 바꿔주던 것과 유사함.
    // mersenne twister 는 한마디로 mersenne 랜덤값 생성기의 seed값을 random_device 로 꼬아줬다(twister)는 의미!
    std::mt19937_64 mersenne(rd()); // create a mersenne twister. (mresenne 는 랜덤값 생성 알고리즘을 발명한 수학자 이름. 그냥 임의로 지은 변수명)

    // 1 ~ 6 중 하나가 선택이 되는데, 
    // uniform_int_distribution 는 1, 2, 3, 4, 5, 6 이 나올 확률을 모두 동일하게 맞춘 것! > 랜덤 생성기 mersenne 가 따를 분포를 만듦.
    std::uniform_int_distribution<> dice(1, 6);

    for (int count = 1; count <= 20; ++count)
    {
        cout << dice(mersenne) << endl;
    }

    return 0;
}