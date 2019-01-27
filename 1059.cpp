//1059 C语言竞赛
#include<iostream>
#include<cmath>

using namespace std;

bool judge(int n)//判断是否是素数
{
	if (n<=1)return false;//0,1负数都不是素数
	if (n == 2)return true;//2是素数
	if (n % 2 == 0)return false;//偶数不是素数
	int s = int(sqrt(n)) + 1;
	for (int i = 3; i < s; i += 2)
	{
		if (n%i == 0)return false;
	}
	return true;//前面都不能整除，是素数
}

int main()
{
	int N;//学生人数
	cin >> N;
	int rank[10000] = {0};//用于存储每个人的排名
	int temp;//存储每个人的ID
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		if (i == 1)
		{
			rank[temp] = 1;
			continue;//第一名神秘大奖记为1
		}
		if (judge(i))//如果排名是素数，记为2
		{
			rank[temp] = 2;
		}
		else//其他人记为2
		{
			rank[temp] = 3;
		}
	}
	int K;//查询人数
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> temp;
		if (rank[temp] == 1)
		{
			printf("%04d: Mystery Award\n", temp);
			rank[temp] = 4;//查询过将其表示为4
		}
		else if (rank[temp] == 2)
		{
			printf("%04d: Minion\n", temp);
			rank[temp] = 4;//查询过将其表示为4
		}
		else if (rank[temp] == 3)
		{
			printf("%04d: Chocolate\n", temp);
			rank[temp] = 4;//查询过将其表示为4
		}
		else if (rank[temp] == 4)
		{
			printf("%04d: Checked\n", temp);
		}
		else
		{
			printf("%04d: Are you kidding?\n", temp);
		}
	}
	return 0;
}
