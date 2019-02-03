//1064 朋友数
#include<iostream>
#include<string>

using namespace std;

int trans(string s)//计算一个数的朋友证明
{
	int n = 0;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		n += s[i] - '0';
	}
	return n;
}

int main()
{
	int N,m = 0;//记录整数个数与朋友证明的个数
	int n[37] = {0};//存储朋友证明的数组，由于最大数9999的朋友证明为36，因此使用长度为37的数组即可
	string temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (n[trans(temp)] == 0)//如果输入的朋友证明不存在，将其设为1；
		{
			n[trans(temp)] = 1;
			m++;
		}
	}
	cout << m << endl;
	int flag = 0;
	for (int i = 0; i < 37; i++)//输出存在的朋友证明
	{
		if (n[i] && !flag)//如果第一次输出将flag设为1之后不再输出
		{
			cout << i;
			flag = 1;
		}
		else if (n[i])
		{
			cout << ' ' << i;
		}
	}
	return 0;
}
