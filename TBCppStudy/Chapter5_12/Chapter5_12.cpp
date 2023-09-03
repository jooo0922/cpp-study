#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

enum StudentName
{
    JACKJACK,       // = 0
    DASH,           // = 1
    VIOLET,         // = 2
    NUM_STUDENTS,   // = 3
};

int main()
{
    //int one_student_score; // 1 variable
    //int student_scores[5]; // 5 int > 5개의 int 만큼의 메모리를 한꺼번에 할당한다 > 이걸 c++ 에서 '배열'이라고 함.

    ////cout << sizeof(one_student_score) << endl; // 4 bytes
    ////cout << sizeof(student_scores) << endl; // 20 bytes (4 bytes * 5) > 연속적으로 붙어있는 메모리 공간을 한꺼번에 빌려온 것!

    //one_student_score = 100; // 일반적인 정수형 변수 초기화 방식

    //student_scores[0] = 100; // 1st element. students_scores 메모리 공간 안에서 맨 첫번째 요소에 접근할 때(즉, 배열의 0번째 요소) 인덱스를 0으로 지정하여 접근할 수 있음!
    //student_scores[1] = 80; // 2nd element
    //student_scores[2] = 90; // 3rd element
    //student_scores[3] = 50; // 4th element
    //student_scores[4] = 0; // 5th element
    ////student_scores[5] = 30; // 6th element > 인덱스가 0부터 시작하므로, student_scores[5] 는 6번째 요소를 의미하고, 배열 개수가 5개로 선언되어 있으므로, 6번째 요소에는 접근할 수 없다!

    //cout << student_scores[0] << endl;
    //cout << student_scores[1] << endl;
    //cout << student_scores[2] << endl;
    //cout << student_scores[3] << endl;
    //cout << student_scores[4] << endl;
    ////cout << student_scores[5] << endl; // 콘솔에 값이 나오긴 하지만, 런타임 에러 발생!
    //// 즉, 예약하지 않은 6번째 메모리 공간이 빈 공간이라 사용하는 데에는 문제가 없지만, 운영체제가 런타임 에러를 쏟는 이유는
    //// "왜 5개의 메모리 공간만 예약했으면서 6번째 공간까지 쓰려고 하느냐?"면서 화를 내는 거라고 보면 됨.

    //// 배열의 각 요소를 변수처럼 사용할 수 있어, 연산자를 사용해 두 요소의 평균을 구하는 것도 가능함.
    //cout << (student_scores[0] + student_scores[1]) / 2.0 << endl;


    // 구조체를 배열로 선언하기
    //cout << sizeof(Rectangle) << endl; // 8 bytes

    //Rectangle rect_arr[10]; // 8 bytes 짜리 구조체 Rectangle 10 개를 집어넣을 수 있는 메모리 공간을 예약함. > 구조체 배열!

    //cout << sizeof(rect_arr) << endl; // 80 bytes

    //// 구조체 배열의 요소에 접근해서 멤버변수 값 초기화하기
    //rect_arr[0].length = 1;
    //rect_arr[0].width = 2;


    // 배열 초기화 방법
    //int my_array[5] = { 1, 2, 3, 4, 5 }; // 5개의 int 만큼의 메모리 공간을 예약한 배열에 5개의 int 값으로 초기화
    //int my_array[5] = { 1, 2 }; // 5개의 int 만큼의 메모리 공간을 예약한 배열에 2개의 int 값으로 초기화 > 나머지 3개는 0으로 자동 초기화시킴.
    //int my_array[] = { 1, 2, 3, 4, 5 }; // 메모리 공간의 개수를 선언하지 않은 배열에 5개의 int 값으로 초기화 > 컴파일러가 알아서 초기화된 5개 int 개수에 맞춰 5개의 메모리 공간을 자동으로 할당해 줌.
    //int my_array[]{ 1, 2, 3, 4, 5 }; // c++ 11 부터는 대입 연산자 없이도 초기화 가능. > 마치 변수를 uniform initialization 하는 것처럼 초기화 가능.

    //cout << my_array[0] << endl;
    //cout << my_array[1] << endl;
    //cout << my_array[2] << endl;
    //cout << my_array[3] << endl;
    //cout << my_array[4] << endl;

    // enum 의 값을 배열 index 로 사용하는 것도 가능
    //cout << my_array[JACKJACK] << endl;
    //cout << my_array[DASH] << endl;
    //cout << my_array[VIOLET] << endl;


    // Enum 과 배열을 연동해서 사용하기
    //int students_scores[NUM_STUDENTS]; // 마지막 enum 요소르 배열 개수를 초기화할 수 있음. > enum 개수와 딱 맞게 배열 메모리 공간을 할당할 수 있음.

    //students_scores[JACKJACK] = 0;
    //students_scores[DASH] = 100;


    // 배열의 크기는 항상 '컴파일 타임'에 선언되어야 함!
    //int num_students = 0;
    //cin >> num_students;

    // 만약에, int 타입 변수로 배열의 크기를 할당하고자 한다면,
    // 그 변수는 반드시 const, 즉 상수 변수로 선언해줘야 함.
    // 왜냐하면, const 가 아닌 변수는 런타임에 언제든지 값이 바뀔 수 있기 때문에,
    // '컴파일 타임'에 크기가 선언되어야 하는 배열의 특성 상, 값이 변경되지 않음을 보장할 수 있는 const 변수로만 배열의 크기를 선언할 수 있음!
    const int num_students = 5;

    // cin 으로 입력된 값을 배열 개수로 선언하고자 한다면,
    // 런타임에 입력된 값으로 배열 개수를 선언하려고 한다는 뜻이기 때문에,
    // 컴파일러가 에러를 발생시킴 > 배열의 크기(개수)는 반드시 '컴파일 타임'에서 미리 결정되어 있어야 함.
    int students_scores[num_students];


    return 0;
}
