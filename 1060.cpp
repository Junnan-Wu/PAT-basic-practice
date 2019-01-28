//1060 爱丁顿数
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N;//骑车天数
	cin >> N;
	vector<int> s(N);//存储路程
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}
	sort(s.begin(), s.end());//对其进行排序
	int E = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] > E + 1)E++;
		else break;
	}
	cout << E;
	return 0;
}
