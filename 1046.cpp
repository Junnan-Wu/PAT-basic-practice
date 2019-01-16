//1046 划拳
#include<iostream>

using namespace std;

int main()
{
	int N;//比赛次数
	cin >> N;
	int a, b, c, d;//分别存储甲喊，甲划，乙喊，乙划
	int count1 = 0, count2 = 0;//分别存储甲输的次数与乙输的次数
	for (int i = 0; i<N; i++)
	{
		cin >> a >> b >> c >> d;
		if (a + c == b&&a + c != d)//如果加和为甲猜的数，乙罚酒
		{
			count2++;
		}
		if (a + c == d&&a + c != b)//如果加和为乙猜的数，甲罚酒
		{
			count1++;
		}
	}
	cout << count1 << ' ' << count2 << endl;
	return 0;
}
