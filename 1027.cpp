//1027 打印沙漏
#include<iostream>

using namespace std;

int count(int n)//计算n个字符可组成的最大的沙漏的行数
{
	int count = 1;
	while (1)
	{
		if (n >= 2 * count*count - 1)count++;
		else return count - 1;
	}
}

int main()
{
	int n;
	char s;
	cin >> n >> s;
	int row = count(n);
	int length = 2 * row - 1;

	for (int i = row; i >= 1; i--)//先输出上半部分的沙漏
	{
		for (int j = 0; j < (length - (2 * i - 1)) / 2; j++)//每行先输出若干空格保居中
		{
			cout << ' ';
		}
		for (int j = 0; j < 2 * i - 1; j++)//每行输出2*i-1个字符
		{
			cout << s;
		}
		//for (int j = 0; j < (length - (2 * i - 1)) / 2; j++)//注意不需要输出多余的空格！
		//{
		//	cout << ' ';
		//}
		cout << endl;
	}
	for (int i = 2; i <= row; i++)//再输出下半部分的沙漏，同上
	{
		for (int j = 0; j < (length - (2 * i - 1)) / 2; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < 2 * i - 1; j++)
		{
			cout << s;
		}
		//for (int j = 0; j < (length - (2 * i - 1)) / 2; j++)
		//{
		//	cout << ' ';
		//}
		cout << endl;
	}
	cout << n - (2 * row*row - 1) << endl;//最后输出剩余的字符的个数
	return 0;
}
