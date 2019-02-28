//1092 最好吃的月饼
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, M;//N种月饼，M个城市
	cin >> N >> M;
	int tep;
	vector<int> v(N);//记录N种月饼的销量
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> tep;
			v[j] += tep;
		}
	}
	//查找最大的销量
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		max = max > v[i] ? max : v[i];
	}
	cout << max << endl;
	//如果是最大销量，输出月饼编号
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i] == max&&!flag)
		{
			cout << i + 1;
			flag = 1;
		}
		else if (v[i] == max&&flag)
		{
			cout << ' ' << i + 1;
		}
	}
	cout << endl;
	return 0;
}
