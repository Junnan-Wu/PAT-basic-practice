//1085 PAT单位排行
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct school
{
	//分数与学校人数
	double score;
	int pn;
};

typedef pair<string, school> PAIR;//定义数据类型PAIR

//定义排序方法
bool compare(const PAIR &a, const PAIR &b)
{
  //首先根据分数进行排序
	if (int(a.second.score) >int( b.second.score))return true;
	else if (int(a.second.score) < int(b.second.score))return false;
	else
	{
    //其次根据人数进行排序
		if (a.second.pn < b.second.pn)return true;
		else if (a.second.pn>b.second.pn)return false;
		else
		{
      //最后根据学校名称进行排序
			if (a.first < b.first)return true;
			else return false;
		}
	}
}

int main()
{
	int N;//考生人数；
	cin >> N;
	string s, sn;//准考证号与学校名称
	int grade;//成绩；
	map<string, school> m;//储存学校信息stl
	for (int i = 0; i < N; i++)
	{
		cin >> s >> grade >> sn;
		for (int j = 0; j < sn.length(); j++)
		{
			if (sn[j] >= 'A'&&sn[j] <= 'Z')sn[j] = sn[j] - 'A' + 'a';
		}
		if (s[0] == 'B')
			m[sn].score += grade / 1.5;
		else if (s[0] == 'A')
			m[sn].score += grade;
		else
			m[sn].score += grade*1.5;
		m[sn].pn++;
	}
	//由于map中没法对value与key同时进行排序，因此将map中的元素拎出来，放在vector中，然后使用sort函数对其进行排序，效率很高
	vector<PAIR> v(m.begin(), m.end());
	sort(v.begin(), v.end(), compare);
	cout << v.size() << endl;
	//先输出第一名
	int rank = 1;
	cout << rank << ' ' << v[0].first << ' ' << int(v[0].second.score) << ' ' << v[0].second.pn << endl;
	for (int i = 1; i < v.size(); i++)
	{
		//如果后一名的分数与前一名不同，该名词则为序列号+1的名次
		if (int(v[i].second.score) != int(v[i - 1].second.score))
			rank = i + 1;
		cout << rank << ' ' << v[i].first << ' ' << int(v[i].second.score) << ' ' << v[i].second.pn << endl;
	}
	return 0;
}
