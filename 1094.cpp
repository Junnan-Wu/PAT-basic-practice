//1094 谷歌的招聘
#include<iostream>
#include<string>
#include<cmath>
#include<sstream>

using namespace std;

//判断一个数是否是质数
bool judge(long long n)
{
	if (n < 2)return false;//如果小于2的整数，不可能是素数
	if (n == 2)return true;//2是素数
	if (n % 2 == 0)return false;//其他2的倍数不是素数
	for (int i = 3; i <= sqrt(n); i++)
	{
		if (n%i == 0)return false;
	}
	return true;
}

int main()
{
	int L, K;//L长度的数，K位素数
	cin >> L >> K; getchar();
	string s;
	getline(cin, s);
	//定义stringstream流进行字符与数字的转化
	stringstream ss;
	long long n;
	for (int i = 0; i <= L - K; i++)
	{
		//取出从i开始K长度的字符串
		string tep = s.substr(i, K);
		ss << tep; ss >> n; ss.clear();
		if (judge(n))
		{
			cout << tep << endl;
			return 0;
		}
	}
	cout << "404" << endl;
	return 0;
}
