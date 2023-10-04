#include <iostream>

using namespace std;

int min(int x, int y)
{
    return x > y ? y : x;
}

int main()
{
    cout << min(5, 6) << endl;
    cout << min(3, 2) << endl;

    return 0;
}