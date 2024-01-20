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
    
    return 0;
}