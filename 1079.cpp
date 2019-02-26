//1079 延迟的回文数
#include<iostream>
#include<string>

using namespace std;

string rev(string a)//逆序字符串
{
	string b = "";
	for (int i = 0; i < a.length(); i++)
	{
		b += a[a.length() - 1 - i];
	}
	return b;
}

string pla(string a,string b)//计算自身与逆序和
{
	string pl = "";
	int plus = 0;
	int p;
	for (int i = a.length()-1; i >=0; i--)
	{
		p = ((a[i] - '0') + (b[i] - '0') + plus) % 10;//相加
		plus = ((a[i] - '0') + (b[i] - '0') + plus) / 10;//进位
		char tep = '0' + p;
		pl = tep + pl;
	}
	if (plus != 0)
	{
		char tep = '0' + plus;
		pl = tep + pl;
	}
	return pl;
}

bool judge(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != a[a.length() - 1 - i])return false;
	}
	return true;
}

int main()
{
	string a, b, c;
	getline(cin, a);
	b = rev(a);
	//竟然有三个测试点都是这么坑……如果输入的数是回文数，直接输出结果就行了
	if (judge(a))
	{
		cout << a << " is a palindromic number." << endl;
		return 0;
	}
	//不是回文数，就进行计算
	for (int i = 0; i < 10; i++)
	{
		c = pla(a, b);
		cout << a << " + " << b << " = " << c << endl;
		if (judge(c))
		{
			cout << c << " is a palindromic number." << endl;
			return 0;
		}
		a = c;
		b = rev(a);
	}
	cout << "Not found in 10 iterations." << endl;
	return 0;
}
