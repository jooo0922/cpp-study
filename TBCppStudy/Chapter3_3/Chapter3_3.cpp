#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int main()
{   
    using namespace std;

    /*
        int x = 5;
        //int y = ++x; // 증가연산자. x = x + 1; (x 에 1이 더해진 값, 즉 6이 들어감).
        int y = --x; // 감소연산자. x = x - 1; (x 에 1을 뺀 값, 즉 4이 들어감).
        int z = x--; // 증감연산자는 피연산자 앞 또는 뒤에 붙는지에 따라 계산 순서가 다름.

        cout << y << endl;
        cout << z << endl;
    */

    
    /*
        증감연산자가 피연산자 앞에 붙은 경우
        x, y 에 1을 더하거나 빼준 후, 콘솔 출력

        증감연산자가 피연산자 뒤에 붙은 경우
        cout 에 x, y 를 먼저 보낸 뒤에, x, y 에 증감 연산 적용 

        int x = 6, y = 6;
        cout << x << " " << y << endl; // 6 6
        cout << ++x << " " << --y << endl; // 7 5
        cout << x << " " << y << endl; // 7 5
        cout << x++ << " " << y-- << endl; // 7 5 > ??? 왜 7 5 가 그대로 나올까?
        cout << x << " " << y << endl; // 8 4 > ??? 왜 이제서야 증감이 적용되었을까?
    */

    int x = 1;
    int v = add(x, ++x); // Do not use > 증감연산자를 이렇게 사용하면 컴파일러마다 작동 결과가 다르다고 함.

    cout << v << endl; // 4 > ??? 3이 나와야 할 것 같은데...? > 증감연산자의 부작용.

    int y = 1;
    y = y++;

    cout << y << endl; // 이 방식도 컴파일러마다 작동 결과가 다름. 이런 방식도 마찬가지로 Do not use!!

    return 0;
}