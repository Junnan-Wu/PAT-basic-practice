//1004 成绩排名
#include<iostream>

using namespace std;

struct stu
{
	char name[11];
	char ID[11];
	int score;
};

int main()
{
	int n;
	cin >> n;
	stu *s = new stu[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].name >> s[i].ID >> s[i].score;
	}
	int max = s[0].score;
	int min = s[0].score;
	int j=0, k=0;
	for (int i = 0; i < n; i++)
	{
		if (max < s[i].score)
		{
			max = s[i].score;
			j = i;
		}
		if (min > s[i].score)
		{
			min = s[i].score;
			k = i;
		}
	}
	cout << s[j].name << ' ' << s[j].ID << endl;
	cout << s[k].name << ' ' << s[k].ID << endl;
	return 0;
}
