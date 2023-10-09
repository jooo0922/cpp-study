#include <iostream>
#include <vector>

using namespace std;

void printStack(const std::vector<int>& stack)
{
    for (auto& e : stack)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    // int* v_ptr = new int[3]{ 1, 2, 3 }; // std::vector 는 내부적으로 이렇게 동적 배열 할당과 유사하게 동작함.
    std::vector<int> v{ 1, 2, 3 };

    // reserve() 는 vector 의 capacity(실제 최대 메모리 용량)을 미리 '예약'해서 잡아두겠다는 뜻.
    // 즉, vector 의 capacity 크기를 변경해주는 함수임. 
    // 그런데, resize(10) 으로 했을 땐 나머지 7개 요소들이 0으로 초기화 됬었는데,
    // reserve(1024) 는 왜 나머지 요소들이 초기화되지 않고 기존에 할당된 1, 2, 3 만 출력될까?
    /*
        이 또한, vector 내에서 
        new, delete 키워드 사용을 줄이기 위한 설계 방식 중 하나인데,

        reserve() 로 vector 의 capacity 를 여유롭게 늘려놓으면,
        나중에 vector 에 요소를 추가할 때,
        별도로 new 키워드를 사용해서 메모리를 동적할당을 안해도 됨.

        왜냐하면, 이미 여유롭게 늘려놓은 메모리 공간이 많으니까!
        그냥 여유공간에 값만 추가로 써놓으면 되는 것이지!

        -> 이를 통해 vector 에 요소를 더 빠른 속도로 추가할 수 있음! 
    */
    v.reserve(1024);

    // 현재 초기화된 vector 의 size 는 3인데, 이를 resize 해보자!
    // 이렇게 하면, 1, 2, 3 을 제외한 나머지 7개의 요소가 0으로 초기화됨.
    // 또한, vector 의 size, capacity 값도 10으로 변경됨.
    //v.resize(10);

    // 현재 초기화된 vector 의 size 보다 더 적게 resize 한다면?
    // 이렇게 하면, 마지막 요소 3을 제외한 1, 2 만 남게 됨.
    // 또한, vector 의 size 는 2로 변경됨.
    // 그런데, capacity 는 3으로 그대로 유지됨. 왜 이런걸까?
    // 즉, 최대 용량은 그냥 3으로 유지하고, 출력할 때의 size 는 2개만 사용하는 것이지!
    // vector 가 이렇게 동작되도록 설계된 이유는 하단에 정리해놓음.
    v.resize(2);

    // vector 에는 size, capacity 라는 개념이 있다!
    /*
        size, capacity

        vector 는 내부적으로 동적 할당을 위해
        new, delete 를 반복적으로 사용하고 있는데,

        이렇게 힙 메모리에 할당하고 제거하기 위해
        new, delete 를 사용하는 것은, 스택 메모리에 비해 상대적으로
        느리고 무거운 작업이라고 함.

        그래서, std::vector 를 잘 사용한다는 것은,
        내부적으로 new, delete 를 덜 사용하는 방식으로
        vector 를 사용한다는 것을 의미함!

        이때, vector 내부에서는 실제로는 capacity 개수 만큼 메모리를 갖고 있는데,
        그런데 그 중에서 몇 개만 사용하는지에 대한 정보가 size 라고 보면 됨.
    */
    // for-each 문에서 각 요소가 들어갈 변수를 참조변수로 선언해서 사용
    for (auto &e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    // vector 에서 실제 사용중인 개수(size) 와 
    // 현재 메모리에 갖고 있는 최대 개수(capacity) 출력
    // for-each 문에서는 size 개수만큼 돈다고 보면 됨.
    cout << v.size() << " " << v.capacity() << endl;

    // vector 를 2로 resize 했을 때, 출력되지 않은 요소 3을 어떻게 접근할 수 있을까?
    //cout << v[2] << endl; // 런타임 에러
    //cout << v.at(2) << endl; // 디버그 에러

    // 이렇게 하니까 3을 출력하네!!
    // 아! 결국 resize(2) 로 하더라도, vector 는 출력되지 않은 요소 3을 갖고 있지만, 없는 척 한거구나!
    // 그래서, vector 가 갖고있는 data의 주소값을 복사해와서 억지로 가져오면 읽어볼 수 있구나!
    /*
        이를 통해 알 수 있는 것!

        vector 는 왜 3을 갖고 있었으면서 없는 척 했을까?

        사실, 메모리 사이즈가 resize 되었다면,
        실제로 기존 메모리를 new 키워드로 복사한 뒤, 3을 제거하고,
        기존 메모리를 delete 로 제거하면 깔끔하지 않나 싶지만,

        앞서 말했던 것처럼,
        new 와 delete 는 자주 사용하면 안좋은 무거운 연산이라고 했지?

        그래서, 이런 메모리 동적 할당 및 반납 행위를 최소화하기 위해,
        실제로는 vector 가 그냥 3까지 갖고 있어서 실제 메모리(capacity)는 3으로 유지하지만,
        vector 를 읽어들일 때의 메모리 크기(size)는 2로 변경해서

        마치 마지막 요소 3에 대한 메모리가 '반납된 것처럼' 보이도록 설계된 것임!
    */
    int* ptr = v.data();
    cout << ptr[2] << endl; // 3


    /* vector 를 스택처럼 사용하기 */
    /*
        함수를 재귀호출 하는 등의 상황에서는
        stack overflow(스택 메모리가 가득 차는 현상)이 발생하기 쉬운데,

        그럼에도 불구하고 재귀 알고리즘을 반드시 사용해야 한다면,
        vector 를 하나의 스택 메모리로 사용하는 방법이 존재함
    */
    std::vector<int> stack;

    /*
        그런데 왜 하필 스택을 vector 로 구현하느냐?

        vector 에서 reserve() 로 미리
        capacity 메모리 공간을 여유롭게 늘려놓으면,

        push_back() 으로 스택에 어떤 노드를 추가할 때,
        다시 new 키워드를 사용해서 동적으로 메모리를 재할당할 필요가 없으니까

        push 동작을 더 빠르게 할 수 있다는 이점 때문에
        vector 를 활용하는 것임!
    */
    // stack.reserve(1024);

    // vector 에서 스택처럼 push, pop 하는 동작을 구현하려면 아래와 같이 사용하면 됨.
    stack.push_back(3);
    printStack(stack);

    stack.push_back(5);
    printStack(stack);

    stack.push_back(7);
    printStack(stack);

    stack.pop_back(); // 후입선출 (가장 마지막에 push 된 것부터 제거하기 시작)
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    return 0;
}