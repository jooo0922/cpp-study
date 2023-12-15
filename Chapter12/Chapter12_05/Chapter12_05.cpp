#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    int x, y;
    cin >> x >> y;

    int op;
    cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
    cin >> op;

    // 정적 바인딩 (static binding 또는 early binding)
    int result;

    switch (op)
    {
    case 0: result = add(x, y); break;
    case 1: result = subtract(x, y); break;
    case 2: result = multiply(x, y); break;
    }

    cout << result << endl;

    return 0;
}