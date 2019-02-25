//1091 N-自守数
#include<iostream>

using namespace std;

//计算n的自守数
int own(int n)
{
	int mod;
	if (n < 10)
		mod = 10;
	else if (n < 100)
		mod = 100;
	else
		mod = 1000;
	for (int i = 1; i < 10; i++)
	{
		if (n*n*i%mod == n)
			return i;
	}
	return 0;//没有自守数返回0
}

int main()
{
	int M;//M个待检验数字
	cin >> M;
	int tep,res;//储存待检测的数字与自守数的计算结果
	for (int i = 0; i < M; i++)
	{
		cin >> tep;
		res = own(tep);
		if (res != 0)
			cout << res << ' ' << res*tep*tep << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
