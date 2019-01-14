//1044 火星数字
#include<iostream>
#include<string>

using namespace std;

string bit[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string ten[13] = { "\0", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void print(int n)//如果读入的是数字，将其转化为13进制数以后输出火星文
{
	if (n == 0)
	{
		cout << "tret" << endl;
		return;
	}
	int t = n / 13;
	int b = n % 13;
	if (b == 0)
	{
		cout << ten[t] << endl;
		return;
	}
	if (t == 0)
	{
		cout << bit[b] << endl;
		return;
	}
	cout << ten[t] << ' ' << bit[b] << endl;
	return;
}//如果输入的是数字

void print(string a)//如果只输入了一个字符，且是火星文
{
	for (int i = 0; i < 13; i++)
	{
		if (a == bit[i])
		{
			cout << i << endl;
			return;
		}
		if (a == ten[i])
		{
			cout << 13 * i << endl;
			return;
		}
	}
	cout << "出错！" << endl;
	return;
}

void print(string a, string b)//如果读入两个字符串，证明是火星文
{
	int i, j;
	for (i = 0; i < 13; i++)
	{
		if (ten[i] == a)
		{
			break;
		}
	}
	for (j = 0; j < 13; j++)
	{
		if (bit[j] == b)
		{
			break;
		}
	}
	cout << i * 13 + j << endl;
	return;
}

int main()
{
	int N;
	cin >> N;
	string temp1, temp2;
	for (int i = 0; i < N; i++)
	{
		cin >> temp1;
		if (cin.peek() != '\n')//如果读了两个字符
		{
			cin >> temp2;
			print(temp1, temp2);
		}
		else//如果读了一个字符
		{
			if (temp1[0] >= '0'&&temp1[0] <= '9')//如果读入的是数字，将其转化为整型数
			{
				int number = stoi(temp1);
				print(number);
			}
			else//如果读入的是单词，将其直接输出
			{
				print(temp1);
			}
		}
	}
	return 0;
}
