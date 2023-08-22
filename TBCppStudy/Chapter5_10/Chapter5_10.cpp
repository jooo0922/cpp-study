#include <iostream>

using namespace std;

int getInt()
{
    while (true)
    {
        cout << "Enter an Integer number : ";
        int x;
        cin >> x;

        // cin.fail() 은 cin 입력으로 받은 값이 지나치게 크거나, 데이터 타입이 다르거나 등의 오류가 발생하여 입력에 실패할 경우 true 를 반환함.
        if (std::cin.fail())
        {
            // 입력 오류가 발생했을 때, cin 스트림이 오류 상태가 발생하여 이후의 입력이 무시되는데,
            // cin.clear() 는 이러한 오류 상태를 원래 상태로 복구하여 다시 입력 작업을 시도할 수 있도록 해줌.
            std::cin.clear();
            std::cin.ignore(32767, '\n'); // cin 스트림 오류 상태 복구 후, 입력 버퍼를 비움.
            cout << "Invalid number, please try again" << endl; // 경고문 출력하고 다음 while 문 반복
        }
        else
        {
            // cin 입력으로 받은 버퍼에 2개 이상의 값이 들어올 경우, 최초 1개 입력을 제외한 나머지 입력을 무시함.
            // 첫 번째 인자는 무시할 문자 개수, 두 번째 인자는 해당 문자를 만날 때까지 문자들을 무시하도록 함.
            // 즉, 여기서는 '\n'(개행문자)를 만날 때까지 최대 32767 개의 문자를 입력 버퍼 상에서 무시하고 비운다는 의미. 
            // 32767 개는 큰 의미가 있는 건 아니고, 입력버퍼에 남아있는 모든 문자를 제거하기 위해 임의의 큰 개수를 인자로 전달한 것뿐임.
            // \n 이 나올때까지 무시하도록 설정한 이유는, 콘솔에서 cin 입력 시, Enter 키를 치는데, 이 때, 입력 버퍼에 개행문자 '\n'이 들어감.
            std::cin.ignore(32767, '\n');

            return x; // cin 입력이 성공했고, 최초 1개 문자를 입력받았을 시, 해당 문자를 반환하며 while 문 탈출!
        }
    }
}

char getOperator()
{
    while (true)
    {
        cout << "Enter an operator (+, -) : "; // TODO: more operators *, / etc.
        char op;
        cin >> op;

        std::cin.ignore(32767, '\n'); // 최초의 입력값 이후의 문자들을 입력버퍼에서 무시하고 제거

        if (op == '+' || op == '-')
        {
            return op; // 제대로 된 연산자 문자를 입력받았을 때에만 문자열을 반환해서 while 문 탈출
        }
        else
        {
            // 부정확한 문자를 입력받을 경우, 콘솔에 경고문을 띄우면서 다음 while 문으로 넘어감.
            // 제대로 된 입력을 받을 때까지 while 문을 반복함.
            cout << "Invalid operator, please try again" << endl;
        }
    }
}

void printResult(int x, char op, int y)
{
    if (op == '+') cout << x + y << endl;
    else if (op == '-') cout << x - y << endl;
    else
    {
        cout << "Invalid operator" << endl;
    }
}

int main()
{
    int x = getInt();
    char op = getOperator();
    int y = getInt();

    printResult(x, op, y);

    return 0;
}
