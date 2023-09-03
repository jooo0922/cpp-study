#include <iostream>

using namespace std;

int main()
{
    int one_student_score; // 1 variable
    int student_scores[5]; // 5 int > 5개의 int 만큼의 메모리를 한꺼번에 할당한다 > 이걸 c++ 에서 '배열'이라고 함.

    //cout << sizeof(one_student_score) << endl; // 4 bytes
    //cout << sizeof(student_scores) << endl; // 20 bytes (4 bytes * 5) > 연속적으로 붙어있는 메모리 공간을 한꺼번에 빌려온 것!

    one_student_score = 100; // 일반적인 정수형 변수 초기화 방식

    student_scores[0] = 100; // 1st element. students_scores 메모리 공간 안에서 맨 첫번째 요소에 접근할 때(즉, 배열의 0번째 요소) 인덱스를 0으로 지정하여 접근할 수 있음!
    student_scores[1] = 80; // 2nd element
    student_scores[2] = 90; // 3rd element
    student_scores[3] = 50; // 4th element
    student_scores[4] = 0; // 5th element
    //student_scores[5] = 30; // 6th element > 인덱스가 0부터 시작하므로, student_scores[5] 는 6번째 요소를 의미하고, 배열 개수가 5개로 선언되어 있으므로, 6번째 요소에는 접근할 수 없다!

    cout << student_scores[0] << endl;
    cout << student_scores[1] << endl;
    cout << student_scores[2] << endl;
    cout << student_scores[3] << endl;
    cout << student_scores[4] << endl;
    //cout << student_scores[5] << endl; // 콘솔에 값이 나오긴 하지만, 런타임 에러 발생!
    // 즉, 예약하지 않은 6번째 메모리 공간이 빈 공간이라 사용하는 데에는 문제가 없지만, 운영체제가 런타임 에러를 쏟는 이유는
    // "왜 5개의 메모리 공간만 예약했으면서 6번째 공간까지 쓰려고 하느냐?"면서 화를 내는 거라고 보면 됨.

    // 배열의 각 요소를 변수처럼 사용할 수 있어, 연산자를 사용해 두 요소의 평균을 구하는 것도 가능함.
    cout << (student_scores[0] + student_scores[1]) / 2.0 << endl;

    return 0;
}
