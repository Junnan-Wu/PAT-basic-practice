//1089 狼人杀-简单版
#include<iostream>
#include<vector>

using namespace std;

struct people
{
	char c;//记录此人指认的人是好人还是坏人；
	int p;//记录此人指认的人的编号；
	bool judge = true;//记录此人是好人还是坏人，默认好人
};

bool compare(people a, people b)//判断a指认b这句话是否是谎话
{
	//如果a指认b是好人，b确实是好人
	if (a.c == '+'&&b.judge)return true;
	//如果a指认b是坏人，b确实是坏人
	if (a.c == '-'&&!b.judge)return true;
	return false;//此人说谎
}

int main()
{
	int N;//总共N个玩家
	cin >> N; getchar();
	vector<people> v(N + 1);//存储玩家信息；
	for (int i = 1; i <= N; i++)
	{
		v[i].c = getchar();
		cin >> v[i].p; getchar();
	}
	for (int i = 1; i <= N - 1; i++)
	{
		v[i].judge = false;//假设i为狼
		for (int j = i + 1; j <= N; j++)
		{
			v[j].judge = false;//假设j为狼人
			int flag1 = 0, flag2 = 0;
			//首先判断是不是狼中只有一个人说谎
			if (compare(v[i], v[v[i].p]))flag1 = 1;//说实话
			if (compare(v[j], v[v[j].p]))flag2 = 1;//说实话
			if ((flag1 == 1 && flag2 == 1) || (flag1 == 0 && flag2 == 0))
			{
				//如果两个狼人都是实话或者都是假话不符合题目；
				v[j].judge = true;
				continue;
			}
			//进行到这一步已经保证了两个狼人有一人说真话，一人说假话
			//后进行遍历寻找说谎的人的个数，必须保证有且仅有两人说谎，并且一人是狼，一人是人
			int cnt = 0;
			for (int k = 1; k <= N; k++)
			{
				//记录说谎的人的个数
				if (!compare(v[k], v[v[k].p]))cnt++;
				if (cnt == 3)break;
			}
			if (cnt == 2)//如果恰好两人说谎，满足题意输出
			{
				cout << i << ' ' << j << endl;
				return 0;
			}
			v[j].judge = true;
		}
		v[i].judge = true;//将i重新设为好人
	}
	//前面都没有输出结果过
	cout << "No Solution" << endl;
	return 0;
}
