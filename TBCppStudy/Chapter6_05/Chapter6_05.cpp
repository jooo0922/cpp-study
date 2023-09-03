#include <iostream>

using namespace std;

int main()
{
    const int num_rows = 3;
    const int num_columns = 5;

	// 이중 반복문으로 행렬 출력하기
	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
		{
			cout << "[" << row << "]" << "[" << col << "]" << "\t"; // "\t" 는 탭 문자를 의미함.
		}

		cout << endl;
	}

	cout << endl;

	return 0;
}