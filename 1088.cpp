//1088 三人行
#include<iostream>
#include<cmath>

using namespace std;

void print(double a, double b)//注意由于丙的能力不一定是整数，这里需要使用double类型进行判断
{
	if (a > b)
		cout << "Cong";
	else if (a == b)
		cout << "Ping";
	else
		cout << "Gai";
}

int main()
{
	int M, X, Y;//我的能力，倍数关系X，Y
	cin >> M >> X >> Y;
	int n1 = 9, n2 = 9;//设甲能力为10*n1+n2,乙则为10*n2+n1,丙为9*abs(n1-n2)/X,同时丙为(10*n2+n1)/Y
	double c1, c2;//丙的能力，两种计算方法
	int flag = 0;
	while (n1 || n2)
	{
		c1 = 9 * abs(n1 - n2) / (X + 0.0); c2 = (10 * n2 + n1) / (Y + 0.0);
		if (c1 == c2)break;
		else
		{
			n2--;
		}
		if (n2 == -1)
		{
			n1--;
			n2 = 9;
		}
		if (n1 == 0 && n2 == 0)//所有二位数都找遍了
		{
			flag = 1;
		}
	}
	if (flag)
		cout << "No Solution" << endl;
	else
	{
		int a = 10 * n1 + n2, b = 10 * n2 + n1;
		cout << a << ' ';
		print(a, M); cout << ' ';
		print(b, M); cout << ' ';
		print(c1, M); cout << endl;
	}
	return 0;
}
