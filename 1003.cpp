//1003 我要通过！
#include<iostream>
#include<string>

using namespace std;

int judge(string s)
{
	int len = s.length();
	int p = s.find("P");
	int t = s.find("T");
	if (t-p<2)return 1;
	for (int i = p + 1; i < t; i++)
	{
		if (s[i] != 'A')return 2;
	}
	if (p*(t-p-1) != len - t - 1)return 3;
	for (int i = 0; i < p; i++)
	{
		int j = len - 1 - i;
		if (s[i] != 'A')return 4;
	}
	for (int i = t+1; i < len; i++)
	{
		if (s[i] != 'A')return 5;
	}
	return 0;
}

int main()
{
	int line;
	cin >> line;
	string *s = new string[line];
	for (int i = 0; i < line; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < line; i++)
	{
		if (judge(s[i]) == 0)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
