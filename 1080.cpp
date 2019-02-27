//1080 MOOC期终成绩
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int P, M, N;//做了编程作业的人，参加期中的人，参加期末的人

//默认构建结构体的时候，都没有参加任何考试，所有分数设为-1
struct score
{
	int GP=-1,GM=-1,GF=-1,G;//编程作业得分,期中得分，期末得分，总评分；
};

typedef pair<string, score> PAIR;

//定义排序规则
bool compare(PAIR a, PAIR b)
{
	if (a.second.G > b.second.G)return true;
	else if (a.second.G < b.second.G)return false;
	else
	{
		if (a.first < b.first) return true;
		else return false;
	}
}

int main()
{
	cin >> P >> M >> N;
	int number[3] = { P, M, N };
	map<string, score> m;
	string tep; int temp;
  //三轮，分别读取编程成绩，期中成绩，期末成绩
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < number[i]; j++)
		{
			cin >> tep >> temp;
			switch (i)
			{
			case 0:
				m[tep].GP = temp;
				break;
			case 1:
				m[tep].GM = temp;
				break;
			case 2:
				m[tep].GF = temp;
				break;
			default:
				break;
			}
		}
	}
  //计算每个人的总分
	for (auto it = m.begin(); it != m.end(); it++)
	{
		double GP = (*it).second.GP, GM = (*it).second.GM, GF = (*it).second.GF;
		if (GP >= 200)
		{
      //如果没来参加考试，成绩为0；
			if (GM == -1)GM = 0;
			if (GF == -1)GF = 0;
			(*it).second.G = GM > GF ? int((GM*0.4 + GF * 0.6+0.5)) : int(GF);
		}
	}
  //将map中的元素存在vector中，进行排序，其中只要输出分数及格的同学即可
	vector<PAIR> v;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if ((*it).second.G >= 60)
			v.push_back(*it);
	}
	sort(v.begin(), v.end(), compare);
  //最后输出及格的人的成绩
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first;
		for (int j = 0; j < 4; j++)
		{
			switch (j)
			{
			case 0:
				cout << ' ' << v[i].second.GP;
				break;
			case 1:
				cout << ' ' << v[i].second.GM;
				break;
			case 2:
				cout << ' ' << v[i].second.GF;
				break;
			case 3:
				cout << ' ' << v[i].second.G;
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
	return 0;
}
