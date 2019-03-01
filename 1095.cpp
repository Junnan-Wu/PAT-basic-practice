//1095 解码PAT准考证
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct student
{
	string ID;//记录准考证
	string rank;//记录等级
	string room;//记录考场
	string date;//记录日期
	string id;//考生编号
	int score;//考生成绩
};

typedef pair<string, int> PAIR;

bool compare1(const PAIR &a, const PAIR &b)//PAIR的first为准考证，second为分数
{
	return a.second != b.second ? a.second > b.second:a.first < b.first;
	//按照分数递减顺序，对于分数并列的考生，按其准考证号的字典序递增输出
}

bool compare2(const PAIR &a, const PAIR &b)//PAIR的fisrt为考场编号，second为人数
{
	return a.second != b.second ? a.second > b.second : a.first < b.first;
	//按人数非递增顺序,若人数并列则按考场编号递增顺序
}

int N, M;//记录考生人数与要统计的个数
vector<student> v;//储存学生信息

void case1(string s)
{
	unordered_map<string, int> m;
	for (int i = 0; i < N; i++)
	{
		if (v[i].rank == s)
			m[v[i].ID] = v[i].score;
	}
	if (m.empty())
	{
		cout << "NA" << endl;
		return;
	}
	vector<PAIR> vv;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		vv.push_back(*it);
	}
	sort(vv.begin(), vv.end(), compare1);
	for (int i = 0; i < vv.size(); i++)
	{
		printf("%s %d\n", vv[i].first.c_str(), vv[i].second);//注意这里必须用printf而不是cout，不然后两个测试点不能通过
		//cout << vv[i].first << ' ' << vv[i].second << endl;
	}
	return;
}

void case2(string s)
{
	int peo = 0, sum = 0;
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i].room == s)
		{
			flag = 1;
			peo++;
			sum += v[i].score;
		}
	}
	if (!flag)
	{
		cout << "NA" << endl;
		return;
	}
	cout << peo << ' ' << sum << endl;
	return;
}

void case3(string s)
{
	unordered_map<string, int> m;//考场编号对应人数
	for (int i = 0; i < N; i++)
	{
		if (v[i].date == s)
			m[v[i].room]++;
	}
	if (m.empty())
	{
		cout << "NA" << endl;
		return;
	}
	vector<PAIR> vv;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		vv.push_back(*it);
	}
	sort(vv.begin(), vv.end(), compare2);
	for (int i = 0; i < vv.size(); i++)
	{
		printf("%s %d\n", vv[i].first.c_str(), vv[i].second);
		//cout << vv[i].first << ' ' << vv[i].second << endl;
	}
	return;
}

int main()
{
	cin >> N >> M;
	v.resize(N);//对全局数组进行大小规定
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].ID >> v[i].score;
		v[i].rank = v[i].ID[0];
		v[i].room = v[i].ID.substr(1, 3);
		v[i].date = v[i].ID.substr(4, 6);
		v[i].id = v[i].ID.substr(10, 3);
	}
  //flag用于判断类别，type规定要求
	int flag;
	string type;
	for (int i = 0; i < M; i++)
	{
		cin >> flag >> type;
		switch (flag)
		{
		case 1:
			cout << "Case " << i + 1 << ": " << flag << ' ' << type << endl;
			case1(type);
			break;
		case 2:
			cout << "Case " << i + 1 << ": " << flag << ' ' << type << endl;
			case2(type);
			break;
		case 3:
			cout << "Case " << i + 1 << ": " << flag << ' ' << type << endl;
			case3(type);
			break;
		default:
			cout << "Case " << i + 1 << ": " << flag << ' ' << type << endl;
			cout << "NA" << endl;
			break;
		}
	}
	return 0;
}
