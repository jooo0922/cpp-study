#include <iostream>

using namespace std;

int main()
{
    //const int num_students = 5;

    // 단순무식하게 점수 평균을 계산하는 방식
    /*int score0 = 84;
    int score1 = 92;
    int score2 = 76;
    int score3 = 81;
    int score4 = 56;

    int total_score = score0 + score1 + score2 + score3 + score4;*/

    // 배열과 반복문으로 점수 평균 계산하기
    //int scores[num_students] = { 84, 92, 76, 81, 56 };
    int scores[] = { 84, 92, 76, 81, 56 };

    const int num_students = sizeof(scores) / sizeof(int); // 이런 식으로, 초기화된 배열로부터 거꾸로 배열의 크기를 역계산할 수 있음

    int max_score = 0; // 최고점을 저장할 변수
    int min_score = 100; // 최저점을 저장할 변수 (만점(100)으로 초기화함)
    int total_score = 0;

    for (int i = 0; i < num_students; ++i)
    {
        total_score += scores[i];

        //max_score = (max_score < scores[i]) ? scores[i] : max_score; // 반복문을 돌면서 현재까지의 최고점과 각 배열 요소를 비교하며 최고점 갱신
        if (max_score < scores[i]) max_score = scores[i]; // if 문으로도 표현 가능
        if (min_score > scores[i]) min_score = scores[i];
    }

    double avg_score = static_cast<double>(total_score) / num_students;
    // Note: double(total_score) / num_students != double(total_score / num_students)
    /*
        평균값 계산 시, 
        나눗셈 후 double 로 캐스팅하는 것과,
        나눗셈 전 double 로 총합만 캐스팅하는 것은 결과값이 다를 수 있음!

        나눗셈 후 double 로 캐스팅하면,
        결과값이 정수로 딱 떨어지지 않을 경우,
        소수 부분이 유실되어 정확하지 않은 값으로 계산될 수 있음!
    */

    cout << max_score << endl; // 최고점 출력
    cout << min_score << endl; // 최저점 출력

    return 0;
}
