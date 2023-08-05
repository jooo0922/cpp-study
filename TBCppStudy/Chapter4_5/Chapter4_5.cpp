#include <iostream>
#include <typeinfo>

int main()
{
    using namespace std;

    cout << typeid(4.0).name() << endl;

    return 0;
}
