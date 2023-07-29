#include <iostream>

int getPrice(bool onSale)
{
    if (onSale)
        return 10;
    else
        return 100;
}

int main()
{
    using namespace std;

    /*
        sizeof() 
        
        어떠한 데이터형의 크기를 알고싶을 때 사용.
        특히, 사용자가 직접 만든 자료형인 class, struct 의 크기를 확인할 때에도 사용 가능! 

        참고로, sizeof() 는 함수가 아니라 '연산자'이다.
    */
    //float a;

    //cout << sizeof(float); // 4 (4 bytes)
    //cout << sizeof(a); // 4
    //cout << sizeof a; // 변수의 사이즈 확인 시, 괄호가 없어도 작동됨. > sizeof() 가 연산자라는 증거

    /*
        comma operator

        콤마 연산자는
        
        변수 = (계산식1, 계산식2)
        
        이렇게 되어있다고 가정하면,

        계산식 1을 먼저 계산하고,
        계산식 2를 그 다음 계산하고,
        계산식 2의 결과를 '변수'에 할당해 줌.
    */
    int x = 3;
    int y = 10;
    int z = (++x, ++y); // 콤마연산자는 ++x 먼저 계산하고, ++y 를 그 다음에 계산하고, y 값을 z 에 들어갈 수 있도록 해줌. 
    /*
        위 콤마연산자는 결국,

        ++x;
        ++y;
        int z = y;

        를 축약한 연산자!

        그래서 대부분 콤마 연산자를 사용하기보다는,
        위에 처럼 풀어서 쓰는 게 더 일반적임. 헷갈리니까!
        예외적으로, for문(반복문)에서는 콤마 연산자가 많이 사용된다고 함.
    */

    cout << x << " " << y << " " << z << endl;

    int a = 1, b = 10; // 여기서 사용된 콤마(,)는 콤마 연산자가 아니라, 두 변수 a, b 의 선언을 구분하는 구분 기호 역할!
    int w;
    
    w = a, b; // 1 > ??? 콤마연산자는 뒤에 계산식을 할당해준다더니, 그러면 10이 나와야 하는 게 아닌가?
    w = (++a, a + b); // 12 > 두 번째 계산식인 a + b 의 결과가 최종적으로 할당됨.

    cout << w << endl;
    /*
        콤마연산자(,) 는 대입연산자(=) 보다 연산 우선순위가 더 낮다!

        따라서, 
        위에 식처럼 콤마연산에 별도로 괄호를 묶어주지 않았다면,
        대입연산이 먼저 적용되어 w 에는 a, 즉 1이 먼저 들어가게 되는 것이다!

        즉, 
        (z = a), b; 이렇게 되는 셈!

        만약 뒤에 값을 할당하는 콤마 연산을 먼저 수행하고 싶다면,
        w = (a, b);
        이런 식으로 바꿔줘야 함!
    */

    /*
        conditional operator (조건 연산자)

        보통 '삼항 연산자' 라고도 함...!

        다른 이름으로는, arithmetric if 라고도 함.
        조건을 처리할 때 if 을 사용하지 않고 처리하는 방식이라는 의미.
    */
    bool onSale = true;

    // 일반적인 조건문 처리 방식
    /*
        int price;

        if (onSale)
        {
            price = 10;
        }
        else
        {
            price = 100;
        }
    */
    
    // 그런데 만약 이 price 변수를 const(심볼릭 상수)로 사용하고 싶다면
    // 조건문을 어떻게 작성해야 할까? > 이럴 때 유용한 것이 삼항연산자!
    // 단, 삼항연산자에 들어가는 조건문이나 표현식이 너무 복잡하면 가급적 사용하지 말고, if문으로 쪼개서 쓰는 게 더 가독성이 좋음.
    //const int price = (onSale == true) ? 10 : 100;
    const int price = getPrice(onSale); // 굳이 if 문으로 써야겠다면 조건문을 함수로 추출해서 사용할수도 있음.

    cout << price << endl;

    int c = 5;
    cout << ((c % 2 == 0) ? "even" : "odd") << endl; // "odd" 부분에 에러가 났던 이유? 스트림 연산자 << 와 삼항연산자의 우선순위가 충돌해서 > 괄호로 묶음처리!

    return 0;
}