//1013 数素数
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

bool judge(int n)
{
	if (n == 2)return true;
	if (n % 2 == 0)return false;
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n%i == 0)return false;
	}
	return true;
}

int main()
{
	int M, N;
	cin >> M >> N;
	vector<int> prime;
	int temp = 2;
	prime.push_back(temp); temp++;
	while (prime.size() <= N)//将素数存在数组中
	{
		if (judge(temp))
		{
			prime.push_back(temp);
		}
		temp += 2;
	}
	vector<int>::iterator it;
	int count = 0;//通过count计数来确保每行输出最多10个数字
	for (it = prime.begin() + M - 1; it <= prime.begin() + N - 1; it++)
	{
		if (count==0)//每行第一个数输出不要空格
		{
			cout << *it;
		}
		else//后面的数需要空格
		{
			cout << ' ' << *it;
		}
		count++;
		if (count == 10)//每十个数字换行
		{
			cout << endl;
			count = 0;
		}
	}
	return 0;
}
