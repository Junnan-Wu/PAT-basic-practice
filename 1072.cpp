//1072 开学寄语
#include<iostream>
#include<set>
#include<string>
#include<vector>

using namespace std;

struct stu
{
	string name;//储存学生人数
	vector<int> items;//储存该学生的物品
};

int main()
{
	int N, M;//储存学生人数与违规物品的个数
	cin >> N >> M;
	set<int> item;//储存违规物品的编号；
	int tep;
	for (int i = 0; i < M; i++)//储存物品编号
	{
		cin >> tep;
		item.insert(tep);
	}
	vector<stu> v(N);//储存学生的信息
	for (int i = 0; i < N; i++)
	{
		int L;//储存学生的物品个数
		cin >> v[i].name >> L;
		v[i].items.resize(L);
		for (int j = 0; j < L; j++)
		{
			cin >> v[i].items[j];
		}
	}
	int count1 = 0, count2 = 0;//记录违规学生人数，违规物品个数
	for (int i = 0; i < N; i++)
	{
		int  flag = 0;
		for (int j = 0; j < v[i].items.size(); j++)
		{
			if (item.find(v[i].items[j]) != item.end()&&!flag)//如果找到并是第一个
			{
				cout << v[i].name;//输出名字
				printf(": %04d", v[i].items[j]);
				flag = 1; count1++;//违规人数加1
				count2++;//违规物品数加1
				continue;
			}
			if (item.find(v[i].items[j]) != item.end() && flag)//找到剩余的违规物品
			{
				printf(" %04d", v[i].items[j]);
				count2++;//违规物品数加1
			}
		}
		if(flag)cout << endl;//该学生违规输出一个换行
	}
	cout << count1 << ' ' << count2 << endl;
	return 0;
}
