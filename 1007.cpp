//1007	素数对猜想
#include<iostream>
#include<vector>
#include<cmath>//关键在于使用sqrt函数简化素数的判断

using namespace std;

bool judge(int n)
{
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)return false;
	}
	return true;
}

int main()
{
	int N;
	cin >> N;
	if (N <= 2)
	{
		cout << 0;
		return 0;
	}
	vector<int> store;
	for (int i = 2; i <= N; i++)
	{
		if (judge(i)) store.push_back(i);
	}
	vector<int> ::iterator it;
	int count = 0;
	for (it = store.begin() + 1; it != store.end(); it++)
	{
		if ((*it - *(it - 1)) == 2) count++;
	}
	cout << count;
	return 0;
}
