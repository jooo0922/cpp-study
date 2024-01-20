#include <iostream>

int getResult()
{
    return 100 * 100;
}

int main()
{
    // 아래에서 int x 는 L-value, 5 같은 리터럴 값이나 표현식을 R-value 라고 했었지?
    int x = 5;
    int y = getResult();

    const int cx = 6;
    const int cy = getResult();

    // L-value reference

    int& lr1 = x; // 변수 x 에 대한 참조변수 -> lr1 과 x 는 같은 주소값을 갖고 있으며, 상호 간 값 수정이 가능함. (Modifiable l-values)
    //int& lr2 = cx; // 참조변수 자신이 const 가 아니라면, const 변수는 할당할 수 없음. (Non-modifiable l-values)
    //int& lr3 = 5; // 참조변수에는 메모리를 갖는 변수만 할당 가능. 리터럴이나 표현식을 할당할 수 없음. 즉, R-value 는 할당 불가.

    // 아래 L-value reference 들은 모두 문법적으로 컴파일이 가능함!
    const int& lr4 = x; // Modifiable l-values
    const int& lr5 = cx; // Non-modifiable l-values
    const int& lr6 = 5; // R-values (어차피 상수 참조변수는 '심볼릭 상수'와 다름이 없으므로, 리터럴을 예외적으로 할당할 수 있음.)
    
    return 0;
}