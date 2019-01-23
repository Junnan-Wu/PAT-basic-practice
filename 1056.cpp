//1056 组合数的和
#include<iostream>

using namespace std;

int main()
{
	int N, temp,sum=0;//存放数字个数，临时数字，数字和
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		sum += temp*(N - 1) * 11;//每个数字会出现在十位与个位均会出现N-1遍
	}
	cout << sum << endl;
	return 0;
}
