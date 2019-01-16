//1047 编程团体赛
#include<iostream>

using namespace std;

int main()
{
	int N;//读取行数
	cin >> N;
	int team, person, score;//临时存放数据
	int result[1001] = {0};
	for (int i = 0; i < N; i++)
	{
		scanf("%d-%d %d", &team, &person, &score);
		result[team] += score;//将相同队伍的人的成绩加在该队伍中
	}
	int max = 0, maxteam;
	for (int i = 0; i < 1001; i++)//找到分数最大的队伍
	{
		if (max < result[i])
		{
			max = result[i];
			maxteam = i;
		}
	}
	cout << maxteam << ' ' << max << endl;
	return 0;
}
