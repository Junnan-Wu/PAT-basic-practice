//1069 微博转发抽奖
#include<iostream>
#include<set>
#include<vector>
#include<string>

using namespace std;


int main()
{
	int M, N, S;//转发量，中奖间隔，第一个中奖人的序号
	cin >> M >> N >> S; getchar();//读取第一行，并读取行末换行符
	vector<string> v(M);//储存转发的人
	set<string> win;//储存中奖的人
	for (int i = 0; i < M; i++)
	{
		getline(cin, v[i]);//按行读取转发人数
	}
	if (M < S)
	{
		cout << "Keep going..." << endl;
		return 0;
	}
	for (int i = S - 1; i < M; i+=N)
	{
		if (win.find(v[i]) == win.end())//没有中过奖
		{
			cout << v[i] << endl;//输出
			win.insert(v[i]);//插入
		}
		else//如果重复中奖，依次顺延
		{
			i++;//先顺延一次
			while (i < M)//如果顺延的那次还在范围内，查找
			{
				if (win.find(v[i]) == win.end())//如果没有中过奖，则输出，推出循环
				{
					cout << v[i] << endl;
					win.insert(v[i]);
					break;
				}
				i++;
			};
		}
	}
	return 0;
}
