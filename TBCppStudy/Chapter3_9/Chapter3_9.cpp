#include <iostream>
#include <bitset> // 비트 연산 시, 이진수로 바꿔서 출력해주는 라이브러리를 사용하면 편함.
#include "Chapter3_9.h"

using namespace std;

void ClickArticle(unsigned char& my_article_flags, unsigned char option_liked)
{
    if (my_article_flags & option_liked)
    {
        // 좋아요가 이미 클릭되어 있을 때
        my_article_flags &= ~option_liked;
        cout << "article liked again " << bitset<8>(my_article_flags) << endl;
    }
    else
    {
        // 좋아요가 클릭되어 있지 않을 때
        my_article_flags |= option_liked;
        cout << "article liked " << bitset<8>(my_article_flags) << endl;
    }
}

int main()
{

    bool item1_flag = false;
    bool item2_flag = false;
    bool item3_flag = false;
    bool item4_flag = false;
    // ...

    // event!
    item1_flag = true;

    // die! item2 lost
    item2_flag = false;

    if (item3_flag == true)
    {
        // event
    }

    if (item3_flag == true && item4_flag == false)
    {
        item3_flag = false;
        item4_flag = true;
    }

    // 특정 아이템 소유 여부에 따라 이벤트를 발생시키는 함수를 호출할 경우,
    // 아이템 개수 만큼 파라미터가 증가함.
    // invokeEvent(item1_flag, item2_flag, item3_flag, ...)

    // 위와 같은 방식으로 각 아이템마다 플래그 변수를 관리하면 코드가 복잡해지겠지?
    // 그런데, 만약 1 byte 짜리 변수에다가 아이템 플래그를 넣는다 하면, 
    // 1 byte 하나의 변수만 사용해도, 8 bits, 즉 8개의 on/off 플래그를 사용할 수 있는 셈이잖아?
    // 즉, 8개의 bool 타입을 사용하지 않고도, 1byte 짜리 1개의 char 타입으로 8개의 아이템 플래그를 표현할 수 있다는 것이지!
    // 이런 기법을 '비트 플래그' 라고 함!

    const unsigned char opt0 = 1 << 0;
    const unsigned char opt1 = 1 << 1;
    const unsigned char opt2 = 1 << 2;
    const unsigned char opt3 = 1 << 3;
    // opt4, 5, 6, 7, ...

    cout << bitset<8>(opt0) << endl; // 00000001
    cout << bitset<8>(opt1) << endl; // 00000010
    cout << bitset<8>(opt2) << endl; // 00000100
    cout << bitset<8>(opt3) << endl; // 00001000

    unsigned char items_flag = 0;
    cout << "No item " << bitset<8>(items_flag) << endl; // 00000000 > 비트가 모두 0, 즉 아이템이 하나도 없는 상태

    // item0 on
    items_flag |= opt0;
    cout << "Item0 obtained " << bitset<8>(items_flag) << endl; // 00000001 > opt0 을 사용해서 맨 오른쪽 비트(item0 flag)를 1로 덮어씀

    // item3 on
    items_flag |= opt3;
    cout << "Item3 obtained " << bitset<8>(items_flag) << endl; // |= (bitwise OR) 연산자로 덮어쓰기를 하므로, 이전에 opt0 으로 덮어썼던 걸 계속 유지하면서 opt3 을 추가로 덮어쓸 수 있음.

    // item3 lost
    items_flag &= ~opt3;
    cout << "Item3 lost " << bitset<8>(items_flag) << endl; // 켜줬던 플래그를 꺼주려면, &= (bitwise AND) 연산자로 opt3 의 보수(bitwise NOT(~)로 구함)를 덮어씀

    // has item1 ?
    if (items_flag & opt1)
    {
        // opt1 에서 1인 비트 자릿수에서 items_flag 가 1이면, true 를 반환함 > 플래그가 true 인지 검사할 수 있음.
        cout << "Has item1" << endl;
    }
    else
    {
        cout << "Not Have item1" << endl;
    }

    // has item0 ?
    if (items_flag & opt0){ cout << "Has item0" << endl; }

    // obtain item 2, 3
    items_flag |= (opt2 | opt3); // item 2,3 플래그를 동시에 on 하는 방법
    cout << bitset<8>(opt2 | opt3) << endl;
    cout << "Item2, 3 obtained " << bitset<8>(items_flag) << endl;

    if ((items_flag & opt2) && !(items_flag & opt1))
    {
        // 두 아이템의 상태를 바꿔주는 건 ^(bitwise XOR) 연산자를 사용
        // 왜냐하면, XOR 은 같으면 0, 다르면 1로 처리해주니까! 
        // -> 즉, opt 와 비교해서 아이템 상태가 다르면 1로, 상태가 같으면 0으로 처리해준다는 뜻.
        items_flag ^= opt2;
        items_flag ^= opt1;
    }

    cout << bitset<8>(items_flag) << endl;

    // 비트 플래그 사용 예제 (컴퓨터 그래픽스)
    // 이런 식으로, 파라미터 갯수를 줄이기 위해, bitwise OR 연산자를 사용하는 경우가 많음.
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    // 비트마스크
    // 16진수 색상코드에서 R, G, B 값을 각각 추출해서 저장하고 싶다면?
    const unsigned int red_mask = 0xFF0000; // red 부분의 비트값만 추출하기 위한 비트마스크 변수
    const unsigned int green_mask = 0x00FF00; // green 부분의 비트값만 추출하기 위한 비트마스크 변수
    const unsigned int blue_mask = 0x0000FF; // blue 부분의 비트값만 추출하기 위한 비트마스크 변수

    // 위 비트마스크 변수들을 이진수로 출력했을 때, 비트값이 1인 부분만 pixel_color 에서 추출하고 싶은 것!
    cout << std::bitset<32>(red_mask) << endl;
    cout << std::bitset<32>(green_mask) << endl;
    cout << std::bitset<32>(blue_mask) << endl;

    unsigned int pixel_color = 0xDAA520; // DA 는 red, A5 는 green, 20 은 blue 임.

    cout << std::bitset<32>(pixel_color) << endl;

    // 비트마스크로 특정 영역의 비트값만 추출할 때에는, &(bitwise AND) 연산자를 사용!
    // green 의 경우, char 타입(=8 bits) 변수로 설정하면 pixel_color 의 오른쪽에서 8번째 자릿수까지 마스킹된 비트값들만 확인 가능.
    // 반면, pixel_color 의 green 에 해당하는 비트값은 오른쪽에서 16 ~ 8번째 자릿수에 위치하고 있음.
    // 따라서, green 을 32 bits 인 int 타입으로 확장해서 16 ~ 8번째 자릿수에 마스킹된 비트값 확인!
    // 또한, 이렇게 하면 자릿수는 제대로 마스킹이 되었지만, green 의 16번째 ~ 8번째 자리에 마스킹되면 십진수 변환 시 부정확!!
    // 따라서, rightshift 연산자로 마스킹된 비트들을 8칸씩 오른쪽으로 이동시킨 것! 
    // 이제 마스킹된 자릿수가 제대로 보일 것이니, int 타입을 다시 char 타입으로 변환하고, 
    // 8칸씩 오른쪽으로 shift 하는 연산자만 그대로 사용하면 됨!
    // red 도 마찬가지 원리로 직접 비트 마스킹 해볼 것!
    unsigned char red = (pixel_color & red_mask) >> 16;
    unsigned char green = (pixel_color & green_mask) >> 8;  
    unsigned char blue = pixel_color & blue_mask;

    cout << "red " << std::bitset<8>(red) << " " << int(red) << endl;
    cout << "green " << std::bitset<8>(green) << " " << int(green) << endl;
    cout << "blue " << std::bitset<8>(blue) << " " << int(blue) << endl;

    // Quiz 1
    unsigned char option_viewed = 0x01;
    unsigned char option_edited = 0x02;
    unsigned char option_liked = 0x04;
    unsigned char option_shared = 0x08;
    unsigned char option_deleted = 0x80;

    unsigned char my_article_flags = 0;

    // code here
    cout << bitset<8>(option_viewed) << endl; // 00000001
    cout << bitset<8>(option_edited) << endl; // 00000010
    cout << bitset<8>(option_liked) << endl; // 00000100
    cout << bitset<8>(option_shared) << endl; // 00001000
    cout << bitset<8>(option_deleted) << endl; // 00000001

    // 기사를 봤을 때
    my_article_flags |= option_viewed;
    cout << "article viewed " << bitset<8>(my_article_flags) << endl;

    // 좋아요 클릭했을 때
    ClickArticle(my_article_flags, option_liked);

    // 좋아요 다시 클릭했을 때
    ClickArticle(my_article_flags, option_liked);

    // 본 기사만 삭제할 때
    if (my_article_flags & option_viewed)
    {
        my_article_flags |= option_deleted;
        cout << "article deleted " << bitset<8>(my_article_flags) << endl;
    }

    // Quiz 2
    // 아래 두 줄이 동일하게 동작하는 이유?
    // myflags &= ~(option4 | option5);
    // myflags &= ~option4 & ~option5;
    // De Morgan 법칙 때문 > bitwise NOT 연산자에 분배법칙을 적용하려면, 논리연산자를 뒤집어줘야 한다!

    return 0;
}
