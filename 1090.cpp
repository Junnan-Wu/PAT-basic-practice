//1090 危险品装箱
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N, M;//成对不相容的物品的对数，集装箱个数
	cin >> N >> M;
	map<int, set<int>> m;//储存m物品的不相容物品；
	int a, b;//临时记录不相容物品编号
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		m[a].insert(b);
		m[b].insert(a);
	}
	for (int i = 0; i < M; i++)
	{
		int n;//记录每一个集装箱的物品数;
		cin >> n;
		vector<int> v(n);//存储每个物品的编号
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &v[j]);
		}
		//判断有没有不相容物品
		bool judge = true;
		for (int j = 0; j < n - 1; j++)
		{
			//如果该物品没有不相容的物品
			if (m[v[j]].size() == 0)
			{
				//直接跳过本次判断
				continue;
			}
			//如果有不相容的物品，在后面查找
			for (int k = j + 1; k < n; k++)
			{
        //后面物品在该物品的不相容物品集合中进行查找，如果找到，这个集装箱就是不合法的
				if (find(m[v[j]].begin(), m[v[j]].end(), v[k]) != m[v[j]].end())//如果找到了不相容的
				{
					judge = false;
					break;
				}
			}
			if (!judge)break;
		}
		if (judge)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
