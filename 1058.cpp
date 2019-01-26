#include<iostream>
#include<vector>

using namespace std;

struct problem
{
	int pn;//问题序号
	int score;//问题满分
	int choice;//问题选项个数
	vector<char> right;//问题正确选项
	int person=0;//答错该题的人的个数
};

int main()
{
  int N, M;//学生人数与多选题个数
  cin >> N >> M;
  problem *p = new problem[M];//存储题目信息的动态数组
  int temp;//临时存储正确选项个数
  char tep;//临时存储选项信息
  for (int i = 0; i < M; i++)
  {
    p[i].pn = i + 1;//问题序号
    cin >> p[i].score >> p[i].choice >> temp;//读入题目满分，所有选项个数，正确选项个数
    for (int j = 0; j < temp; j++)
    {
      cin >> tep;//读入所有正确选项
      p[i].right.push_back(tep);//将正确选项存入数组
    }
  }
	int c;//学生选项个数
	for (int i = 0; i < N; i++)
	{
		int sum = 0;//记录该学生得分
		for (int j = 0; j < M; j++)//判断每一个选项是否正确
		{
			int pos=0;//定位选项位置
			bool judge = true;//判断学生答题正确与否
			cin >> tep;//去掉第一个括号
			cin >> c;
			if (c !=p[j].right.size())judge = false;//！！!如果选项个数都不符合，一定是错的（防止有选项虽少，但是选的全对的情况给true）
			for (int k = 0; k < c; k++)
			{
				cin >> tep;
				if (judge && pos<p[j].right.size())//如果之前都对，且位置没有超出范围
				{
					if (p[j].right[pos] == tep) pos++;//继续判断下一个
					else judge = false;
				}
				else
				{
					judge = false;//错误
				}
			}
			cin >> tep;//去掉第二个的括号
			if (judge)//如果答对该学生得分增加
			{
				sum += p[j].score;
			}
			else//否则该题的答错人数加1
			{
				p[j].person++;
			}
		}
		cout << sum << endl;
	}
	int max = 0;
	for (int i = 0; i < M; i++)
	{
		max = max > p[i].person ? max : p[i].person;//找到错误人数最多的题
	}
	if (max==0)//如果所有题都没有人错，全队输出too simple
	{
		cout << "Too simple" << endl;
	}
	else
	{
		cout << max <<' ';//输入错的次数
		int i;
    //为了保证结尾无多余空格，需要先输出第一个不带空格的序号
		for (i = 0; i < M; i++)//输入错的编号
		{
			if (p[i].person == max)
			{
				cout << p[i++].pn;
				break;
			}
		}
		for (; i < M; i++)
		{
			if (p[i].person == max)
			{
				cout << ' '<<p[i].pn;
			}
		}
	}
	return 0;
}
