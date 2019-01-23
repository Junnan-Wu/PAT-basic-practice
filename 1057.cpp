//1057 数零壹
#include<iostream>
#include<string>

using namespace std;

struct result//统计最后一个数的二进制数的零一的个数的结构体
{
	int zero=0;
	int one=0;
};

result cal(int n)//统计n的二进制数的零一个数
{
	result a;
	while (n)
	{
		if (n % 2 == 1)a.one++;
		else a.zero++;
		n /= 2;
	}
	return a;
}

int main()
{
	string s;//存储字符串
	getline(cin, s);
	int sum=0;//记录总和
	for (unsigned i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a'&&s[i] <= 'z')sum += s[i] - 'a'+1;
		else if (s[i] >= 'A'&&s[i] <= 'Z')sum += s[i] - 'A'+1;
		else continue;
	}
	result a = cal(sum);
	cout << a.zero << ' ' << a.one << endl;
	return 0;
}
