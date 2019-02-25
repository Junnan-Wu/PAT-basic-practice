//1086 就不告诉你
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	int a, b, mul;
	cin >> a >> b;
	mul = a*b;
	//将数字转化为字符串
	stringstream ss;
	string s;
	ss << mul;
	ss >> s;
	//注意如果计算结果最后几位是0，那么倒序后不应输入开头的0
	int flag = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (!flag && s[i] == '0')
		{
			continue;
		}
		else
		{
			flag = 1;
		}
		cout << s[i];
	}
	return 0;
}
