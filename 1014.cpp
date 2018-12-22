//1014	福尔摩斯的约会
//此题的关键在于比较的字符必须是范围内的数组，不属于范围内的字符相同是无用的
#include<iostream>
#include<string>

using namespace std;

const string code[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
char t[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B',
'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N' };

int main()
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	char week, hour;
	int minute;
	int count = 0;//用count计数，保证从前两个字符串中按顺序取相同字符
	for (int i = 0; i < a.size()||i<b.size(); i++)
	{
		if (count == 0 && a[i] == b[i] && (a[i] >= 'A'&&a[i] <= 'G'))//存放星期
		{
			week = a[i];
			count++;
			continue;
		}
		if (count == 1 && a[i] == b[i] && ((a[i] >= 'A'&&a[i] <= 'N') || (a[i] >= '0'&&a[i] <= '9')))//存放小时
		//必须保证相同的字符是t数组中的
		{
			hour = a[i];
			break;
		}
	}
	for (int i = 0; i < c.size() || i < d.size(); i++)//存放分钟
	{
		if (c[i] == d[i] &&((c[i] >= 'a'&&c[i] <= 'z') || (c[i] >= 'A'&&c[i] <= 'Z')))
		//必须保证相同的字符是英文字符
		{
			minute = i;
			break;
		}
	}
	cout << code[week - 'A'];
	for (int i = 0; i < 24; i++)
	{
		if (hour == t[i])
		{
			printf(" %02d:%02d", i,minute);
			break;
		}
	}
	return 0;
}
