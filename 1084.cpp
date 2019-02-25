//1084 外观数列
#include<iostream>
#include<string>

using namespace std;

//定义计算一个数列的下一个外观数列的函数
string Next(string s)
{
	string next;
	next = "";
	char c;
	int count = 1;//记录字符出现的次数
  //从第二位开始判断，如果与前面字符相同，则增加count，若不同，则在下一个外观数列中加入数数的结果
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == s[i - 1])
			count++;
		else
		{
			next += s[i - 1];
			c = '0' + count;
			next += c;
			count = 1;
		}
	}
  //记录最后的情况
	next += s[s.length() - 1];
	c = '0' + count;
	next += c;
	return next;
}

int main()
{
	string s;
	int N;
	cin >> s >> N;
	for (int i = 1; i < N; i++)
	{
		s = Next(s);
	}
	cout << s;
	return 0;
}
