//1078 字符串压缩与解压
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

string compress(string s)//压缩
{
	string com = "",tep;
	stringstream ss;
	int count = 1;
  //对比前一个字符与后一个字符是否相同，相同计数加1，不相同的话证明变了一个字符，这样前面所有字符的个数变为一个字符串，与前面字符组合为：数字+字符的形式。要注意如果计数为1，证明这是一个单独的字符，前面不需要1
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == s[i - 1])
			count++;
		else
		{
			if (count == 1)
			{
				com += s[i-1];
				continue;
			}
      //不是1的时候，使用stringstream将数字转化为字符
			ss << count;
			ss >> tep;
			com += tep;//加数字
			com += s[i-1];
			ss.clear();
			count = 1;
		}
	}
  //还要判断最后的情况
	if (count == 1)
	{
		com += s[s.length() - 1];
		return com;
	}
	ss << count;
	ss >> tep;
	com += tep;
	com += s[s.length() - 1];
	return com;
}

string decompress(string s)
{
	string dec = "";
	stringstream ss;
	int f=0;//记录数字的首与位数
	if (!(s[0] >= '0'&&s[0] <= '9'))//如果首位不是数字
	{
		dec += s[0];
	}
	//从第二位开始判断
	for (int i = 1; i < s.length(); i++)
	{
		if (!(s[i] >= '0'&&s[i] <= '9'))//找到直到不是数字的时候
		{
			if (!(s[i - 1] >= '0'&&s[i - 1] <= '9'))//如果前一位不是数字，证明这个是单独的字母
			{
				dec += s[i];
				f = i + 1;//数字的首位暂定为下一位
				continue;
			}
			else//如果前一位是数字，证明是一个重复的字母
			{
				string plus=s.substr(f, i-f);//将数字存起来,并将字符串转化为数字,此函数是返回s的子串，从f开始，的i-f个数的字符
				ss << plus;
				int p;
				ss >> p;
				ss.clear();
				string plu(p, s[i]);//构造长度为p字符为s[i]的字符
				dec += plu;
				//数字的首位暂定为下一位
				f = i + 1;
			}
		}
	}
	return dec;
}

int main()
{
	char c;
	string s;
	cin >> c; getchar();
	getline(cin, s);
	if (c == 'C')
	{
		cout << compress(s);
	}
	else
	{
		cout << decompress(s);
	}
	return 0;
}
