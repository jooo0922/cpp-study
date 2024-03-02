#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <numeric> // std::inner_product 사용을 위해 포함

using namespace std;

// 백만 번 더하기
void func1()
{
    long long sum = 0;
	for (unsigned i = 0; i < 1000'000; i++)
	{
		sum += 1;
	}

	cout << sum << endl;
}

// 10억 번 더하기 -> 연산량이 1000 배 더 많음
void func2()
{
	long long sum = 0;
	for (unsigned i = 0; i < 1000'000'000; i++)
	{
		sum += 1;
	}

	cout << sum << endl;
}

void run()
{
	func1();
	func2();
}

int main()
{
	// 이 호출부에서 cpu 사용량 profiling
	//run();

	// 이 부분에서 힙 메모리 profiling
	int* d = new int[10000];
	float* f = new float[100];

	delete[] d;
	delete[] f;

    return 0;
}