#include<iostream>
#include<string>

using namespace std;

int judge(char c)//判断字符是否合法
{
	if (c >= '0'&&c <= '9')return 1;
	else if ((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')) return 2;
	else if (c == '.')return 3;
	else return 0;
}

int res(string s)//判断密码属于什么类型
{
	int flag1 = 0, flag2 = 0;//记录数字与字母是否出现
	if (s.length() < 6)return 1;//长度太短
	for (int i = 0; i < s.length(); i++)
	{
		if (judge(s[i]) == 1)
		{
			flag1 = 1;
			continue;
		}
		else if (judge(s[i]) == 2)
		{
			flag2 = 1;
			continue;
		}
		else if (judge(s[i]) == 3)
		{
			continue;
		}
		else
			return 2;//存在不合法字符
	}
	if (!flag1&&flag2)return 3;//只有字母没有数字;
	if (flag1&&!flag2)return 4;//只有数字没有字母;
	if (!flag1&&!flag2) return 5;//只有.
	return 0;//合法的密码；
}

int main()
{
	int N;//记录N个字符串
	cin >> N; getchar();
	string temp;//存储临时密码
	int f;//记录判断结果
	for (int i = 0; i < N; i++)
	{
		getline(cin, temp);
		f = res(temp);
		if (!f)
			cout << "Your password is wan mei." << endl;
		else if (f == 1)
			cout << "Your password is tai duan le." << endl;
		else if (f == 2)
			cout << "Your password is tai luan le." << endl;
		else if (f == 3)
			cout << "Your password needs shu zi." << endl;
		else if (f == 4)
			cout << "Your password needs zi mu." << endl;
		else
			continue;
	}
	return 0;
}
