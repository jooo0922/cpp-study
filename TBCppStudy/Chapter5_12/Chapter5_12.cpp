#include <iostream>

using namespace std;

//struct Rectangle
//{
//    int length;
//    int width;
//};

//enum StudentName
//{
//    JACKJACK,       // = 0
//    DASH,           // = 1
//    VIOLET,         // = 2
//    NUM_STUDENTS,   // = 3
//};

void doSomething(int students_scores[]) // 그래서 배열을 인자로 받는 매개변수를 선언할 때에는, 실제 배열 크기와 상관없이 크기를 할당하지 않아도 됨. 어차피 내부적으로는 포인터 변수로 처리되어 버리니까 배열 개수가 중요한 게 아님!
{
    // 파라미터로 전달된 배열의 요소의 '값'은 동일하게 출력된 걸 확인함.
    //cout << students_scores[0] << endl;
    //cout << students_scores[1] << endl;
    //cout << students_scores[2] << endl;

    // 이번에는 파라미터로 전달된 배열 요소의 '메모리 공간 주소'를 출력해보자
    /*
        여기서 알 수 있는 아주아주 중요한 포인트!

        왜 함수의 파라미터로 전달받는 배열 매개변수 int students_scores[20] 만
        혼자서 메모리 주소값이 다를까?

        그 이유는, 이 함수에서 선언해놓은 매개변수가
        마치 배열의 모양새를 하고 있어서 배열처럼 보이지만,
        컴파일러는 내부적으로 이를 '새롭게 선언된 포인터 변수'로 처리하고 있음!!!

        뭐에 대한 포인터 변수냐?
        바로 함수의 파라미터로 전달받는 배열 (main 함수에서 선언한 int students_scores[20])의
        메모리 주소값을 담고있는 포인터 변수다!
        
        즉, 함수의 파라미터로 전달받는 배열 int students_scores[20] 의 
        메모리 공간을 가리키는 포인터 변수라는 뜻!

        그렇기에, 이 포인터 변수는 main 함수에서 선언한 int students_scores[20] 의
        메모리 주소를 '값'으로 갖고 있기는 하지만, 이것이 이 포인터 변수의 '메모리 주소'는 아닌 것이지!

        포인터 변수 자체의 메모리 주소는 이것과 별개로 따로 존재할테니까!

        그래서 이 포인터 변수가 '값'으로 갖고 있는 메모리 주소는 17956312,
        즉, main 함수에서 선언한 int students_scores[20] 의 메모리 주소이자,
        main 함수에서 선언한 int students_scores[20] 의 첫 번째 요소의 메모리 주소 (int)&(students_scores[0]) 와 같은 것임!

        그러나, 이 포인터 변수 자체에 할당된 '메모리 공간 주소'는 17956100 으로,
        main 함수에서 선언한 int students_scores[20] 와는 아예 관련이 없는 메모리 공간의 주소라는 것임!

        한 편, 이 포인터 변수를 통해 접근한
        배열의 첫번째 요소(&(students_scores[0]))는
        main 함수에서 출력해 본 배열의 첫 번째 요소와 메모리 주소가 일치함!

        오직, 매개변수로 선언한 int students_scores[20] 만이
        포인터 변수로써, 넘겨받은 배열과 전혀 무관한 메모리 공간에 저장되어 있음을 알 수 있음!
    */
    cout << (int)&students_scores << endl; // 17956100 > 엥? main 에서 출력한 배열 자체의 메모리 주소는 17956312(== 첫 번째 요소의 메모리 주소)와 같았는데 여기서는 왜 다르지???
    cout << (int)&(students_scores[0]) << endl; // 17956312 (+ 4 bytes)
    cout << (int)&(students_scores[1]) << endl; // 17956316 (+ 4 bytes)
    cout << (int)&(students_scores[2]) << endl; // 17956320 (+ 4 bytes)

    // 이게 또 웃긴 게, x86(32 bit) 로 빌드하느냐 x64(64 bit) 로 빌드하느냐에 따라 포인터 변수의 메모리 공간 크기가 다르게 출력됨.
    // 포인터 변수는 x86 으로 빌드된 프로그램에서 4 bytes 의 메모리 공간을 할당받지만,
    // x64 로 빌드된 프로그램에서는 8 bytes 메모리 공간을 할당받음!
    // 왜냐? x64 프로그램은 사용하는 메모리 공간이 더 많아지기 때문에, 메모리 공간의 주소를 표현할 때, 그 길이가 더 길어질 수 밖에 없기 때문에,
    // 메모리 주소를 담는 포인터 변수의 크기도 그만큼 더 커질 수밖에 없는 것!
    cout << "Size in doSomething " << sizeof(students_scores) << endl; // 4 bytes 출력 > 매개변수로 선언된 students_scores[20] 이 배열이 아닌 포인터 변수라는 또 다른 증거!
}

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
    const int num_students = 20;

    // cin 으로 입력된 값을 배열 개수로 선언하고자 한다면,
    // 런타임에 입력된 값으로 배열 개수를 선언하려고 한다는 뜻이기 때문에,
    // 컴파일러가 에러를 발생시킴 > 배열의 크기(개수)는 반드시 '컴파일 타임'에서 미리 결정되어 있어야 함.
    //int students_scores[num_students];

    // 메모리 공간 주소는 16진수로 출력되므로, 보기 편하도록 c-style casting 으로 10진수 정수형으로 변환해서 출력함.
    /*
        여기서 알 수 있는 중요한 포인트 두 가지!

        1. 배열 자체의 메모리 공간 주소를 찍으면,
        배열의 첫 번째 요소가 저장된 메모리 공간 주소와 일치한다!
        > 즉, 배열의 메모리 주소는 배열의 첫 번째 요소가 저장된 메모리 공간의 주소를 가리키는 것!

        2. int (4 bytes) 타입의 배열을 선언했기 때문에,
        한 요소씩 건너뛰어서 메모리 공간 주소를 확인할수록, 4 bytes 씩 증가된 십진수 메모리 주소가 출력된다!
        > 즉, 4 bytes 간격으로 연이어 붙어있는 메모리 공간을 예약하는구나!
    */
    //cout << (int)&students_scores << endl; // 배열 자체가 저장된 메모리 공간 주소 > 7797532
    //cout << (int)&(students_scores[0]) << endl; // 배열의 첫 번째 요소가 저장된 메모리 공간 주소 > 7797532 (배열 자체의 메모리 공간 주소와 일치!)
    //cout << (int)&(students_scores[1]) << endl; // 배열의 두 번째 요소가 저장된 메모리 공간 주소 > 7797536 (+ 4 bytes)
    //cout << (int)&(students_scores[2]) << endl; // 배열의 세 번째 요소가 저장된 메모리 공간 주소 > 7797540 (+ 4 bytes)
    //cout << (int)&(students_scores[3]) << endl; // 배열의 네 번째 요소가 저장된 메모리 공간 주소 > 7797544 (+ 4 bytes)

    //cout << sizeof(students_scores) << endl; // 80 bytes


    int students_scores[num_students] = { 1, 2, 3, 4, 5, }; // fixed size array(크기가 고정된 배열) 정의 및 초기화

    // 초기화된 배열 요소의 값 일부 출력
    //cout << students_scores[0] << endl;
    //cout << students_scores[1] << endl;
    //cout << students_scores[2] << endl;

    // 이번에는 배열 요소 일부의 메모리 공간 주소를 출력해보자
    // 여기서 출력한 메모리 주소는 이전에 확인했던 내용과 일치함.
    cout << (int)&students_scores << endl; // 17956312 (배열 변수 자체의 메모리 주소 == 배열의 첫 번째 요소 메모리 주소)
    cout << (int)&(students_scores[0]) << endl; // 17956312 (+ 4 bytes)
    cout << (int)&(students_scores[1]) << endl; // 17956316 (+ 4 bytes)
    cout << (int)&(students_scores[2]) << endl; // 17956320 (+ 4 bytes)

    cout << "Size in main " << sizeof(students_scores) << endl; // 배열의 크기 80 bytes 가 정상 출력.
    
    // 배열을 함수의 파라미터로 넘겨준 뒤, 내부에서 동일한 배열 요소의 값 일부 출력
    // > 일단 배열 요소의 값 자체는 동일하게 출력되는 것을 확인할 수 있었음.
    doSomething(students_scores);

    return 0;
}
